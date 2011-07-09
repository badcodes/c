#ifndef XIAORANZZZ_DEBUG_HEADER
#define XIAORANZZZ_DEBUG_HEADER

#ifndef NDEBUG
    #ifndef APPNAME
        #define APPNAME TEXT("DEBUG")
    #endif
	#define RETURN(X) {MessageBox(NULL,(X),TEXT(#X),MB_OK);return (X);}
    #define DEBUG_PRINT(FMT,STR) \
		{ \
			TCHAR debug_msg[2056]; \
			_stprintf(debug_msg,TEXT("[%s]\n") FMT,APPNAME,STR); \
			MessageBox(NULL,debug_msg,APPNAME,MB_ICONINFORMATION | MB_OK); \
		} 
	#define DEBUG_PRINT3(FMT,STR1,STR2,STR3) \
		{ \
			TCHAR debug_msg[2056]; \
			_stprintf(debug_msg,TEXT("[%s]\n") FMT,APPNAME,STR1,STR2,STR3); \
			MessageBox(NULL,debug_msg,APPNAME,MB_ICONINFORMATION | MB_OK); \
		} 
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

#else
	#define RETURN(X) return X;
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
