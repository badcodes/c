#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xrzlib\debug.h"
#include "cmd.h"
#include "utils.h"
#include "printf.h"


#define PRINTF_DEBUG_PRINT(FMT,STR) \
       DEBUG_PRINT("%s\n","printf(" #FMT "," #STR ")")
       // #FMT "=" %s," #STR "=%s\n",FMT,STR);

DEFINE_CMD_INFO(
        printf,"1.0","Emuleate c printf",
        "[format string] arguments...",NULL
)

DEFINE_CMD_MAIN(printf,int argc,char** argv) {
    char *fmtbuf,*fmt,*saved;
    int myargc,match;
    char c;
    unescape_argv(argc-1,argv+1);

    DEBUG_PRINTARG("printf called with",argc,argv);
    if(argc == 1)
        return 0;
    fmtbuf = argv[1];
    if(argc == 2) {
        printf ("%s",fmtbuf);
        return 0;
    }
    fmt = strdup(fmtbuf);
    saved = fmt;
    myargc = 2;
    match = 0;
    while( myargc<argc && *fmtbuf!=NULL ) {
        c=(*fmtbuf);
        *(fmt++)=*fmtbuf;
        fmtbuf++;
        match=0;
        if(c=='%') {
            while(myargc<argc && *fmtbuf != NULL) {
                c=*fmtbuf;
                *(fmt++)=c;
                fmtbuf++;
                switch(c) {
                    case 's':
                    case 'S':
                        *fmt=NULL;
                        PRINTF_DEBUG_PRINT(saved,argv[myargc]);
                        printf(saved,argv[myargc++]);
                        match = 1;
                        break;
                    case 'c' :
                    case 'C' :
                        *fmt=NULL;
                        PRINTF_DEBUG_PRINT(saved,argv[myargc]);
                        printf(saved,argv[myargc++][0]);
                        match = 1;
                        break;
                    case 'p' :
                    case 'P' :
                        *fmt=NULL;
                        PRINTF_DEBUG_PRINT(saved,argv[myargc]);
                        printf(saved,argv[myargc++]);
                        match = 1;
                        break;
                    case 'd' :
                    case 'D' :
                        *fmt=NULL;
                        PRINTF_DEBUG_PRINT(saved,argv[myargc]);
                        printf(saved,atoi(argv[myargc++]));
                        match = 1;
                        break;
                    case 'f' :
                    case 'F' :
                    case 'G' :
                    case 'g' :
                        *fmt=NULL;
                        PRINTF_DEBUG_PRINT(saved,argv[myargc]);
                        printf(saved,atof(argv[myargc++]));
                        match = 1;
                        break;
                    case '%' :
                        break;
                    default :
                        break;
                }
                if(match==1) {
                    fmt = saved;
                    break;
                }
            }
        }
    }
    if(match) {
        if(*fmtbuf)
            printf("%s",fmtbuf);
    }
    else {
        *fmt='\0';
        printf("%s",saved);
    }
/*
    if(!match && *saved!=NULL) {
        PRINTF_DEBUG_PRINT("%s",saved);
        printf("%s",saved);
    }
    else if(*(fmtbuf) != NULL) {
        PRINTF_DEBUG_PRINT("%s",fmtbuf);
        printf("%s",fmtbuf);
    }
*/
    for(;myargc<argc;myargc++) {
        PRINTF_DEBUG_PRINT("%s",argv[myargc]);
        printf("%s",argv[myargc]);
    }
    free(saved);
    return 0;
}

