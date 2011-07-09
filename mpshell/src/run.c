#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "cmd.h"
#include "debug.h"
#include "utils.h"
#include "run.h"

DEFINE_CMD_INFO(
    run,
    "1.0",
    "program loader",
    "[options] cmd arguments..." \
        "\n  -w (directory) Set working directory",
    NULL
)

DEFINE_CMD_MAIN(run,int argc,TCHAR** argv) {
	printarg(TEXT("[run]"),argc,argv);
    return 0;
}
