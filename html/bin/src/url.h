/*
 * =====================================================================================
 * 
 *       Filename:  url.h
 * 
 *    Description:  
 * 
 *        Version:  1.0
 *        Created:  03/27/2007 12:54:13 AM CST
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  xiaoranzzz (xrLiN), xiaoranzzz@gmail.com
 *        Company:  MYPLACE
 * 
 * =====================================================================================
 */
#ifndef MYPLACE_HTML_HEADER_URL
#define MYPLACE_HTML_HEADER_URL

#define PROTOCOL_FLAG "://"
#define FREEMEM(m) if(m!=NULL) free(m)

typedef struct s_url
{   
    char* schema;
    char* domain;
    char* path;
    char* file;
} URL;

URL* newURL();
URL* parseurl(char* url);
void freeURL(URL* mURL);
char* getfullurl(char* rurl,char* burl);

#endif



