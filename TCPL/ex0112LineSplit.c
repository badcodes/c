/*
 * =====================================================================================
 *
 *       Filename:  ex0112LineSplit.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2007 11:25:45 PM CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */
#include <stdio.h>
#define IN  1
#define OUT 0

int main()
{
    int c;
    int inword=OUT;

    while ((c=getchar())!=EOF){
        if (c==' ' || c=='\t' || c=='\n') {
            if (inword==IN) putchar('\n');
            inword=OUT;
            }
        else {
            putchar(c);
            inword=IN;
        }
    }
}

