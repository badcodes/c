/*
 * =====================================================================================
 *
 *       Filename:  002.Fah-Cel.c
 *
 *    Description:  Convert from Fahrenheit and Celsius temperatures.
 *
 *        Version:  1.0
 *        Created:  03/20/2007 08:11:32 PM CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 12
#define C_LOWER ((LOWER+UPPER)/2)

float f2c(float);
float c2f(float);


int main(int argc,char* argv[])
{
    int i;
    printf("Fahrenheit\tCelsius\t\tCelsius\t\tFahrenheit\n");
    for (i=LOWER;i<=UPPER;i+=STEP) {
        printf("%5d\t\t%5.1f\t\t%5d\t\t%5.1f\n",i,f2c(i),i-C_LOWER,c2f(i-C_LOWER));
        }
    return 0;
    
}

//C = (5/9)*(F-32)

float f2c(float f) 
{
    return 5.0*(f-32.0)/9.0;    
}

//F = 9*C/5+32

float c2f(float c)
{
    return 9.0*c/5.0+32.0;
}

