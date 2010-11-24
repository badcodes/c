/*
 * =====================================================================================
 *
 *       Filename:  ex0119ReverseInput.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/21/2007 12:30:56 AM CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */
#include <stdio.h>

#define MAX_LINE 1024

int getline(char str[],int lim);

int main()
{
    char line[MAX_LINE];
    int len;

    while ((len=getline(line,MAX_LINE))>0) {
        int i;
        for (i=len-2;i>=0;i--)
            putchar(line[i]);
        putchar('\n');
    }
}


int getline(char str[],int lim) 
{
    int i=0;
    int c;
    while ((c=getchar())!=EOF && c!='\n' && i<lim-1)
        str[i++]=c;
    if (c=='\n')
        str[i++]=c;
    str[i]='\0';
    return i;
}
