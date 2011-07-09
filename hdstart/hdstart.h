#ifndef HDSTART_INCLUDE
    #define HDSTART_INCLUDE
    #define HDSTART_NAME hdstart
    #define HDSTART_NAME_TEXT "hdstart"
    #ifndef STANDALONE
        #define HDSTART_MAIN main
    #else
        #define HDSTART_MAIN APPNAME
    #endif

#endif
