/*
 * =====================================================================================
 * 
 *       Filename:  queue.h
 * 
 *    Description:  General Queue 
 * 
 *        Version:  1.0
 *        Created:  01/06/2007 04:58:23 AM HKT
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 * 
 * =====================================================================================
 */
#ifndef DLMAN_INCLUDE_QUEUE
#define DLMAN_INCLUDE_QUEUE

#include "list.h"

typedef int bool;

struct QUEUE {
    int length;
    List *top;
    List *bottom;
};
typedef struct QUEUE Queue;

bool queue_in(DATATYPE in, Queue * s);
DATATYPE queue_out(Queue * s);
bool queue_is_empty(Queue * s);
void queue_clean(Queue * s);
int queue_length(Queue * s);
void queue_init(Queue * q);

#endif
