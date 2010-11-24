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

void print_info( const char* nm,
                const char* ver,
                const char* desc,
                const char* usage,
                const char* option
                ){
   printf("%s v%s\n    -%s\nUsage:%s\n",
        nm,ver,desc,usage);
   if(option)
        printf("Options:\n%s",option);
    
}


DEFINE_CMD_MAIN(help,int argc,char** argv) {
   char* cmdname;
   if(argc<2) {
      cmdname="help";
      display_help(cmdname);
      printf("Available commands:\n");
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

int display_help(const char* cmdname) {
   int cmdidx = cmd_idx(cmdname);
   if(cmdidx>=0) {
      CMDINFO *thiscmd = cmd_info(cmdidx);
      print_info(thiscmd->name,thiscmd->ver,thiscmd->desc,thiscmd->usage,thiscmd->option);
      return 0;
   }
   else {
		char *cmd = malloc((strlen(cmdname) + 5)*sizeof(char)+1);
		strcpy(cmd,"help ");
		strcat(cmd,cmdname);
		system(cmd);
//      printf("No information available for \"%s\"\n",cmdname);
      return 1;
   }
}
int display_help_ex(const char* cmdname) {
   int cmdidx = cmd_idx(cmdname);
   char* exopt;
   if(cmdidx>=0) {
      CMDINFO *thiscmd = cmd_info(cmdidx);
      if(thiscmd->option) {
        exopt = malloc((strlen(thiscmd->option) + strlen(DEFAULT_OPTION))*sizeof(char)+1);
        strcpy(exopt,DEFAULT_OPTION);
        strcat(exopt,thiscmd->option);
      }
      else {
        exopt = DEFAULT_OPTION;
      }
      print_info(thiscmd->name,thiscmd->ver,thiscmd->desc,thiscmd->usage,exopt);
      return 0;
   }
   else {
      printf("No information available for \"%s\"\n",cmdname);
      return 1;
   }
}
