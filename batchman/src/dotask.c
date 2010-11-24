/*
 * =====================================================================================
 *
 *       Filename:  dotask.c
 *
 *    Description:  do task
 *
 *        Version:  1.0
 *        Created:  01/07/2007 01:25:27 AM HKT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */
#include "config.h"
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "dotask.h"
#include <stdio.h>

int dotask(const char *url, const char *taskhandler)
{
    if (taskhandler == NULL)
	taskhandler = DOWNLOADER;
    char *cmdline = (char *) malloc(strlen(taskhandler) + strlen(url) + 4);
    sprintf(cmdline, "%s \"%s\"", taskhandler, url);
    //printf("%s\n",cmdline);
    return (system(cmdline));
}
