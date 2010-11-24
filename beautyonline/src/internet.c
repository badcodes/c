/***************************************************************************
 *            internet.c
 *
 *  Tue Dec 19 16:08:20 2006
 *  Copyright  2006  xiaoranzzz
 *  <xiaoranzzz@Fedora.MYPLACE>
 ****************************************************************************/

#include "internet.h"

CURL* curlHnd;

int init_internet() {
	CURLcode result;
	result=curl_global_init(CURL_GLOBAL_ALL);
	if (result!=0)
		return -1;
	curlHnd=curl_easy_init();
	//~ if (result!=0)
		//~ return -1;
}

int free_internet() {
	if (curlHnd != NULL) curl_easy_cleanup(curlHnd);
	curl_global_cleanup();
	return 0;
}

int download(char* uri,FILE* stream) {
	curl_easy_setopt(curlHnd,CURLOPT_VERBOSE,1);
	curl_easy_setopt(curlHnd,CURLOPT_URL,uri);
	curl_easy_setopt(curlHnd,CURLOPT_WRITEDATA,stream);
	curl_easy_setopt(curlHnd,CURLOPT_TIMEOUT,240);
	return curl_easy_perform(curlHnd);
}
