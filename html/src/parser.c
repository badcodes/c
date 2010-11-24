/*
 * =====================================================================================
 *
 *       Filename:  linkparser.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2007 10:20:35 PM CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include "url.h"
#include "debug.h"

#define MAX_VALUE 1024
#define MAX_PROPERTY 1024
#define MAX_TAG 1024

#define NEXT_CHAR(file) fgetc(file)                     

#define IS_LINK_TAG(tag)                                \
    (!strcasecmp(tag,"a") || !strcasecmp(tag,"img") || !strcasecmp(tag,"link"))

#define IS_LINK_PROP(prop)                                   \
    (!strcasecmp(prop,"href") || !strcasecmp(prop,"src"))
    
#define IS_SPACE(c)                                     \
     ((c)==' ' || (c)=='\n' || (c)=='\t')

#define SKIP_WS(file,c) do {                            \
        c=fgetc(file);                                  \
        if (c==EOF) goto END_OF_FILE;                   \
        } while (IS_SPACE(c))                           

#define END_OF_VALUE(c) (                               \
    (quote_non && ( IS_SPACE(c) || c=='>')) ||          \
    (quote_sng && (c=='\'')) ||                         \
    (quote_dbl && (c=='\"')) ||                         \
    (c==EOF)                                            \
    )                                 

int gettag(FILE* html,char* tag);
int getproperty(FILE* html,char* property);    
int getvalue(FILE* html,char* value);


int main(int argc,char** argv) 
{
    char property[MAX_PROPERTY];
    char value[MAX_VALUE];
    char tag[MAX_TAG];

    int do_next=0;
    char* fullurl=NULL;
    char* baseurl=NULL;

    if (argc>1)
        baseurl=argv[1];

    while (gettag(stdin,tag)) {
        if (!IS_LINK_TAG(tag)) continue;

        DEBUG_PRINT_STR(tag);
        while (getproperty(stdin,property)) {
            if (!IS_LINK_PROP(property)) continue;
            DEBUG_PRINT_STR(property);
            do_next=getvalue(stdin,value);
            DEBUG_PRINT_STR(value);     
            if (do_next) {
                fullurl=getfullurl(value,baseurl);
                if (fullurl!=NULL) {
                    printf("%s\n",fullurl);
                    free(fullurl);
                }
            }
        }
    }

    while (0) {
         do_next=getproperty(stdin,property);
//         printf("%s=",property);
         if (!do_next) break;
         do_next=getvalue(stdin,value);
         if (IS_LINK(property)) {
            fullurl=getfullurl(value,baseurl);
            if (fullurl!=NULL) {
                printf("%s\n",fullurl);
                free(fullurl);
            }
         }
         if (!do_next) break;
    }

    return 0;
}
    
int gettag(FILE* html,char* tag)
{
    int c=0;
    char* p=tag;
    int lim=MAX_TAG-2;

    do {
        c=NEXT_CHAR(html);
        if (c==EOF) break;
    } while (c!='<');

    if (c==EOF) goto END_OF_FILE;

    SKIP_WS(html,c);

    do {
        if (lim--<0) break;
        *tag++=c;
        c=NEXT_CHAR(html);
    } while (!IS_SPACE(c));

    *tag='\0';
    return 1;
    END_OF_FILE:
    *tag='\0';
    return 0;

}


int getproperty(FILE* html,char* property)
{
    int c=0;
    char* p=property;
    int outword=0;
    int lim=MAX_PROPERTY-2;

    SKIP_WS(html,c);
    do {
        if (IS_SPACE(c)) {outword=1;SKIP_WS(html,c);}
        if (c==EOF) goto END_OF_FILE;
        if (c=='=') break;
        if (outword) {property=p;outword=0;}
        *property++=c;
        if (lim--<0) break;
        c=NEXT_CHAR(html);
        if (c==EOF) goto END_OF_FILE;
    } while (c!='=');

    *property='\0';
    return 1;

    END_OF_FILE:
    *property='\0';
    return 0;
}


int getvalue(FILE* html,char* value)
{
    int c=0;

    int quote_non=0;
    int quote_sng=0;
    int quote_dbl=0;
    int lim=MAX_VALUE-2;

    SKIP_WS(html,c);
    switch (c)
    {
        case '\"' :
            quote_dbl=1;
            break;
        case '\'' :
            quote_sng=1;
            break;
        default :
            quote_non=1;
            *value++=c;
            if (lim--<0) break;
            break;
    }


    do
    {
        c=NEXT_CHAR(html);

        if (END_OF_VALUE(c))
            break;
        else {
            if (lim--<0) break;
            *value++=c;
            }

    } while (c!=EOF) ;
   
   if (c==EOF) goto END_OF_FILE;

    *value='\0';

   // printf("%s\n",value);
    return 1;

    END_OF_FILE:
    *value='\0';
   // printf("%s\n",value);
    return 0;
}
