/* wildcard.c */

/* Author:
 *	Guntram Blohm
 *	Buchenstrasse 19
 *	7904 Erbach, West Germany
 *	Tel. ++49-7305-6997
 *	sorry - no regular network connection
 */

/* this program implements wildcard expansion for elvis/dos. It works
 * like UNIX echo, but uses the dos wildcard conventions
 * (*.* matches all files, * matches files without extension only,
 * filespecs may contain drive letters, wildcards not allowed in directory
 * names).
 *
 * Grieviously hacked by M.Lord for use with LESS177 port to MSDOS.
 * The original elegant code is now barely discernable.
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <dos.h>
#include "compiler.h"

extern void *malloc();
char *buf, *bufp;
unsigned len;

void
addfile(f)
	char *f;
{
	char *p;

	if ((!len) && ((buf = bufp = (char *) malloc (len = 128)) == NULL)) {
		len = 0;
		return;
	}

	if ((len - (int)(bufp - buf)) <= (2 + strlen(f))) {
		*bufp = '\0';
		if ((p = (char *) malloc(len + 128)) == NULL)
			return;
		len += 128;
		bufp = (char *) strcpy (p, buf);
		free (buf);
		for (buf = bufp; *bufp; bufp++);
	}
	*bufp++ = ' ';
	while ((*bufp++ = tolower(*f++)) != '\0');
	--bufp;
}

char *
expand(name)
	char *name;
{
	char *filespec;
	int wildcard=0;
	struct ffblk findbuf;
	int err;
	char f[80];
	len = 0;	/* force allocation of a fresh buffer */

	strcpy(f, name);
	for (filespec=f; *filespec; filespec++);

	while (--filespec>=f)
	{	if (*filespec=='?' || *filespec=='*')
			wildcard=1;
		if (*filespec=='/' || *filespec=='\\' || *filespec==':')
			break;
	}
	if (!wildcard)
		addfile(f);
	else
	{
		filespec++;
		err=findfirst(f, &findbuf, 0);
		while (!err)
		{
			strcpy(filespec, FILENAME(findbuf));
			addfile(f);
			err=findnext(&findbuf);
		}
	}
	return (len == 0) ? NULL : buf;
}
