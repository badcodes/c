#ifndef XRZLIB_LIST_HEADER
#define XRZLIB_LIST_HEADER
    typedef void ListElement;
    typedef ListElement* elem;
    struct TListNode {
        struct TListNode* next;
        elem data;
    };
    typedef struct TListNode ListNode;
    typedef ListNode* list;
    list list_new(elem data);
    list list_append(list dst,elem data);
    list list_insert(list* dst,elem data);
    list list_last(list dst);
    int list_length(list dst);
    list list_at(list dst,int pos);
#endif
