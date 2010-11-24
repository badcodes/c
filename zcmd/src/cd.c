#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
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

DEFINE_CMD_MAIN(zcd,int argc,char** argv) {
    if(argc < 2) {
        char* pwd=(char*)malloc(sizeof(char)*(MAXPATH+1));
        getcwd(pwd,MAXPATH);
        printf("%s",pwd);
        free(pwd);
    }
    else {
        int l;
        char* path = argv[1];
        l = strlen(path);
        if(l>1 && path[1]==':') {
            int drive = 2 + toupper(path[0]) - 'C';
            setdisk(drive);
        }
        chdir(path);
    }
    return 0;
}


