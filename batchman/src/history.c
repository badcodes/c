/*
 * =====================================================================================
 * 
 *       Filename:  history.c
 * 
 *    Description:  download history
 * 
 *        Version:  1.0
 *        Created:  01/07/2007 01:11:32 AM HKT
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 * 
 * =====================================================================================
 */
#include "config.h"
#include "history.h"

int remember(const char *url, FILE * record)
{
    if (record == NULL)
	return 0;
    return (fputs(url, record) >= 0);
}
