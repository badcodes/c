/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  test system return value
 *
 *        Version:  1.0
 *        Created:  01/07/2007 08:48:58 PM HKT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* cmdline =NULL;
    size_t cs=0;
    int sv;
    while(getline(&cmdline,&cs,stdin)!=-1) {
	sv = system(cmdline);
	printf("System Return %d \n",sv);
    }

}
