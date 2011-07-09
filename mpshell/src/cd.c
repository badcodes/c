#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "config.h"
#include "xrzlib\os.h"
#include "cmd.h"
#include "cd.h"
#include "xrzlib\debug.h"
#include "utils.h"

DEFINE_CMD_INFO(
    zcd,
    "1.0",
    "Enchanced chdir,change drive as well",
    "[PATH]",
    NULL
)

DEFINE_CMD_MAIN(zcd,int argc,TCHAR** argv) {
    if(argc < 2) {
        TCHAR* pwd=(TCHAR*)malloc(sizeof(TCHAR)*(MAXPATH+1));
        _tgetcwd(pwd,MAXPATH);
        _tprintf(TEXT("%s"),pwd);
        free(pwd);
    }
    else {
        int l;
        TCHAR* path = argv[1];
        l = _tcslen(path);
        if(l>1 && path[1]==':') {
            int drive = 2 + toupper(path[0]) - 'C';
            setdisk(drive);
        }
        _tchdir(path);
    }
    return 0;
}


