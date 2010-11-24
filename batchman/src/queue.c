/*
 * =====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  Queue implemention of link list
 *
 *        Version:  1.0
 *        Created:  01/06/2007 05:02:06 AM HKT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */
#include "config.h"
#include "list.h"
#include "queue.h"
#include <stdlib.h>

int queue_length(Queue * q)
{
    return q->length;
}

void queue_init(Queue * q)
{
    q->length = 0;
    q->top = NULL;
    q->bottom = NULL;
}

bool queue_in(DATATYPE what, Queue * s)
{
    List *bottom = s->bottom;
    List *newbot = (List *) malloc(sizeof(List));
    if (newbot == NULL)
	return 0;
    newbot->data = what;
    newbot->next = NULL;
    if (s->length < 1) {
	s->bottom = newbot;
	s->top = newbot;
    } else {
	bottom->next = newbot;
	s->bottom = newbot;
    }
    s->length++;
    return 1;
}

DATATYPE queue_out(Queue * s)
{
    if (s->length < 1)
	return NULL;
    List *cur = s->top;
    DATATYPE result = cur->data;
    s->top = cur->next;
    free(cur);
    if (s->top == NULL)
	s->bottom = NULL;
    s->length--;
    return result;
}

bool queue_is_empty(Queue * s)
{
    return ((s->length) < 1);
}

void queue_clean(Queue * s)
{
    while (s->top != NULL) {
	List *cur = s->top;
	s->top = cur->next;
	free(cur);
    }
    queue_init(s);
}
