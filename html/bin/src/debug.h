/*
 * =====================================================================================
 * 
 *       Filename:  debug.h
 * 
 *    Description:  
 * 
 *        Version:  1.0
 *        Created:  03/27/2007 05:22:39 PM CST
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 * 
 * =====================================================================================
 */

#ifndef MYPLACE_COMMON_HEADER_DEBUG


#define MYPLACE_COMMON_HEADER_DEBUG

#ifdef MYPLACE_DEBUG

    #include <stdio.h>

    #define DEBUG_PRINT(EXP,TYPE)                           \
        printf(#EXP "\t:  " TYPE "\n",EXP)

    #define DEBUG_PRINT_STR(EXP)                            \
        do {                                                \
        if ((EXP)==NULL)                                    \
            printf(#EXP"\t:  NULL\n");                      \
        else                                                \
            DEBUG_PRINT(EXP,"%s");                          \
        } while (0)             

    #define DEBUG_PRINT_INT(EXP)                            \
        DEBUG_PRINT(EXP,"%d")
#else
    #define DEBUG_PRINT(EXP,TYPE)   ;
    #define DEBUG_PRINT_STR(EXP)    ;
    #define DEBUG_PRINT_INT(EXP)    ;
#endif


#endif
