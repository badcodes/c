#include <windows.h>
#include <shellapi.h>
#define C_ZERO '\0'
/*#define VBPATH "C:\\Program Files\\Microsoft Visual Studio\\VB98\\VB6.EXE"*/
char *parentDir(const char *fullpath);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
	if (*szCmdLine!=C_ZERO) 
/*		ShellExecute(0,"open",VBPATH,NULL,parentDir(VBPATH),SW_SHOW);
	else*/
		ShellExecute(0,"open",szCmdLine,NULL,parentDir(szCmdLine),SW_SHOW);
	return 0;
}

char *parentDir(const char *fullpath)
{
	size_t pos;
	char *s=(char *)malloc(sizeof(char)*_MAX_PATH);
	pos=(strrchr(fullpath,'\\')-fullpath);
	if (pos<1) return NULL;
	strncpy(s,fullpath,pos);
	*(s+pos+1)=C_ZERO;
	return s;
}