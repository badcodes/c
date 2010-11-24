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
#include <ctype.h>
#include <wchar.h>
int main(int argc,char* argv []){
    int size;
    char* str;
    if (argc<3)
	return -1;
    str = argv[1];
    size = atoi(argv[2]);
    if (size<0) 
	size = 0;
    if (strlen(str) <= size)
	printf("%s\n",str);
    else {
	str[size]='\0';
	printf("%s\n",str);
    }
    return 0;
}
