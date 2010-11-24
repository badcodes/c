
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

#define VERSION "0.1"
#define APPNAME "fullname"
#define AUTHOR "xiaoranzzz@myplace"
#define DESC "search filename in current directory and PATH"

char* buildpath(const char* fst,const char* sec,char* buf);
int fexist(const char* filename);
char* testext(const char* filename);


int main(int argc,char** argv) {
	char basename[255];
	char cwd[255];
	char fullname[255];
	char *result;

	if(argc!=2) {
		printf("%s v%s, written by %s\n",APPNAME,VERSION,AUTHOR);
		printf("    - %s\n",DESC);
		printf("Usage:\n\t%s (filename)\n",argv[0]);
		return 1;
	}

	strcpy(basename,argv[1]);
	if((result=testext(basename))) {
		printf("%s\n",result);
		return 0;
	}


	getcwd(cwd,255);
/*	printf("cwd=%s\n",cwd); */

	buildpath(cwd,basename,fullname);
	if((result=testext(fullname))) {
		printf("%s\n",result);
		return 0;
	}

	if((result=searchpath(basename))) {
		printf("%s\n",result);
		return 0;
	}

	return 1;
}

char* buildpath(const char* fst,const char* sec,char* buf) {
	strcpy(buf,fst);
	strcat(buf,"\\");
	strcat(buf,sec);
	return buf;
}

int fexist(const char* filename) {
	int r;
/*	printf("%s\n",filename);  */
	r=open(filename,O_RDONLY);
	if(r<0) return 0;
	close(r);
	return 1;
}

char* testext(const char* filename) {
	static char* result[255];
	strcpy(result,filename);
	if(fexist(result))
		return result;

	strcat(result,".exe");
	if(fexist(result))
		return result;

	strcpy(result,filename);
	strcat(result,".com");
	if(fexist(result))
		return result;

	strcpy(result,filename);
	strcat(result,".bat");
	if(fexist(result))
		return result;

	return NULL;
}