#include <tchar.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WINDOWS
	#include <windows.h>
	#include "wdebug.h"
#else
	#include "debug.h"
#endif

#ifdef __cplusplus
extern "C" {  
#endif	

//Declare C functions here
int  opt_get_word(const TCHAR* source, TCHAR** dgot, TCHAR** dremain) {
	const TCHAR* remain;
	TCHAR* got;
	TCHAR* pgot; 
	TCHAR match;
	int pos = 0;
	int findnext = 0;
	got = (TCHAR*)malloc(_tcslen(source)*sizeof(TCHAR)+1);
	pgot = got;
	match = _TEXT(' ');
//	DEBUG_PRINT(TEXT("source = %s\n"),source);
	while(source[pos]  != _TEXT('\0') && _istspace(source[pos])) {
					pos++;
	}
	if(source[pos] == _TEXT('\0')) {
		*got = 0;
		remain = source;
		return 0;
	}
	while(source[pos] != _TEXT('\0')) {
		if(!findnext) {
			if(source[pos] == _TEXT('"')) {
				match = _TEXT('"');
				pos++;
			}
			else if(source[pos] == _TEXT('\'')) {
				match = _TEXT('\'');
				pos++;
			}
			else {
				match = _TEXT(' ');
			}
			findnext = 1;
		}
		else if(match == _TEXT(' ') && _istspace(source[pos])) {
					*got = _TEXT('\0');
					got++;
					pos++;
					break;
		}
		else if(source[pos] == match) {
					*got = _TEXT('\0');
					got++;
					pos++;
				break;
		}
		*got = source[pos];
		got++;
		pos++;
	}
	while(source[pos]  != _TEXT('\0') && _istspace(source[pos])) {
		pos++;
	}
	*got = _TEXT('\0');
	got = pgot;
	remain = &source[pos];
	*dgot = got;
	*dremain = (TCHAR*)remain;
	//DEBUG_PRINT3(TEXT("[SOURCE]:\n%s\n[GOT]:\n%s\n[REMAIN]:\n%s\n"),source,got,remain);

	return 1;
}

#ifdef __cplusplus
}
#endif



