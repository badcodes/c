/*
 * =====================================================================================
 *
 *       Filename:  strlen.c
 *
 *    Description:  Return length of then string.
 *
 *        Version:  1.0
 *        Created:  12/15/2006 08:24:22 PM CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
int main(int argc,char* argv []){
    if (argc<2)
	printf("%d\n",0);
    printf("%d\n",strlen(argv[1]));
    return 0;
}
