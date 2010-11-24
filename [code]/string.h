/*!
	\file string.h
*/
#include <stdlib.h>
#include <malloc.h>
#include <tchar.h>
#include <string.h>

#ifndef MAXSTRLEN
#define MAXSTRLEN 32767
#endif

#ifndef NIL
#define NIL _T('\0')
#endif

extern int strsplit(_TCHAR *s,_TCHAR c,_TCHAR **vOut);
extern _TCHAR *strdelc(_TCHAR *sIn,_TCHAR c,_TCHAR *sOut);
