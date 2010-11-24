#include <stdio.h>
#define LINDEBUG
#include "..\\linlib\\debug.h"

const day_month[2][12]={
      {31,28,31,30,31,30,31,31,30,31,30,31},
      {31,29,31,30,31,30,31,31,30,31,30,31}
      };
char *month_name(unsigned int m)
{
     static char* ns[]={
            "错误的月分","一月","二月","三月","四月",
            "五月","六月","七月","八月","九月","十月",
            "十一月","十二月" 
     };
     return ((m<1 || m>12)?ns[0]:ns[m]);
 }
int dayofyear(int y,int m,int d)
{
    int leap=0;
    int i;
    if (y<0) return -1;
    if (m<1 || m>12) return -1;
    if ((!y%4 && y%100) || (!y%400)) leap=1;
    if (d>day_month[leap][m+1]) return -1;
    for (i=0;i<m-1;i++)
        d=d+day_month[leap][i];
    return d;
}

void mdofday(int y,int day,int *m,int *d)
{
     int leap=0;
     if (y<0) return;
     if ((!y%4 && y%100) || (!y%400)) leap=1;
     if (day>365+leap) return;
     for(*m=1;day>day_month[leap][*m-1];*m=*m+1){
         day -= day_month[leap][*m-1];
     }
     *d=day;
}

int ch5_monthday()
{
    int m=0;
    int d=0;
    int day=dayofyear(2006,2,15);
    printf("There %s %d %s by 2006.2.15 since 2006.1.1\n",\
         (day>1)?"are":"is",\
         day,\
         (day>1)?"days":"day");
    mdofday(2006,35,&m,&d);
    printf("%d days up since 2006.1.1 is 2006.%d.%d\n",35,m,d);
    for (m=0;m<14;m++) {
        debugInt(m);
        debugStr(month_name(m));   
        }
    system("PAUSE");
}
