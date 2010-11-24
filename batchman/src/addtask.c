/*
 * =====================================================================================
 *
 *       Filename:  addtask.c
 *
 *    Description:  addtask from File stream
 *
 *        Version:  1.0
 *        Created:  01/06/2007 06:15:59 AM HKT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */



#include "config.h"
#include <stdio.h>
#include "queue.h"
#include "batchman.h"
#include <sys/stat.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <stdio_ext.h>
#include "path.h"

#define TEMPFILE "tmp.tmp"

int addtask(Queue * s, const char *taskfile)
{
    char *task = NULL;
    size_t c = 0;
    int l = 0;
    char *pdir = dirname(taskfile);
    char *tmpfile = buildpath(pdir, TEMPFILE);


    unlink(tmpfile);
    rename(taskfile, tmpfile);

    FILE *ftask = fopen(tmpfile, "r");
    if (ftask != NULL) {
	APPMSG("Tasks read from %s\n", tmpfile);
	while ((l = getline(&task, &c, ftask)) > 0) {
	    if (task[l - 1] == '\n') {
		if (l == 1) {
		    task = NULL;
		    continue;
		 }
		task[l - 1] = 0;
	    }
	    APPMSG("Task added: %s\n", task);
	    queue_in(task, s);
	    task = NULL;
	}
	fclose(ftask);
        free(tmpfile);
        free(pdir);
	unlink(tmpfile);
        return 0;
    }
    free(tmpfile);
    free(pdir);
    return 0;
}
