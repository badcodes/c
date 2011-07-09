#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmd.h"
#include "help.h"

DEFINE_CMD_INFO(
    help,
    "1.0",
    "Display information for command",
    "(command name)",
    NULL
)

void print_info( const TCHAR* nm,
                const TCHAR* ver,
                const TCHAR* desc,
                const TCHAR* usage,
                const TCHAR* option
                ){
   _tprintf(TEXT("%s v%s\n    -%s\nUsage:%s\n"),
        nm,ver,desc,usage);
   if(option)
        _tprintf(TEXT("Options:\n%s"),option);

}


DEFINE_CMD_MAIN(help,int argc,TCHAR** argv) {
   TCHAR* cmdname;
   if(argc<2) {
      cmdname=TEXT("help");
      display_help(cmdname);
      _tprintf(TEXT("Available commands:\n"));
      cmd_list();
   }
   else {
	  int i;
	  for(i=1;i<argc;i++) {
		display_help(argv[i]);
	  }
   }
   return 0;
}

int display_help(const TCHAR* cmdname) {
   int cmdidx = cmd_idx(cmdname);
   if(cmdidx>=0) {
      CMDINFO *thiscmd = cmd_info(cmdidx);
      print_info(thiscmd->name,thiscmd->ver,thiscmd->desc,thiscmd->usage,thiscmd->option);
      return 0;
   }
   else {
		TCHAR *cmd = malloc((_tcslen(cmdname) + 5)*sizeof(TCHAR)+1);
		_tcscpy(cmd,TEXT("help "));
		_tcscat(cmd,cmdname);
		system(cmd);
//      _tprintf("No information available for \"%s\"\n",cmdname);
      return 1;
   }
}
int display_help_ex(const TCHAR* cmdname) {
   int cmdidx = cmd_idx(cmdname);
   TCHAR* exopt;
   if(cmdidx>=0) {
      CMDINFO *thiscmd = cmd_info(cmdidx);
      if(thiscmd->option) {
        exopt = malloc((_tcslen(thiscmd->option) + _tcslen(DEFAULT_OPTION))*sizeof(TCHAR)+1);
        _tcscpy(exopt,DEFAULT_OPTION);
        _tcscat(exopt,thiscmd->option);
      }
      else {
        exopt = DEFAULT_OPTION;
      }
      print_info(thiscmd->name,thiscmd->ver,thiscmd->desc,thiscmd->usage,exopt);
      return 0;
   }
   else {
      _tprintf(TEXT("No information available for \"%s\"\n"),cmdname);
      return 1;
   }
}
