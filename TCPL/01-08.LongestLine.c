/*
 * =====================================================================================
 *
 *       Filename:  01-08.LongestLine.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/21/2007 12:03:30 AM CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */
#include <stdio.h>

#define MAX_STR_LENGTH 1024

int getline(char str[],int maxlength);
void copy(char src[],char dst[]);

int main()
{
    int maxlen=0;
    int len;
    char bigline[MAX_STR_LENGTH];
    char line[MAX_STR_LENGTH];

    while ((len=getline(line,MAX_STR_LENGTH))>0) {
        if (len>maxlen) {
            copy(line,bigline);
            maxlen=len;
        }
    }
    if (maxlen>0)
        printf("Longgest line is : %s",bigline);
    else
        printf("Nothing read.\n");

    return 0;
}

int getline(char str[],int maxlength) 
{
    int c;
    int i=0;
    while ((c=getchar())!=EOF && c!='\n' && i<maxlength-1) {
            str[i++]=c;
    }
    if (c=='\n') 
        str[i++]=c;
    str[i]='\0';
    return i;
}

void copy(char src[],char dst[])
{
    int i=0;
    while ((dst[i]=src[i])) 
        i++;
    dst[i]='\0';
}
