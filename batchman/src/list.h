/*
 * =====================================================================================
 * 
 *       Filename:  list.h
 * 
 *    Description:  General link List
 * 
 *        Version:  1.0
 *        Created:  01/06/2007 04:55:54 AM HKT
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 * 
 * =====================================================================================
 */
#ifndef DLMAN_INCLUDE_LIST
#define DLMAN_INCLUDE_LIST
typedef char *DATATYPE;
struct LIST {
    DATATYPE data;
    struct LIST *next;
};
typedef struct LIST List;

#endif
