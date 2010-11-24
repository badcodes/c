/*
 * =====================================================================================
 * 
 *       Filename:  batchman.h
 * 
 *    Description:  batchman
 * 
 *        Version:  1.0
 *        Created:  01/07/2007 06:10:15 AM HKT
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 * 
 * =====================================================================================
 */

#ifndef DLMAN_INCLUDE_DLMAN
#define DLMAN_INCLUDE_DLMAN

#define APPNAME "BatchMan"
#define TASKFILE "batchman.task"
#define HISTORYFILE "batchman.history"
#define TASKHANDLER "echo"
#define TASKINCOME "batchman.income"
#define APPMSG(...) printf("["APPNAME"] " __VA_ARGS__)

//char* g_working_dir;

#endif
