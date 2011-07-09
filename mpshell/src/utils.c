#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "xrzlib\debug.h"
#include "zcmd.h"
#include "utils.h"


#define SKIPSPACE(s) while(isspace(*s)) s++;

void unescape_argv(int argc,TCHAR** argv) {
    int i;
    TCHAR* tmp;
    for(i=0;i<argc;i++) {
        tmp = unescape(argv[i],NULL);
        _tcscpy(argv[i],tmp);
        free(tmp);
    }
}

TCHAR* unescape(const TCHAR* src,TCHAR* dst) {
    int i;
    TCHAR c;
    TCHAR* unstr = _tcsdup(src);
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
        _tcscpy(dst,unstr);
        return dst;
    }
    else {
        return unstr;
    }
}

int printarg(const TCHAR* msghd,int argc,TCHAR** argv) {
    int i;
    if(msghd)
        _tprintf(TEXT("%s\n"),msghd);
        for(i=0;i<argc;i++) {
                _tprintf(TEXT("argv[%2d] = %s\n"),i,argv[i]);
    }
    return 1;
}

int fgetline(TCHAR* s,int n,FILE* stream) {
    int l=0;
    if(fgets(s,n,stream)==NULL) {
        DEBUG_PRINTS(TEXT("end of file"));
        return -1;
    }
    else {
        DEBUG_PRINT(TEXT("get line : %s\n"),s);
        l = _tcslen(s);
        if (s[l-1]=='\n')
            s[l-1]='\0';
        return l-1;
    }

}

int break_cmdline(TCHAR** argv,const TCHAR* s,int max) {
    int argc;
    int c,lastc;
    TCHAR* tmp;
    int tc; //index for tmp
    int fq; //flag of quoting
    tmp = (TCHAR*)malloc(MAX_ARG_LENGTH*sizeof(TCHAR));
    argc=0;tc=0;fq=0;lastc='\0';
    SKIPSPACE(s);
    DEBUG_PRINT(TEXT("break_cmdline begin with [%s]\n"),s);
    while(argc<max && ((c=*(s++))!=NULL)) {
        if(c == '\"' && lastc != '\\') {
            if(fq) {
                fq=0;
                //tmp[tc++]=c;
                tmp[tc]='\0';
                tc=0;
                argv[argc++]=_tcsdup(tmp);
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
            argv[argc++]=_tcsdup(tmp);
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
            argv[argc] = (TCHAR*)malloc(MAX_ARG_LENGTH*sizeof(TCHAR));
            argv[argc][0] = '\"';
            _tcscat(argv[argc],tmp);
        }
        else {
            argv[argc++]=_tcsdup(tmp);
        }
    }
    DEBUG_PRINT_LOOP(argc,argv,TEXT("break_cmdline get \"%s\"\n"));
    DEBUG_PRINT(TEXT("%s\n"),TEXT("break_cmdline end"));
    return argc;
}

int free_argv(int argc,TCHAR** argv) {
    while(argc-->0) {
        free(argv[argc]);
    }
    return 1;
}

TCHAR* unquote(TCHAR* src) {
    int l_src;
    l_src = _tcslen(src);
    if(l_src > 2 && src[0]=='\"' && src[l_src-1]=='\"') {
        int i;
        for(i=0;i<l_src-1;i++) {
            src[i]=src[i+1];
        }
        src[l_src-1]='\0';
    }
    return src;
}
TCHAR* quote(TCHAR* dst,const TCHAR* src) {
    TCHAR* tmp;
    if(dst == NULL || dst == src) {
        tmp = malloc(sizeof(TCHAR)*(_tcslen(src)+2+1));
    }
    else {
        tmp = dst;
    }
    tmp[0]='\"';
    tmp[1]='\0';
    _tcscat(tmp,src);
    _tcscat(tmp,"\"");
    return tmp;
}
void argv_free(int argc,TCHAR** argv) {
}

TCHAR** list_to_argv(TCHAR** argv,list lst) {
	return NULL;
}

list list_break_word(const TCHAR* line) {
	return NULL;
}

void list_free(list lst) {
}
void list_free_all(list lst) {
}

