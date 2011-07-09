#ifndef XIAORANZZZ_DEBUG_HEADER
#define XIAORANZZZ_DEBUG_HEADER

#ifndef NDEBUG

    #define DEBUG_PRINT(FMT,STR) \
        _tprintf(TEXT("%s:") FMT,APPNAME,STR);
    #define DEBUG_PRINTS(X) \
        DEBUG_PRINT(TEXT("%s\n"),X)
    #define DEBUG_PRINTD(X) \
        DEBUG_PRINT(TEXT("%d\n"),X)
    #define DEBUG_PRINTG(X) \
        DEBUG_PRINT(TEXT("%g\n"),X)
    #define DEBUG_PRINT_IF(COND,FMT,STR) \
        if((COND)){DEBUG_PRINT(FMT,STR);}
    #define DEBUG_CODE_BEGIN {
    #define DEBUG_CODE_END   }
    #define DEBUG_PRINT_LOOP(C,V,FMT) \
        {int DLIDX;for(DLIDX=0;DLIDX<(C);DLIDX++) DEBUG_PRINT(FMT,(V)[DLIDX]);}
    #define DEBUG_PRINTARG(APPNAME,argc,argv) \
        printarg(APPNAME,argc,argv);
#else
    #define DEBUG_PRINT_IF(COND,FMT,STR)
    #define DEBUG_PRINT(FMT,STR)
    #define DEBUG_PRINTS(X)
    #define DEBUG_PRINTD(X)
    #define DEBUG_PRINTG(X)
    #define DEBUG_CODE_BEGIN if(0){
    #define DEBUG_CODE_END   }
    #define DEBUG_PRINT_LOOP(C,V,FMT)
    #define DEBUG_PRINTARG

#endif
#endif
