#include <stdio.h>
#include <stdlib.h>
#include "cmd.h"
#include "utils.h"
#include "echo.h"

DEFINE_CMD_INFO(
    xecho,
    "1.0",
    "output what i got, one by one, no less, no more",
    "args...",
    NULL
)

DEFINE_CMD_MAIN(xecho,int argc,char** argv) {
   int i=0;
   unescape_argv(argc-1,argv+1);
   for(i=1;i<argc;i++) {
      printf((i!=argc-1 ? "%s " : "%s"),(argv[i]));
   }
   return 0;
}




