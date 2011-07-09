#include <stdio.h>
#include <stdlib.h>
#include "..\list.h"

int main(int argc,char** argv) {
    int i;
    list argvlist = list_new(NULL);
    list p;
    for(i=0;i<argc;i++) {
        list_append(argvlist,(ListElement*)argv[i]);
        printf("argvlist length:%d\n",list_length(argvlist));
    }
    for(p=argvlist->next;p;p=p->next) {
        printf("%s\n",(char*)(p->data));
    }
    list_free_node(argvlist);
    free(argvlist);
    return 0;
}
