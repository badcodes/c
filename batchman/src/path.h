/*
 * =====================================================================================
 * 
 *       Filename:  path.h
 * 
 *    Description:  path related functions
 * 
 *        Version:  1.0
 *        Created:  01/08/2007 08:56:34 PM HKT
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 * 
 * =====================================================================================
 */

#ifndef MYPLACE_INCLUDE_FILESYSTEM_PATH
#define MYPLACE_INCLUDE_FILESYSTEM_PATH

char *dirname(const char *filename);
char *basename(const char *filename);
char *buildpath(char *part1, char *part2);

#endif
