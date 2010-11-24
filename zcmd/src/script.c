#include <stdio.h>
#include <stdlib.h>
#include "cmd.h"
#include "utils.h"
#include "script.h"
#include "zcmd.h"
#include "filecmd.h"

DEFINE_CMD_INFO(
        script,
        "1.0",
        "script processer",
        "(script filename) args...",
        "    -i\tInteractive Mode"
      )


DEFINE_CMD_MAIN(script,int argc,char** argv) {
    char* fn;
    FILE* fp;
    int f_itat=0;
    if(argc==2 && argv[1][0]=='-' && argv[1][1]=='i') {
        f_itat=1;
        argc--;
        argv++;
    }
    if(argc==1) {
        fn="-";
    }
    else {
        fn=argv[1];
    }
    if(fn[0]=='-' && fn[1]=='\0') 
        fp=stdin;
    else
        fp=fopen(fn,"r");
    if(fp) {
        char* line = (char*)malloc(sizeof(char)*MAX_ARG_LENGTH);
        int l=-1;
        if(f_itat) 
            printf("%s>",APPNAME);
        while((l=fgetline(line,MAX_ARG_LENGTH,fp))!=-1) {
            if(l>0)
                process_line(script_NAME,line);
            if(f_itat) 
                printf("%s>",APPNAME);
        }
        fclose(fp);
        return 0;
    }
    else {
        fprintf(stderr,"File not accessable:%s\n",fp);
        return 1;
    }                             
}

