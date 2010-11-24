//#include <io.h>
#include <string.h>
#include <stdlib.h>
#include "filesystem.h"
#ifdef WINDOWS
#include <tchar.h>
#else
#include "tchar.h"
#endif

int findfile(const _TCHAR* path,unsigned attrib,_TCHAR *vdata[],int maxget) 
{
	struct _tfinddata_t c_file;
	intptr_t hfile;
	int count=0;

	hfile=_tfindfirst((const _TCHAR*)path,&c_file);
	if (hfile==-1l) return 0l;
	do {
		if  ( (c_file.attrib & attrib) && \
		_tcscmp(c_file.name ,_T(".")) && \
		_tcscmp(c_file.name,_T(".."))) {
			if (maxget>0 && count>maxget) return count;
			vdata[count]=_tcsdup(c_file.name);
			count++;
		}
	} while (_tfindnext(hfile,&c_file)==0);

	_findclose(hfile);
	return count;
}

int countfile(const _TCHAR* path,unsigned attrib) 
{
	struct _tfinddata_t c_file;
	intptr_t hfile;
	int count=0;

	hfile=_tfindfirst((const _TCHAR*)path,&c_file);
	if (hfile==-1l) return 0l;
	do {
		if  ( (c_file.attrib & attrib) && \
		_tcscmp(c_file.name ,_T(".")) && \
		_tcscmp(c_file.name,_T(".."))) {
			count++;
		}
	} while (_tfindnext(hfile,&c_file)==0);

	_findclose(hfile);
	return count;
}

_TCHAR* buildpath(_TCHAR *path,const _TCHAR * path1,const _TCHAR* path2)
{
	size_t pos;
	_TCHAR *aux1,*aux2;
	aux1=(_TCHAR *)path1;
	aux2=(_TCHAR *)path2;
	pos=_tcslen(aux1);
	if (aux1[pos-1]==_T('\\')) aux1[pos-1]=_T('\0');
	if (aux2[0]==_T('\\')) aux2++;
	path=_tcscpy(path,aux1);
	path=_tcscat(path,_T("\\"));
	path=_tcscat(path,(const _TCHAR*)aux2);
	return path;
}

_TCHAR *parentDir(const _TCHAR *fullpath)
{
	size_t pos;
	_TCHAR *s=(_TCHAR *)malloc(sizeof(_TCHAR)*_MAX_PATH);
	pos=(_tcsrchr(fullpath,_T('\\'))-fullpath);
	if (pos<1) return NULL;
	strncpy(s,fullpath,pos);
	*(s+pos+1)=_T('\0');
	return s;
}
