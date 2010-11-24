/*!
*\file p.c
*\brief �������ļ�
*\version 0.1
*\author  xrLin
*/
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include "../[code]/string.h"

/*!�ַ�������*/
#define MAX_SEARCH_PATH 10       

/*!�����������չ����*/
#define MAX_SEARCH_EXT 10       

/*!�����в����ָ���*/
#define ARG_PREFIX _T('-')      

/*!��������ǰ�÷�*/
#define ENV_PREFIX _T('%')
      
/*!�ַ��������ָ���*/
#define QUOTE _T(';')           

#ifndef intptr_t
#define intptr_t int
#endif

 /*!�ַ�������*/
#define  LString _TCHAR*       

#define UNQUOTE(expstr) strdelc((expstr),_T('\"'),(expstr))

static LString findin(LString path,LString ext,LString name,unsigned int attrib,unsigned int level);
static LString goforfile(LString filename,unsigned int attrib,int level);

/*!
\brief ������

�������¼��ֲ�����\n
-p[path] ����������·����Ĭ��Ϊ��ǰĿ¼��\n
-n[name] �������������ƣ������Ƿǿ��ַ�����û��Ĭ��ֵ��\n
-e[ext]	 ������������չ����\n
		��������������ֵ���ж��������;�Ÿ�����\n
-t[type]  �������������ͣ�0Ϊ�ļ���1ΪĿ¼��\n
-l[level] ������������ȣ�Ĭ��Ϊ0��
-h ��ʾ����
*/
int _tmain(int argc, LString argv[])
{
	LString path=(LString)malloc(MAX_SEARCH_PATH*_MAX_PATH*sizeof(LString));
	LString name=(LString)malloc(_MAX_FNAME*sizeof(LString));
	LString ext=(LString)malloc(MAX_SEARCH_EXT*_MAX_EXT*sizeof(LString));
	unsigned attrib;
	int t=0;
	int l=0;
	int showhelp=0;
	path[0]=NIL;
	name[0]=NIL;
	ext[0]=NIL;
#ifdef _DEBUG
	{
		int idebug=argc;
		while (--idebug)
			_tprintf(_T("%d:%s\n"),idebug,argv[idebug]);
	}
#endif
	while (--argc>0){
		if (argv[argc][0]==ARG_PREFIX && _tcslen(argv[argc])>1){
			switch(argv[argc][1]){
			case _T('p'):case _T('P'):
				_tcscpy(path,&argv[argc][2]);
				break;
			//case _T('n'):case _T('N'):
			//	_tcscpy(name,&argv[argc][2]);
			case _T('e'):case _T('E'):
				_tcscpy(ext,&argv[argc][2]);
				break;
			case _T('t'):case _T('T'):
				t=argv[argc][2]-_T('0');
				break;
			case _T('l'):case _T('L'):
				l=argv[argc][2]-_T('0');
				break;
			case _T('h'):case _T('H'):
				showhelp=1;
				break;
			}
		}
		else
			_tcscpy(name,argv[argc]);	
	}
	if (showhelp==1) 
		_tprintf(_T("%s"),
				"�������¼��ֲ�����\n"\
				"-p[path]  ����������·����Ĭ��Ϊ��ǰĿ¼��\n"\
				"-n[name]  �������������ƣ������Ƿǿ��ַ�����û��Ĭ��ֵ��\n"\
				"-e[ext]   ������������չ����\n"\
				"          ��������������ֵ���ж��������;�Ÿ�����\n"\
				"-t[type]  �������������ͣ�0Ϊ�ļ���1ΪĿ¼��\n"\
				"-l[level] ������������ȣ�Ĭ��Ϊ0��\n"\
				"-h        ��ʾ����");
	if (name[0]==NIL) return 0;
	if (ext[0]==NIL && t==-1) t=1;
	if (path[0]==NIL)
		path=_tgetenv(_T("path"));
	if (path[0]==ENV_PREFIX) {
		path++;
		path[_tcslen(path)-1]=NIL;
		path=_tgetenv(path);
	}
	if (t==0) 
		attrib=_A_ARCH;
	else
		attrib=_A_SUBDIR;
	
	UNQUOTE(path);
	UNQUOTE(ext);
	_tprintf(_T("%s"),findin(path,ext,name,attrib,l));
	return 0;
}

/*!
    \brief ��ʼ���в���
    \arg path    ����·��(����·����;�Ÿ���)
    \arg ext     �ļ���չ��(������չ����;�Ÿ���)
    \arg name    �ļ�����
    \arg attrib  �ļ�����
    \arg level   ���ҵ����
    \return      ���ز��ҽ���ַ���
*/
LString findin(
            LString path,
            LString ext,
            LString name,
            unsigned int attrib,
            unsigned int level)
{
	LString *pathV=(LString *)malloc(MAX_SEARCH_PATH*sizeof(LString));
	LString *extV=(LString *)malloc(MAX_SEARCH_EXT*sizeof(LString));
	LString tmpname=(LString)malloc(_MAX_FNAME*sizeof(_TCHAR));
	LString fullname=(LString)malloc(_MAX_FNAME*sizeof(_TCHAR));
	LString result;
	int pc;
	int ec;
	int pi;
	int ei;
	pc=strsplit(path,QUOTE,pathV);
	ec=strsplit(ext,QUOTE,extV);

	for (pi=0;pi<pc;pi++) {
		buildpath(tmpname,pathV[pi],name);
		if (ec>0) {
			for (ei=0;ei<ec;ei++) {
				_tcscpy(fullname,tmpname);
				if (extV[ei][0]!=NIL) 
					_tcscat(fullname,extV[ei]);
				result=goforfile(fullname,attrib,level);
				if (result!=NULL) 
					return (_TCHAR *)buildpath(fullname,pathV[pi],result);
			}
		}
		else {
			result=goforfile(tmpname,attrib,level);
			if (result!=NULL) 
				return (_TCHAR *)buildpath(fullname,pathV[pi],result);
		}
	}

	return NULL;
}


/*!
    \brief ��ʽ����
    \arg filename    ��ȫ·����(����*?)
    \arg attrib      �ļ�����
    \arg level       ���ҵ����
    \return          ���ַ�����ʽ���ؽ��
*/
LString goforfile(
                LString filename,
                unsigned int attrib,
                int level)
{
	struct _tfinddata_t c_file;
	intptr_t hfile;
	hfile=_tfindfirst(filename,&c_file);
	if (hfile==-1) return NULL;
	do {
		if (c_file.attrib & attrib) 
			return _tcsdup(c_file.name);
	} while (_tfindnext(hfile,&c_file)==0);
	return NULL;
}
