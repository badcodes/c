#include <stdio.h>
#include <string.h>
#include "config.h"
#include "cmd.h"
#include "help.h"
#include "xrzlib\debug.h"

CMDINFO cmd_pool[CMD_MAX];
int cmd_count = 0;

int cmd_register(
                const TCHAR* name,
                const TCHAR* ver,
                const TCHAR* desc,
                const TCHAR* usage,
                const TCHAR* option,
      cmdfun call) {
   cmd_pool[cmd_count].name = name;
   cmd_pool[cmd_count].ver = ver;
   cmd_pool[cmd_count].desc = desc;
   cmd_pool[cmd_count].usage = usage;
   cmd_pool[cmd_count].option = option;
   cmd_pool[cmd_count].call = call;
   cmd_count++;
   if(cmd_count>CMD_MAX)
      cmd_count=0;
   return 1;
}
int cmd_idx(const TCHAR* cmdname) {
   int i;
   for(i=0;i<cmd_count;i++) {
      if(_tcsicmp(cmdname,cmd_pool[i].name)==0)
         return i;
   }
   return -1;
}

int cmd_exec(int idx,int argc,TCHAR** argv) {
   return cmd_pool[idx].call(argc,argv);
}
int cmd_list() {
   int i;
   for(i=0;i<cmd_count;i++) {
       DEBUG_PRINT(TEXT("[%d]"),i+1);
       _tprintf(TEXT("    %-10s:    %s\n"),cmd_pool[i].name,cmd_pool[i].desc);
   }
   return i;
}
CMDINFO *cmd_info(cmdidx) {
   return &cmd_pool[cmdidx];
}

int cmd_init() {
   CMD_INIT(help);
   return 1;
}

