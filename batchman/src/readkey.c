/*
 * =====================================================================================
 *
 * Filename:readkey.c
 *
 *Description:readkey from stdio noblocking mode
 *
 *Version:1.0
 *Created:01/07/2007 01:54:59 AM HKT
 * Revision:none
 * Compiler:gcc
 *
 * Author:xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *Company:MYPLACE
 *
 * =====================================================================================
 */

#include "config.h"

#ifdef PROCESS_INPUT

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "batchman.h"
#include <string.h>

int inputavail()
{
    fd_set rfds;
    struct timeval tv;
    int retval;

/* Watch stdin (fd 0) to see when it has input. */
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

/* Wait up to 40 microseconds. */
    tv.tv_sec = 0;
    tv.tv_usec = 40;

    retval = select(1, &rfds, NULL, NULL, &tv);
    /* Don’t rely on the value of tv now! */
//    APPMSG("Select Time out,return %d\n",retval);
    if (retval>0)
	return 1;
    return 0;
}

int readkey()
{
    int key = EOF;
    if (inputavail() == 1) {
	key = getchar();	//read(0,&key,1);
	//printf("key %c:%d read.\n",key,key);
    }
    return key;
}

char* readline()
{
    const int MAXLength = 256;
    char result[MAXLength];
    int f=-1;
    if (inputavail()==1) {
        f=read(STDIN_FILENO ,result,MAXLength);
        if (f>0) result[f]='\0';
    }
    return (f>0)?strdup(result):NULL;
}
#endif
