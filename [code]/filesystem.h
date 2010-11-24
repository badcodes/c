#ifndef _LIN_INC_FILESYSTEM
#define _LIN_INC_FILESYSTEM

#ifndef intptr_t
#define intptr_t int
#endif

#ifdef WINDOWS
#include <tchar.h>
#else
#include "tchar.h"
#endif

extern _TCHAR* buildpath(_TCHAR *cmbpath,const TCHAR * path1,const TCHAR* path2);
extern int findfile(const TCHAR* path,unsigned attrib,TCHAR *vdata[],int maxget) ;
extern int countfile(const TCHAR* path,unsigned attrib);
extern  _TCHAR *parentDir(const _TCHAR *fullpath);
#endif


