#include <stdio.h>

char **newCharArr(int i)
{
    char **tmp;
    tmp=(char **)malloc(sizeof(*tmp)*i);
    return tmp;
}
char **redimCharArr(char **arr,int from,int to)
{
    int i;
    if (to==from) return arr;
    char **tmp=(char **)malloc(sizeof(*arr)*to);
    if (to<from) to=from;
    for (i=0;i<to;i++)
        *(tmp+i)=*(arr+i);
    free((void*)arr);
    return tmp;
}

char *strdup(char *s)
{
    char *tmp;
    tmp=(char*)malloc(sizeof(char)*(strlen(s)+1));
    strcpy(tmp,s);
    return tmp;
}

#define INITSIZE 300
#define MAXCHAR 200
#define ADDUP 100
#undef LINDEBUG
#include "..\\linlib\\debug.h"

int ch7_DArr()
{
    int size=INITSIZE;
    int linecount=0;
    int ccount=0;
    int c;
    char *tmp=malloc(sizeof(char)*MAXCHAR);
    char **line=newCharArr(size);
    FILE *f;
    if ((f=fopen("text","r"))==NULL) {
        printf("%s\n","File not exist.");
        return -1;
    }
    while((c=getc(f))!=EOF){
        if (c=='\n'){
            tmp[ccount]='\0';
            if (linecount>=size-1){
                line=redimCharArr(line,size,size+ADDUP);
                size += ADDUP;
            }
            line[linecount]=strdup(tmp);
            //debugStr(line[linecount]);
            linecount++;
            ccount=0;
        }
        else if (ccount>=MAXCHAR-1) {
            tmp[ccount]='\0';
            if (linecount>=size-1){
                line=redimCharArr(line,size,size+ADDUP);
                size += ADDUP;
            }
            line[linecount]=strdup(tmp);
            //debugStr(line[linecount]);
            linecount++;
            ccount=0;
            tmp[ccount++]=c;
        }
        else
            tmp[ccount++]=c;
    }
    fclose(f);
    debugInt(linecount);
    debugInt(size);
    PAUSE;
    tmp[ccount]='\0';
    line[linecount]=strdup(tmp);
    for(c=0;c<=linecount;c++){
        printf("%d:%s\n",c,line[c]);
        if (!(c%10)) PAUSE;
    }
    return 0;
}
