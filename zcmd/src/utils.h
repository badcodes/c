
#ifndef ZCMD_UTILS_INCLUDE
#define ZCMD_UTILS_INCLUDE

    #include <stdio.h>
    #include "xrzlib\list.h"
    #define MAX_ARG_LENGTH 256
    #define MAX_ARGC 24

    char* unescape(const char* src,char* dst);
    int printarg(const char* msghd,int argc,char** argv);
    int fgetline(char* s,int n,FILE* stream);
    int break_cmdline(char** argv,const char* s,int max);
    int free_argv(int argc,char** argv);
    void argv_free(int argc,char** argv);
    char** list_to_argv(char** argv,list lst);
    list list_break_word(const char* line);
    void list_free(list lst);
    void list_free_all(list lst);

    char* unquote(char* src);
    char* quote(char* dst,const char* src);
    void unescape_argv(int argc,char** argv);

   #define DEFULAT_OPTSTRING "  -h\tDisplay this text\n"
   #define MAIN_WITH_HELP(NAME) int main(int argc,char** argv) {\
        char* myopt;\
        cmd_init();\
        REGISTER_CMD(NAME);\
        if(argc>1 && strcmp(argv[1],"-h")==0) {\
                return display_help_ex( NAME ## _NAME );\
         }\
         else {\
                return NAME ## _PROCESS (argc,argv);\
         }\
       }

   #define MAIN_WITHOUT_HELP(NAME) int main(int argc,char** argv) {\
                return NAME ## _PROCESS (argc,argv);\
         }

#endif

/*

*/
