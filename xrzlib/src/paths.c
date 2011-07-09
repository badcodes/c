#include <string.h>
#include <tchar.h>
#ifdef _WINDOWS
	#include <windows.h>
	#include "wdebug.h"
#else
	#include "debug.h"
#endif


TCHAR*  get_parent_dir(const TCHAR*  filename) {
	TCHAR*  result;
	TCHAR* lastslash;
	result = _tcsdup(filename);
	lastslash = _tcsrchr(result,TEXT('\\'));
	if(lastslash == NULL) {
		lastslash = _tcsrchr(result,TEXT('/'));
	}
	if(lastslash == NULL) {
		return NULL;
	}
	else {
		*lastslash = TEXT('\0');
		RETURN(result);
	}
}
TCHAR*  build_path(const TCHAR*  first,const TCHAR*  second) {
	if(first == NULL) {
		RETURN(_tcsdup(second));
	}
	else if(second == NULL) {
		RETURN (_tcsdup(first));
	}
	else {
		TCHAR*  result;
		int lenf = _tcslen(first);
		int pos = 0;
		result = (TCHAR* ) malloc(_MAX_PATH*sizeof(TCHAR));
		if(first[lenf-1] == TEXT('\\') || first[lenf-1] == TEXT('/')) {
			_tcscpy(result,first);
		}
		else {
			_tcscpy(result,first);
			result[lenf] = TEXT('\\');
			lenf++;
			result[lenf] = TEXT('\0');
		}
		while(second[pos] == TEXT('\\') || second[pos] == TEXT('/')) {
			pos++;
		}
		while(second[pos] != TEXT('\0')) {
			result[lenf] = second[pos];
			lenf++;
			pos++;
		}

		result[lenf] = TEXT('\0');
		RETURN(result);
	}
}