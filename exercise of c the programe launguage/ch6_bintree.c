#include <malloc.h>
#include "ch6_bintree.h"           
pnode newnode(void *value)
{
     pnode tmp=(pnode)malloc(sizeof(struct node));
     if (tmp==NULL) return NULL;
     tmp->p=value;
     tmp->left=NULL;
     tmp->right=NULL;
     return tmp;
 }
pnode addnode(
     pnode rootnode,
     void *value,
     int (*comp)(void*,void*)
     )
{
     int r;
     if (rootnode==NULL){ 
        rootnode=newnode(value);
        return rootnode;
        }
     r=(*comp)(value,rootnode->p);
     if (r==0)
        rootnode->p=value;
     else if (r<0)
          rootnode->left=addnode(rootnode->left,value,comp);
     else
          rootnode->right=addnode(rootnode->right,value,comp);
     return rootnode;           
 }
void prtree(pnode rootnode,void (*pnt)(void*))
{
     if (rootnode!=NULL){
        prtree(rootnode->left,pnt);
        (*pnt)(rootnode->p);
        prtree(rootnode->right,pnt);
     }
}
//TEST
#include <string.h>
#include <stdio.h>

struct emp {
       char *name;
       int num;
       };
typedef struct emp *pe;       
typedef int (*PCMP)(void *,void *);

pe newpe(char *name,int num)
{
   pe tmp;
   tmp=(pe)malloc(sizeof(struct emp));
   tmp->name=name;
   tmp->num=num;
   return tmp;             
}
int pecmp(pe e1,pe e2)
{
    if (e1->num==e2->num)
       return 0;
    else if (e1->num>e2->num)
       return 1;
    else
       return -1;      
}
void pnt(pe e)
{
     printf("%d:%s\n",e->num,e->name);
     return;
 }
int ch6_bintree()
{  
    pnode rootnode=NULL;
    rootnode=addnode(rootnode,newpe("lin",4),(PCMP)pecmp);
    addnode(rootnode,newpe("abc",2),(PCMP)pecmp);
    addnode(rootnode,newpe("ok",1),(PCMP)pecmp);
    prtree(rootnode,(void (*)(void*))pnt);
    system("PAUSE");
    return 0;
}
