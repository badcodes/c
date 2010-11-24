/*
 * =====================================================================================
 *
 *       Filename:  01-07.MathPower.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2007 11:39:07 PM CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */
#include <stdio.h>
#define LOWER 1
#define UPPER 100
#define POWERVALUE 6

double power(int,int);

int main()
{
    int i,j;
    for (i=LOWER;i<=UPPER;i++) {
        printf("%3d",i);
        for (j=2;j<=POWERVALUE;j++)
            printf("*%3d",i);
        printf("\t\t=\t\t%.0f\n",power(i,POWERVALUE));
    }
    return 0;
}
/*
double power(int base,int n)
{
    double result=1;
    if (n>0) 
        return result*power(base,n-1);
    else
        return result;
}
*/

double power(int base,int n)
{
    double result=1;
    while (n-->0) 
        result*=base;
    return result;
}
