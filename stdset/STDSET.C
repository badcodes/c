#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include "stdset.h"

int main(int argc,char** argv) {
        char INPUT[MAXVAR];
        int count=0;
        int c;
    if(argc!=2) {
        printf("%s v%s, by %s\n",APPNAME,APPVER,APPAUTHOR);
        printf("\t- %s\n",APPDESC);
        printf("Usage:\n\t%s %s",argv[0],APPUSAGE);
        return 1;
        }
        while((c=getchar())!=EOF) {
                INPUT[count++]=c;
                if(count>=MAXVAR-1) {
                        break;
                }
        }
        while(count>1 && INPUT[count-1]=='\n') {
                count--;
        }
        INPUT[count]=0;
        printf("%s",INPUT);
}
