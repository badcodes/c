#include <stdio.h>
#include <string.h>
#define MAXLINE 5000 //MAXLINE TO SORT
#define MAXSTRING 1000
#define LINDEBUG 0
#include "..\\linlib\\debug.h"

char *readline();

void quicksort(void *v[],int from,int to,int (*comp)(void *,void*));

int ch5_sort()
{
    char *line[MAXLINE];
    int i,l;
    for(l=0;l<MAXLINE && (line[l]=readline())!=NULL;l++)
        ;    
    quicksort((void*)line,0,l-1,(int (*)(void *,void *))strcmp);
    for(i=0;i<l;i++)
       printf("%s\n",line[i]);
    system("PAUSE");   
    return 0;      
}

char *readline()
{
    char *tmp=malloc(1000);
    char *r;
    if (gets(tmp)!=NULL && strlen(tmp)>0) {
       r=(char*)calloc(strlen(tmp)+1,sizeof(char));
       strcpy(r,tmp);
       free(tmp);
       return r;
       }
    free(tmp);   
    return NULL;      
}

void quicksort(
     void *v[],
     int left,
     int right,
     int (*comp)(void *,void*)
     )
{
     int last,i;
     void swap(void *[],int,int);
     if (left>=right || left<0 ) return ;
     swap(v,left,(left+right)/2);
     last=left;
     for (i=left+1;i<=right;i++){
         if ((*comp)(v[left],v[i])>0){
            ++last;                                           
            swap(v,i,last);
            }
     }
     swap(v,left,last);
     quicksort(v,left,last-1,comp);
     quicksort(v,last+1,right,comp);     
     return;
 }

void swap(void *v[],int i,int j)
{
     void *tmp=v[i];
     v[i]=v[j];
     v[j]=tmp;     
}
