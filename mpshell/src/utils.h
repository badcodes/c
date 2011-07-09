
#ifndef ZCMD_UTILS_INCLUDE
#define ZCMD_UTILS_INCLUDE
    #include "config.h"
    #include <stdio.h>
    #include "xrzlib\list.h"
    #define MAX_ARG_LENGTH 256
    #define MAX_ARGC 24

    TCHAR* unescape(const TCHAR* src,TCHAR* dst);
    int printarg(const TCHAR* msghd,int argc,TCHAR** argv);
    int fgetline(TCHAR* s,int n,FILE* stream);
    int break_cmdline(TCHAR** argv,const TCHAR* s,int max);
    int free_argv(int argc,TCHAR** argv);
    void argv_free(int argc,TCHAR** argv);
    TCHAR** list_to_argv(TCHAR** argv,list lst);
    list list_break_word(const TCHAR* line);
    void list_free(list lst);
    void list_free_all(list lst);

    TCHAR* unquote(TCHAR* src);
    TCHAR* quote(TCHAR* dst,const TCHAR* src);
    void unescape_argv(int argc,TCHAR** argv);

   #define DEFULAT_OPTSTRING "  -h\tDisplay this text\n"
   #define MAIN_WITH_HELP(NAME) int main(int argc,TCHAR** argv) {\
        TCHAR* myopt;\
        cmd_init();\
        REGISTER_CMD(NAME);\
        if(argc>1 && _tcscmp(argv[1],"-h")==0) {\
                return display_help_ex( NAME ## _NAME );\
         }\
         else {\
                return NAME ## _PROCESS (argc,argv);\
         }\
       }

   #define MAIN_WITHOUT_HELP(NAME) int main(int argc,TCHAR** argv) {\
                return NAME ## _PROCESS (argc,argv);\
         }

#endif

/*

*/
