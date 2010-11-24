/*
 * popen, pclose functions for MS DOS
 *
 * (C) Copyright 1988, 1990 Diomidis Spinellis. All rights reserved. 
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by Diomidis Spinellis.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <process.h>

/*
 * Possible actions on an popened file
 */
enum action {
	delete, 			/* Used for "r". Delete the tmp file */
	execute				/* Used for "w". Execute the command. */
};

/*
 * Linked list of things to do at the end of the program execution.
 */
static struct todo {
	FILE *f;			/* File we are working on (to fclose) */
	const char *name;		/* Name of the file (to unlink) */
	const char *command;		/* Command to execute */
	enum action what;		/* What to do (execute or delete) */
	struct todo *next;		/* Next structure */
} *todolist;

/*
 * Add a file f running the command command on file name to the list
 * of actions to be done at the end.  The action is specified in what.
 * Return -1 on failure, 0 if ok.
 */
static int
add(FILE *f, const char *command, const char *name, enum action what)
{
	struct todo    *p;

	if ((p = (struct todo *) malloc(sizeof(struct todo))) == NULL)
		return -1;
	p->f = f;
	p->command = command;
	p->name = name;
	p->what = what;
	p->next = todolist;
	todolist = p;
	return 0;
}

FILE *
popen(const char *command, const char *t)
{
	char buff[256];
	char *name;
	FILE *f;

	if ((name = tmpnam(getenv(NULL))) == NULL)
		return NULL;

	switch (*t) {
	case 'r':
		sprintf(buff, "%s >%s", command, name);
		if (system(buff) || (f = fopen(name, "r")) == NULL) {
			free(name);
			return NULL;
		}
		if (add(f, command, name, delete)) {
			(void)fclose(f);
			(void)unlink(name);
			free(name);
			return NULL;
		}
		return f;
	case 'w':
		if ((f = fopen(name, "w")) == NULL) {
			free(name);
			return NULL;
		}
		if (add(f, command, name, execute)) {
			(void)fclose(f);
			(void)unlink(name);
			free(name);
			return NULL;
		}
		return f;
	default:
		free(name);
		return NULL;
	}
}

int
pclose(FILE *f)
{
	struct todo *p, **prev;
	char buff[256];
	const char *name;
	int status;

	for (p = todolist, prev = &todolist; p; prev = &(p->next), p = p->next)
		if (p->f == f) {
			*prev = p->next;
			name = p->name;
			switch (p->what) {
			case delete:
				free(p);
				if (fclose(f) == EOF) {
					(void)unlink(name);
					status = EOF;
				} else if (unlink(name) < 0)
					status = EOF;
				else
					status = 0;
				return status;
			case execute:
				(void)sprintf(buff, "%s <%s", p->command, p->name);
				free(p);
				if (system(buff)) {
					(void)unlink(name);
					status = EOF;
				} else if (fclose(f) == EOF) {
					(void)unlink(name);
					status = EOF;
				} else if (unlink(name) < 0)
					status = EOF;
				else
					status = 0;
				return status;
			default:
				return EOF;
			}
		}
	return EOF;
}
