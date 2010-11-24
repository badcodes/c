/*
 * =====================================================================================
 *
 *       Filename:  01-06.WordsCount.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2007 10:26:02 PM CST
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

int is_blank(int);

int main()
{
    int c;
    int inword=OUT;
    int nw=0;

    while((c=getchar())!=EOF) {
        if (is_blank(c))
            inword=OUT;
        else if (! inword) {
                inword=IN;
                ++nw;
            }
    }
    printf("%d words read.\n",nw);
    return 0;
}

int is_blank(int c)
{
    if (c==' ' || c=='\t' || c== '\n') 
        return 1;
    return 0;
}
