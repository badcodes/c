#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "config.h"
#include "xrzlib\debug.h"
#include "xrzlib\os.h"
#include "zcmd.h"
#include "utils.h"
#include "version.h"
#include "filecmd.h"

#define SKIPSPACE(s) while(isspace(*s)) s++;;
int free_argv(int argc,TCHAR** argv);

DEFINE_CMD_INFO(
    filecmd,
    "1.0",
    "Run commands from file",
    "(filenames...)",
    NULL
)

DEFINE_CMD_MAIN(filecmd,int argc,TCHAR** argv) {
    int i;
    TCHAR* fn;
    FILE* fp;
    for(i=1;i<argc;i++) {
        fn=argv[i];
        if(_tcscmp(fn,TEXT("-"))==0)
            fp=stdin;
        else {
            fp=_tfopen(fn,TEXT("r"));
        }
        if(fp) {
            TCHAR* line = malloc(MAX_ARG_LENGTH*sizeof(TCHAR)+1);
            int l=0;
            DEBUG_PRINT(TEXT("reading file %s\n"),fn);
            while((l=fgetline(line,MAX_ARG_LENGTH,fp))!=-1) {
                if(l==0)
                    continue;
                if(!process_line(APPNAME,line))
                    break;
            }
            fclose(fp);
        }
        else {
            fprintf(stderr,TEXT("File not accessable:\"%s\"\n"),fn);
        }
    }
    return 0;
}

int process_line(const TCHAR* appname,const TCHAR* line) {
    static TCHAR** argv_l = NULL;
    static int argc_l = 0;
    if(argv_l) {
        while(argc_l-->0)
            free(argv_l[argc_l]);
    }
    else {
       argv_l = (TCHAR**)malloc(MAX_ARGC*sizeof(TCHAR*));
    }
    argc_l = 1;
    argv_l[0] = _tcsdup(appname);
    argc_l = break_cmdline(argv_l+1,line,MAX_ARGC);
    if(argc_l>0) {
        argc_l++;
        DEBUG_CODE_BEGIN
            printarg(TEXT("process_line"),argc_l,argv_l);
        DEBUG_CODE_END
        zcmd_process(argc_l,argv_l);
        return 1;
    }
    return 1;
}
