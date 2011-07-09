#ifndef ZZZ_HELP_HEADER
#define ZZZ_HELP_HEADER
   #include "cmd.h"
   DECLARE_CMD(help)
   #define DEFAULT_OPTION "    -h\tDisplay this text\n"

   int display_help(const TCHAR* cmdname);
   int display_help_ex(const TCHAR* cmdname);
#endif

