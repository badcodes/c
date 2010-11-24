#include <stdlib.h>
#include "list.h"
#include "debug.h"

list list_new(elem data) {
    list lst = (list)malloc(sizeof(ListNode));
    lst->data = data;
    lst->next = NULL;
    return lst;
}
list list_append(list dst,elem data) {
    if(dst == NULL) {
        list head = list_new(data);
        return head;                            
    } 
    else {
        list last = list_last(dst);
        last->next = list_new(data);
        return dst;
    }
}
list list_insert(list* dst,elem data) {
    list head = list_new(data);
    head->next = *dst;
    *dst = head;
    return *dst;
}
list list_last(list dst) {
    list last = dst;
    if(!last)
        return NULL;
    while(last->next != NULL)
        last = last->next;
    return last;
}
int list_length(list dst) {
    int l=0;
    while(dst!=NULL) {
        l=l+1;
        dst = dst->next;
    }
    return l;
}
list list_at(list dst,int pos) {
    list p=dst;
    if(p == NULL)
        return NULL;
    else if(pos<0)
        return NULL;
    else if(pos == 0)
        return p;
    else {
        while(--pos>0) {
            p = p->next;
            if(p == NULL) break;
        }
        return p;
    }
    
}

