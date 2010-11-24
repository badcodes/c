#ifndef ZCMD_FILECMD_HEADER
#define ZCMD_FILECMD_HEADER
    #include "cmd.h"

    DECLARE_CMD(filecmd)

    int process_line(const char* appname,const char* line);
    int getline(char* s,int n,FILE* stream);
    int split(char** dst,const char* s,int max);
#endif

