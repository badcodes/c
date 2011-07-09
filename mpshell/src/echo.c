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

DEFINE_CMD_MAIN(xecho,int argc,TCHAR** argv) {
   int i=0;
   unescape_argv(argc-1,argv+1);
   for(i=1;i<argc;i++) {
      _tprintf((i!=argc-1 ? TEXT("%s ") : TEXT("%s")),(argv[i]));
   }
   return 0;
}




