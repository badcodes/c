/*
 * =====================================================================================
 *
 *       Filename:  01-04.CountChars.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2007 09:06:58 PM CST
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
    int nc=0;
    while (getchar()!=EOF)
        nc++;
    printf("%d charactors read.\n",nc);
    return 0;
        
}

