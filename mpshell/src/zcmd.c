#ifdef WINDOWS
#include <windows.h>
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#include "config.h"
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

#ifdef WINDOWS

int WINAPI WinMain(
  HINSTANCE hInstance,      // handle to current instance
  HINSTANCE hPrevInstance,  // handle to previous instance
  LPSTR lpCmdLine,          // command line
  int nCmdShow              // show state
) {
    int argc;
    LPTSTR* argv;
    LPTSTR cmdline = GetCommandLine();
    argv = CommandLineToArgvW(cmdline,&argc);
    return mpshell(argc,argv);
}
#else
int main(int argc, LPTSTR *argv) {
        return mpshell(argc,argv);
}
#endif


int mpshell(int argc,TCHAR** argv) {
    cmd_init();
    CMD_INIT(xecho);
    CMD_INIT(modpath);
    CMD_INIT(filecmd);
    CMD_INIT(printf);
    CMD_INIT(script);
    CMD_INIT(exit);
    CMD_INIT(zcd);
	CMD_INIT(run);
	CMD_INIT(hstart);
    DEBUG_PRINTARG(TEXT("zcmd"),argc,argv);
    return zcmd_process(argc,argv);
}

int zcmd_process(int argc,TCHAR** argv) {
        int idx;
    if(argc == 1) {
      _tprintf(TEXT("%s v%s\n    - %s\nUsage:\n    %s\n"),
         APPNAME,
         APPVER,
         APPDESC,
         APPUSAGE);
      _tprintf(TEXT("Support these commands:\n"));
      cmd_list();
      _tprintf(TEXT("Any unsupport command will pass to system shell.\n"));
      return 0;
    }
    else {
/*         int u_i; */
/*         TCHAR* u_tmp; */
/*         for(u_i=0;u_i<argc;u_i++) { */
/*             u_tmp = unescape(argv[u_i],NULL); */
/*             _tcscpy(argv[u_i],u_tmp); */
/*             free(u_tmp); */
/*         } */
        idx = cmd_idx(argv[1]);
        if(idx<0)
            return zcmd_shell(argc-1,argv+1);
        else
            return cmd_exec(idx,argc-1,argv+1);
   }
}

int zcmd_shell(int argc,TCHAR** argv) {
static TCHAR* cmdline = NULL;//
    TCHAR* tmp;
    int i;
    if(cmdline == NULL) {
        cmdline = (TCHAR*)malloc(MAX_ARG_LENGTH*sizeof(TCHAR)+1);
    }
    cmdline[0]='\0';
    tmp = (TCHAR*)malloc(MAX_ARG_LENGTH*sizeof(TCHAR)+1);
    tmp[0]='\0';
    for(i=0;i<argc;i++) {
        quote_onneed(tmp,argv[i]);
//        _tcscat(cmdline,"\"");
        _tcscat(cmdline,tmp);
//        _tcscat(cmdline,"\"");
        if(i!=argc-1)
            _tcscat(cmdline," ");
    }
    free(tmp);
    DEBUG_PRINT("%s\n",cmdline);
    return system(cmdline);
}

int quote_onneed(TCHAR* dst,const TCHAR* src) {
    _tcscpy(dst,src);
    if(isspace(*src++)) {
        int l = _tcslen(dst);
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

int zcmd_process_line(const TCHAR* cmdline) {
    int r=0;
    if(cmdline) {
        list argvlist = list_break_word(cmdline);
        if(argvlist) {
             int idx = cmd_idx((TCHAR*)(argvlist->data));
             if(idx>=0) {
                int argc = list_length(argvlist);
                TCHAR** argv = (TCHAR**)malloc(sizeof(TCHAR*)*argc);
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

