#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xrzlib\debug.h"
#include "cmd.h"
#include "utils.h"
#include "hstart.h"


#define PRINTF_DEBUG_PRINT(FMT,STR) \
       DEBUG_PRINT("%s\n","_tprintf(" #FMT "," #STR ")")
       // #FMT "=" %s," #STR "=%s\n",FMT,STR);

DEFINE_CMD_INFO(
        hstart,"1.0","start program invisiably",
        "[command [arguments...]]",NULL
)

DEFINE_CMD_MAIN(hstart,int argc,TCHAR** argv) {
    TCHAR *fmtbuf,*fmt,*saved;
    int myargc,match;
    TCHAR c;
    unescape_argv(argc-1,argv+1);
    DEBUG_PRINTARG("hstart called with",argc,argv);
    if(argc == 1)
        return 0;
    return 0;
}

