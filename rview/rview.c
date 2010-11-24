#include "..\\[code]\\filesystem.h"
#include "rview.h"
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>
#include <io.h>
#include <time.h>
#include <tchar.h>
#include "..\\[code]\\DEBUG.h"

#ifndef _MAX_FNAME
#define _MAX_FNAME 260
#define _MAX_PATH 260
#endif

typedef struct {
	_TCHAR viewer[_MAX_FNAME];
	_TCHAR workdir[_MAX_FNAME];
	_TCHAR filename[_MAX_FNAME];
} APPINI,*pAPPINI;

int  savecur(pAPPINI status,const _TCHAR * inifile)
{
	FILE *f;
	if ((f=_tfopen(inifile,_T("wb")))==NULL) return(0);
	fwrite((const void*)status,sizeof(*status),1,f);
	if (ferror(f)) {
		fclose(f);
		return(0);
	}
	else {
		fclose(f);
		return(1);
	}
}

int  loadpre(pAPPINI status,const _TCHAR *inifile)
{
	FILE *f;
	if ((f=_tfopen(inifile,_T("rb")))==NULL) return(0);
	fread((void*)status,sizeof(*status),1,f);

	if (ferror(f)) {
		fclose(f);
		return(0);
	}
	else {
		fclose(f);
		return(1);
	}
}

int  getindex(_TCHAR * strlook,_TCHAR *vdata[],int  count)
{
	int  index;
	for(index=0;index<count;index++){
		if (!_tcscmp(strlook,vdata[index]))
			return index;
	}
	return -1;
}

int  _tmain(int  argc,_TCHAR *argv[])
{
	int  viewrnd=0;
	int  viewprev=0;
	int  viewhelp=0;
	int  viewini=0;
	int  viewlist=0;
	int  viewindex=0;
	int  viewnext=0;
	int  fcount=0;
	int  next=1;
	int  reload=0;
	_TCHAR *pageviewer=(_TCHAR*)malloc(_MAX_FNAME);
	_TCHAR *lastdir=(_TCHAR *)malloc(_MAX_PATH);
	_TCHAR *inifile=_tgetenv(_T("APPDATA"));
	_TCHAR *cmdline=(_TCHAR*)malloc(_MAX_FNAME);
	_TCHAR *defaultfile=(_TCHAR*)malloc(_MAX_FNAME);
	_TCHAR *searchfor=(_TCHAR*)malloc(_MAX_FNAME);
	_TCHAR **filelist;
	FILE *appout;
	APPINI status;

	
	defaultfile[0]=NIL;
	pageviewer[0]=NIL;
	lastdir[0]=NIL;
	cmdline[0]=NIL;
	status.viewer[0]=NIL;
	status.workdir[0]=NIL;
	status.filename[0]=NIL;

#ifdef _DEBUG
	appout=_tfopen(_T("text.txt"),_T("wb"));
#else
	appout=stdout;
#endif

	_tcscat(inifile,_T("\\") _T(APPNAME));
	_tmkdir(inifile);
	_tcscat(inifile,_T("\\rview.ini"));

	while (--argc>0)
	{
		/*if argv start at '-')*/
		if (argv[argc][0]==_T('-')) {
			switch(argv[argc][1]) {
			case _T('r'):
			case _T('R'):
				reload=1;
				break;
			case _T('h'):
			case _T('H'):
				viewhelp=1;
				break;
			case _T('v'):
			case _T('V'):
				viewini=1;
				break;
			case _T('l'):
			case _T('L'):
				viewlist=1;
				break;
			case _T('n'):
			case _T('N'):
				viewnext=1;
				break;
			case _T('p'):
			case _T('P'):
				viewprev=1;
				break;
			case _T('z'):
			case _T('Z'):
				viewrnd=1;
				break;
			case _T('c'):
			case _T('C'):
				_tcscpy(pageviewer,(_TCHAR*)&(argv[argc][2]));
				break;
			case _T('f'):
			case _T('F'):
				_tcscpy(defaultfile,(_TCHAR*)&(argv[argc][2]));
				break;
			}
		}
		else 
			viewindex=_ttoi(argv[argc]);
	}

	if (viewhelp==1) {
		fprintf(appout,"%s\n",APPINFO);
		fprintf(appout,"%s\n",APPHELP);
		return 0;
	}


	_tgetcwd(lastdir,_MAX_PATH);

	if (loadpre(&status,inifile)==0) {
		status.workdir[0] =NIL;// _tcscpy(status.workdir,lastdir);
		status.viewer[0]=NIL;//_tcscpy(status.viewer,pageviewer);
		status.filename[0] = NIL;
	}

#ifndef _DEBUG
	_ftprintf(appout,_T("CURLINE:%d\n"),__LINE__);	
	_ftprintf(appout,_T("Viewer:%s\n"),status.viewer);
	_ftprintf(appout,_T("Workdir:%s\n"),status.workdir);
	_ftprintf(appout,_T("Filename:%s\n"),status.filename);
#endif

	if (status.workdir[0]==NIL)
		_tcscpy(status.workdir ,lastdir);
	if (pageviewer[0]!=NIL)
		_tcscpy(status.viewer,pageviewer);
	else if (status.viewer[0]==NIL) 
		_tcscpy(status.viewer,DEFAULTVIEWER);
	
	if (viewini==1) {
		_ftprintf(appout,_T("DefaultViewer:%s\nWorkDir:%s\nLastFile:%s"),status.viewer,status.workdir,status.filename );
		savecur(&status,inifile);
		return 0; 
	}

	if (reload==1) {
		int  c=0;
		fprintf(appout,"原先目录是：");
		_ftprintf(appout,_T("%s\n"), status.workdir);
		fprintf(appout,"当前目录是：");
		_ftprintf(appout,_T("%s\n"),lastdir);
		fprintf(appout,"确定要将当前目录设定为工作目录?(Y/N)");
		//fflush(stdin);
		c=_fgettchar();
		if (c==_T('Y') || c==_T('y')) {
			_tcscpy(status.workdir,lastdir);
			status.filename[0] = NIL;
			savecur(&status,inifile);
			}
	}

	//_chdir(status.workdir);
	//DEBUGStr(status.workdir)
	
	if (defaultfile[0]!=NIL) _tcscpy(status.filename ,defaultfile);
	if (status.filename[0]==NIL) viewnext=1;

/*	DEBUGInt(viewnext);
	DEBUGInt(viewlist);
	DEBUGInt(viewrnd);
	DEBUGInt(viewindex);*/

	if ((viewlist)||(viewrnd)||(viewindex)||(viewnext)) {
		searchfor=buildpath(searchfor,status.workdir,WILDNAME);
#ifdef _DEBUG
		//DEBUGStr(status.workdir);
		_ftprintf(appout,_T("%s\n"),status.workdir);
		_ftprintf(appout,_T("%s\n"),WILDNAME);
		_ftprintf(appout,_T("%s\n"),searchfor);
#endif
		fcount=countfile(searchfor,_A_ARCH);
		if (fcount<=0) return 0;
		filelist=(_TCHAR **)malloc(sizeof(_TCHAR*)*(fcount+1));
		fcount=findfile(searchfor,_A_ARCH,filelist,fcount);
		qsort((void*)filelist,(size_t) fcount,sizeof(_TCHAR*),(int(_cdecl*)(const void*,const void*))&wcscmp);
		
		//viewlist
		if (viewlist==1) {
			int  i;
			for (i=0;i<fcount;i++){
					_ftprintf(appout,_T("[%4d]:%s\n"),i+1,filelist[i]);
			}
			return(0);
		}
		else if (viewindex>0) {     //viewindex
			next=viewindex-1;
		}
		else if (viewrnd==1) {  //viewrnd
			srand( (unsigned)time( NULL ) );
			next= rand( ) % fcount;
		}
		else if (status.filename[0]==NIL)  {
			next=0;
		}
		else if (viewnext==1) {
			next=getindex(status.filename,filelist,fcount)+1;
		}
		else if (viewprev==1) {
			next=getindex(status.filename,filelist,fcount)-1;
		}
		if ((next>fcount-1) || next<0 ) next=0;
		_tcscpy(status.filename ,filelist[next]); 
	}

	/*DEBUGStr(status.viewer )
	DEBUGStr(status.workdir )
	DEBUGStr(status.filename )*/

	savecur(&status,inifile);
	defaultfile=buildpath(defaultfile,status.workdir ,status.filename );
	_stprintf(cmdline,_T("%s \"%s\""),status.viewer,defaultfile);
	//printf("%s:\n",status.filename);

#ifdef _DEBUG
	_ftprintf(appout,_T("Viewer:%s\n"),status.viewer);
	_ftprintf(appout,_T("Workdir:%s\n"),status.workdir);
	_ftprintf(appout,_T("Filename:%s\n"),status.filename);
	_ftprintf(appout,_T("DefaultFile:%s\n"),defaultfile);
	_ftprintf(appout,_T("Cmdline:%s\n"),cmdline);
#endif

	system(cmdline);
	_ftprintf(appout,_T("[%s]\n"),defaultfile);
	
	fclose(appout);
	return (0);
}
