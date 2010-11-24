/*
 * =====================================================================================
 *
 *       Filename:  ex0109ReplaceBlank.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2007 09:19:48 PM CST
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
    int b = EOF;
    while ( (c = getchar()) != EOF)
    {
        if ( c != ' ')
            putchar(c);
        else if (b != ' ')
            putchar(c);
        b = c;
    }
}

