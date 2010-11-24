
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "xrzlib\debug.h"
#include "xrzlib\list.h"
#include "utils.h"
#include "cmd.h"
#include "zcmd.h"

#include "echo.h"
#include "printf.h"
#include "modpath.h"
#include "filecmd.h"
#include "script.h"
#include "exit.h"
#include "cd.h"
#include "run.h"

int main(int argc,char** argv) {
    cmd_init();
    CMD_INIT(xecho);
    CMD_INIT(modpath);
    CMD_INIT(filecmd);
    CMD_INIT(printf);
    CMD_INIT(script);
    CMD_INIT(exit);
    CMD_INIT(zcd);
	CMD_INIT(run);
    DEBUG_PRINTARG("zcmd",argc,argv);
    return zcmd_process(argc,argv);
}

int zcmd_process(int argc,char** argv) {
        int idx;
    if(argc == 1) {
      printf("%s v%s\n    - %s\nUsage:\n    %s\n",
         APPNAME,
         APPVER,
         APPDESC,
         APPUSAGE);
      printf("Support these commands:\n");
      cmd_list();
      printf("Any unsupport command will pass to system shell.\n");
      return 0;
    }
    else {
/*         int u_i; */
/*         char* u_tmp; */
/*         for(u_i=0;u_i<argc;u_i++) { */
/*             u_tmp = unescape(argv[u_i],NULL); */
/*             strcpy(argv[u_i],u_tmp); */
/*             free(u_tmp); */
/*         } */
        idx = cmd_idx(argv[1]);
        if(idx<0) 
            return zcmd_shell(argc-1,argv+1);
        else 
            return cmd_exec(idx,argc-1,argv+1);
   }
}

int zcmd_shell(int argc,char** argv) {
static char* cmdline = NULL;//
    char* tmp;
    int i;
    if(cmdline == NULL) {
        cmdline = (char*)malloc(MAX_ARG_LENGTH*sizeof(char)+1);
    }
    cmdline[0]='\0';
    tmp = (char*)malloc(MAX_ARG_LENGTH*sizeof(char)+1);
    tmp[0]='\0';
    for(i=0;i<argc;i++) {
        quote_onneed(tmp,argv[i]);
//        strcat(cmdline,"\"");
        strcat(cmdline,tmp);
//        strcat(cmdline,"\"");
        if(i!=argc-1)
            strcat(cmdline," ");
    }
    free(tmp);
    DEBUG_PRINT("%s\n",cmdline);
    return system(cmdline);
}

int quote_onneed(char* dst,const char* src) {
    strcpy(dst,src);
    if(isspace(*src++)) {
        int l = strlen(dst);
        dst[l]='\"';
        dst[l+1] = '\0';
        while(l-->0) {
            dst[l] = dst[l-1];
        }
        dst[0]='\"';
        return 1;
    }
    return 0;
}

int zcmd_process_line(const char* cmdline) {
    int r=0;
    if(cmdline) {
        list argvlist = list_break_word(cmdline);
        if(argvlist) {
             int idx = cmd_idx((char*)(argvlist->data));
             if(idx>=0) {
                int argc = list_length(argvlist);
                char** argv = (char**)malloc(sizeof(char*)*argc);
                list_to_argv(argv,argvlist);
                list_free(argvlist);
                free(argvlist);
                r = cmd_exec(idx,argc,argv);     
                argv_free(argc,argv);
                free(argv);
             }
             else {
                list_free_all(argvlist);
                free(argvlist);
                r =  zcmd_shell_line(cmdline);
             }
        }
    }
    return r;
}

