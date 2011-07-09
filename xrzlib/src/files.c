#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include "files.h"

int file_exists(const TCHAR* filename)
{
	FILE* fh;
	fh = _tfopen(filename,_TEXT("r"));
	if(fh == NULL) {
		return 0;
	}
	else {
		fclose(fh);
		return 1;
	}
}

TCHAR* get_current_dir()
{
	TCHAR* result = (TCHAR*)malloc(sizeof(TCHAR)*_MAX_PATH);
	if(_tgetcwd(result,_MAX_PATH)) {
		return result;
	}
	else {
		free(result);
		return NULL;
	}
}

int directory_exists(const TCHAR* filename)
{
	TCHAR* save = get_current_dir();
	if(_tchdir(filename)) {
		_tchdir(save);
		free(save);
		return 1;
	}
	else {
		return 0;
	}
}