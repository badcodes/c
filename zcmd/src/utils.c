#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "xrzlib\debug.h"
#include "utils.h"


#define SKIPSPACE(s) while(isspace(*s)) s++;

void unescape_argv(int argc,char** argv) {
    int i;
    char* tmp;
    for(i=0;i<argc;i++) {
        tmp = unescape(argv[i],NULL);
        strcpy(argv[i],tmp);
        free(tmp);
    }
}

char* unescape(const char* src,char* dst) {
    int i;
    char c;
    char* unstr = strdup(src);
        for(i=0;(c=*(src++)) != '\0';i++) {
        if(c=='\\') {
            c = *(src++);
            switch(c) {
                case 'n':
                    unstr[i]='\n';
                    break;
                case 't':
                    unstr[i]='\t';
                    break;
                case '\\':
                    unstr[i]='\\';
                    break;
                case 'r':
                    unstr[i]='\r';
                    break;
                case 'a':
                    unstr[i]='\a';
                    break;
                case 'b':
                    unstr[i]='\b';
                    break;
                case 'f':
                    unstr[i]='\f';
                    break;
                case '\"':
                    unstr[i]='\"';
                    break;
                default:
                    unstr[i]='\\';
                    unstr[i++] = c;
                    break;
            }
        }
        else {
            unstr[i] = c;
        }
    }
    unstr[i]='\0';
    if(dst != NULL) {
        strcpy(dst,unstr);
        return dst;
    }
    else {
        return unstr;
    }
}

int printarg(const char* msghd,int argc,char** argv) {
    int i;
    if(msghd)
        printf("%s\n",msghd);
        for(i=0;i<argc;i++) {
                printf("argv[%2d] = %s\n",i,argv[i]);
    }
    return 1;
}

int fgetline(char* s,int n,FILE* stream) {
    int l=0;
    if(fgets(s,n,stream)==NULL) {
        DEBUG_PRINTS("end of file");
        return -1;
    }
    else {
        DEBUG_PRINT("get line : %s\n",s);
        l = strlen(s);
        if (s[l-1]=='\n')
            s[l-1]='\0';
        return l-1;
    }

}

int break_cmdline(char** argv,const char* s,int max) {
    int argc;
    int c,lastc;
    char* tmp;
    int tc; //index for tmp
    int fq; //flag of quoting
    tmp = (char*)malloc(MAX_ARG_LENGTH*sizeof(char));
    argc=0;tc=0;fq=0;lastc='\0';
    SKIPSPACE(s);
    DEBUG_PRINT("break_cmdline begin with [%s]\n",s);
    while(argc<max && ((c=*(s++))!=NULL)) {
        if(c == '\"' && lastc != '\\') {
            if(fq) {
                fq=0;
                //tmp[tc++]=c;
                tmp[tc]='\0';
                tc=0;
                argv[argc++]=strdup(tmp);
                SKIPSPACE(s);
                continue;
            }
            else if(tc==0) {
                fq=1;
                //tmp[tc++]=c;
                continue;
            }
        }
        if(fq==0 && isspace(c)) {
            SKIPSPACE(s);
            tmp[tc]='\0';
            tc=0;
            argv[argc++]=strdup(tmp);
        }
        else {
            lastc=c;
            tmp[tc++]=c;
        }
    }
    if(tc>0 && argc<max) {
        tmp[tc]='\0';
        if(fq) {
            //put the beginning "quote" back to argument
            argv[argc] = (char*)malloc(MAX_ARG_LENGTH*sizeof(char));
            argv[argc][0] = '\"';
            strcat(argv[argc],tmp);
        }
        else {
            argv[argc++]=strdup(tmp);
        }
    }
    DEBUG_PRINT_LOOP(argc,argv,"break_cmdline get \"%s\"\n");
    DEBUG_PRINT("%s\n","break_cmdline end");
    return argc;
}

int free_argv(int argc,char** argv) {
    while(argc-->0) {
        free(argv[argc]);
    }
    return 1;
}

char* unquote(char* src) {
    int l_src;
    l_src = strlen(src);
    if(l_src > 2 && src[0]=='\"' && src[l_src-1]=='\"') {
        int i;
        for(i=0;i<l_src-1;i++) {
            src[i]=src[i+1];
        }
        src[l_src-1]='\0';
    }
    return src;
}
char* quote(char* dst,const char* src) {
    char* tmp;
    if(dst == NULL || dst == src) {
        tmp = malloc(sizeof(char)*(strlen(src)+2+1));
    }
    else {
        tmp = dst;
    }
    tmp[0]='\"';
    tmp[1]='\0';
    strcat(tmp,src);
    strcat(tmp,"\"");
    return tmp;
}
void argv_free(int argc,char** argv) {
}

char** list_to_argv(char** argv,list lst) {
	return NULL;
}

list list_break_word(const char* line) {
	return NULL;
}

void list_free(list lst) {
}
void list_free_all(list lst) {
}

