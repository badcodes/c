/*
 * =====================================================================================
 *
 *       Filename:  01-05.CountLines.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2007 09:12:03 PM CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */

#include <stdio.h>

int main() 
{
    int c;
    int nl=0;
    while ((c=getchar())!=EOF)
        if (c=='\n') ++nl;
    printf("%d lines read.\n",nl);
    return 0;
        
}

