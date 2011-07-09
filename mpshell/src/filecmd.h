#ifndef ZCMD_FILECMD_HEADER
#define ZCMD_FILECMD_HEADER
    #include "cmd.h"

    DECLARE_CMD(filecmd)

    int process_line(const TCHAR* appname,const TCHAR* line);
    int getline(TCHAR* s,int n,FILE* stream);
    int split(TCHAR** dst,const TCHAR* s,int max);
#endif

