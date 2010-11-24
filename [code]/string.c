/*!
	\file string.c
*/
#include "string.h"

int strsplit(_TCHAR *s,_TCHAR c,_TCHAR **vOut)
{
	size_t i;
	size_t l=_tcslen(s);
	int count=0;
	_TCHAR cc;
	_TCHAR *tmp=(_TCHAR *)malloc(MAXSTRLEN*sizeof(_TCHAR));
	_TCHAR *aux=tmp;
	for (i=0;i<l;i++){
		cc=*s++;
		if (cc!=c)
			*(aux++)=cc;
		else{
			*(aux)=NIL;
			*(vOut++)=_tcsdup(tmp);
			aux=tmp;
			count++;
		}
	}
	if(l>0 && cc!=c) {
	*(aux)=NIL;
	*(vOut++)=_tcsdup(tmp);
	count++;
	}
	return count;
}
_TCHAR *strdelc(_TCHAR *sIn,_TCHAR c,_TCHAR *sOut)
{
	_TCHAR cc;
	_TCHAR *aux=sOut;
	if (*sIn==NIL) return NULL;
	while(*sIn){
		cc=*sIn++;
		if(cc!=c) 
			*sOut++=cc;
	}
	*sOut=NIL;
	return aux;
}
