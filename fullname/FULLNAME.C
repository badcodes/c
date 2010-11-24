
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define VERSION "0.1"
#define APPNAME "fullname"
#define AUTHOR "xiaoranzzz@myplace"
#define DESC "return fullpath name"

char* buildpath(const char* fst,const char* sec,char* buf);


int main(int argc,char** argv) {
	char* basename;
	char cwd[255];
	char fullname[255];

	if(argc!=2) {
		printf("%s v%s, written by %s\n",APPNAME,VERSION,AUTHOR);
		printf("    - %s\n",DESC);
		printf("Usage:\n\t%s (filename)\n",argv[0]);
		return 1;
	}

	basename=argv[1];
	if (basename[1]==':') {
		if(basename[2]=='\\') {
			strcpy(fullname,basename);
		}
		else {
			int drive=toupper(basename[0]) - 'A' + 1;
			getcurdir(drive,cwd);
			strncpy(fullname,basename,2);
			fullname[2]='\\';
			fullname[3]='\0';
			strcat(fullname,cwd);
			buildpath(fullname,basename+2,fullname);
		}
	}
	else {
		getcwd(cwd,255);
		if(basename[0]=='\\') {
			strncpy(fullname,cwd,2);
			fullname[2]='\0';
			strcat(fullname,basename);
		}
		else {
			buildpath(cwd,basename,fullname);
		}
	}
	printf("%s\n",fullname);
	return 0;
}

char* buildpath(const char* fst,const char* sec,char* buf) {
/*
	printf("fst=%s\nsec=%s\n",fst,sec);
*/
	strcpy(buf,fst);
	if(buf[strlen(buf)-1]!='\\')
		strcat(buf,"\\");
	if(sec[0]=='\\') sec++;
	strcat(buf,sec);
	return buf;
}


