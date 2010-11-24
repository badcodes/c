 /*
 * =====================================================================================
 * 
 *       Filename:  readkey.h
 * 
 *    Description:  readkey
 * 
 *        Version:  1.0
 *        Created:  01/07/2007 02:03:06 AM HKT
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 * 
 * =====================================================================================
 */
#ifndef DLMAN_INCLUDE_READKEY
#define DLMAN_INCLUDE_READKEY

#include "config.h"

#ifdef PROCESS_INPUT
int inputavail();
int readkey();
char* readline();
#endif

#endif
