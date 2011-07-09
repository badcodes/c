#include <ctype.h>
#include <stdlib.h>
#include "cmd.h"
#include "exit.h"

DEFINE_CMD_INFO(
    exit,
    "1.0",
    "Exit the programe",
    "[number]",
    NULL
)

DEFINE_CMD_MAIN(exit,int argc,TCHAR** argv) {
    if(argc == 1) {
        exit(0);
    }
    else {
        exit(_ttoi(argv[1]));
    }
    return 1;
}

