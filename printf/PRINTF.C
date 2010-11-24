#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cmd_printf(int argc,char** argv);


int main(int argc,char** argv) {
	return cmd_printf(argc,argv);
}

int cmd_printf(int argc,char** argv) {
	char *fmt_buf,*fmt;
	int varc;
	if(argc==1)
		return help("printf");
	fmt_buf=strdup(argv[1]);
	varc=2;
	while(c=
}
int cmd_help(char* cmdname) {
	if(stricmp(cmdname,"printf")==0) {
		printf("%s V%s\n-    %s",cmdname,cmd_ver(cmdname),
	}
}