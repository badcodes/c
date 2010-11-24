#ifndef XIAORANZZZ_OS_HEADER
#define XIAORANZZZ_OS_HEADER

#ifdef __WATCOMC__
    #undef _HAVE_DIRECT_H
    #define _HAVE_DIRECT_H
#endif
#ifdef WIN32
    #undef _HAVE_DIRECT_H
    #define _HAVE_DIRECT_H
#endif

#ifdef _HAVE_DIRECT_H
	#include <direct.h>
	#define MAXPATH _MAX_PATH
	#define getcwd _getcwd
	#define stricmp _stricmp
	#define setdisk _chdrive
	#define strdup _strdup
#else 
	#include <dir.h>
#endif

#endif

