/*
 * =====================================================================================
 *
 *       Filename:  url.c
 *
 *    Description:  url utility
 *
 *        Version:  1.0
 *        Created:  03/27/2007 12:51:33 AM CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 *
 * =====================================================================================
 */

#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include "url.h"

#ifdef MYPLACE_DEBUG
    #include "debug.h"
#endif

URL* newURL()
{
    URL* mURL =  (URL*)malloc(sizeof(URL));
    mURL->schema=NULL;
    mURL->domain=NULL;
    mURL->path=NULL;
    mURL->file=NULL;
    return mURL;
}

void freeURL(URL* mURL)
{
    FREEMEM(mURL->schema);
    FREEMEM(mURL->domain);
    FREEMEM(mURL->path);
    FREEMEM(mURL->file);
    free(mURL);
}

URL* parseurl(char* url)
{
    int l=0;    
    char* p=NULL;
    URL* mURL = newURL();

    p=strstr(url,PROTOCOL_FLAG);
    if (p!=NULL) {
        l=(int)(p-url);
        mURL->schema=(char*)malloc(l+1);
        memcpy(mURL->schema,url,l);
        mURL->schema[l]='\0';
        url=p+strlen(PROTOCOL_FLAG);
    }
    else
        mURL->schema=strdup("http");

    p=strchr(url,'/');
    if (p!=NULL) {
        l=(int)(p-url);
        mURL->domain=(char*)malloc(l+1);
        memcpy(mURL->domain,url,l);
        mURL->domain[l]='\0';
        url=p;
    }
    else { 
        mURL->domain=strdup(url);
        mURL->path=strdup("/");
        return mURL;
    }
    
    p=strrchr(url,'/');
    if (p!=NULL) {
        l=(int)(p-url);
        mURL->path=(char*)malloc(l+2);
        memcpy(mURL->path,url,l+1);
        url=p+1;
    }
    else
        mURL->path=strdup("/");
    
    mURL->file=strdup(url);
    return mURL;
}

char* getfullurl(char* rurl,char* burl)
{
    char* fullurl;//=(char*)malloc(strlen(rurl)+strlen(burl)+1);
    char* p;
    URL* baseURL;

    if (rurl==NULL) return NULL;
    if (burl==NULL) return strdup(rurl);

    
    p=strstr(rurl,PROTOCOL_FLAG);
    if (p!=NULL)
        return strdup(rurl);
    

    baseURL=parseurl(burl);

    if (*rurl=='/'){ 
        fullurl=(char*)malloc(strlen(baseURL->schema)+strlen(baseURL->domain)+strlen(rurl)+4);
        sprintf(fullurl,"%s://%s%s",baseURL->schema,baseURL->domain,rurl);
    }
    else {
        fullurl=(char*)malloc(strlen(baseURL->schema)+strlen(baseURL->domain)+strlen(baseURL->path)+strlen(rurl)+4);
        sprintf(fullurl,"%s://%s%s%s",baseURL->schema,baseURL->domain,baseURL->path,rurl);
    }


    freeURL(baseURL);

    return fullurl;
}


#ifdef MYPLACE_DEBUG
int main()
{
    URL* test;
    
    char* url="www.google.com/afds/werer/dfa";
    test=parseurl(url);
    DEBUG_PRINT_STR(test->schema);
    DEBUG_PRINT_STR(test->domain);
    DEBUG_PRINT_STR(test->path);
    DEBUG_PRINT_STR(test->file);
    freeURL(test);
    char* fullurl=getfullurl("/index.html",url);
    DEBUG_PRINT_STR(fullurl);
    free(fullurl);
    return 0;
}
#endif
