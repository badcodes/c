#ifndef ZCMD_ZCMD_HEADER
#define ZCMD_ZCMD_HEADER
    #include "version.h"
    #include "config.h"
    #include "xrzlib\list.h"

    int zcmd_process(int argc,TCHAR** argv);

    int quote_onneed(TCHAR* dst,const TCHAR* src);

    int zcmd_shell(int argc,TCHAR** argv);

    int zcmd_process_line(const TCHAR* cmdline);
    #define zcmd_shell_line(LINE) system((LINE));

    int zcmd_process_list(list arglist);
    int zcmd_shell_list(list arglist);


#endif
