#ifndef _INTERNET_H
#define _INTERNET_H

#ifdef __cplusplus
extern "C"
{
#endif



#ifdef __cplusplus
}
#endif

#include <curl/curl.h>

int init_internet();
int free_internet();
int download(char* uri,FILE* stream);


//int download(gchar* uri)

#endif /* _INTERNET_H */

