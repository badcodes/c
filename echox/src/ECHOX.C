
#define ASM 0
#define STRCPY 1

#ifdef __TURBOC__

#if defined USE_PRINTF
	#include <stdio.h>
#elif defined USE_CPUTS
	#include <conio.h>
#elif defined USE_PUTS
	#include <stdio.h>
#else
	#define USE_WRITE
	#include <io.h>
	#include <fcntl.h>
#endif

#endif

#define MAX_CHAR 256

#if STRCPY
	#include "arrcpy.h"
#define FEED_STR(DST,IDX,SRC) arrcpy(DST,&IDX,SRC)
#else
#define FEED_STR(DST,IDX,SRC) while(*SRC) {DST[IDX++]=*(SRC++);}
#endif
#define PUT_BREAK(C) ostr[is++]=C;break;

#define STREQU(N,A,B) (A[0+N] == B && A[1+N] == 0)
#define STREQU2(N,A,B,C) (A[0+N] == B && A[1+1] == C && A[2+N] == 0)
#define STREQU3(N,A,B,C,D) (A[0+N] == B && A[1+N] == C && A[2+N] == D && A[3+N] == 0)

#define EXT_MARK 'e'
#define CMD_S ';'
#define TAB_MARK '#'
#define NEWLINE_MARK '^'

void process(unsigned char ext,char* str,int len);

int main(int argc,char** argv) {

    char str[MAX_CHAR];
    char* ostr = str;
    int is;
    unsigned char ext;

recheck:
	is=0;
	ext=0;
    while(argc>1 && argv[1][0] == '-') {
		if(STREQU(1,argv[1],'e')) {
				ext |= 1;
				argc--;
				argv++;
		}
		else if(STREQU(1,argv[1],'n')) {
				ext |= 2;
				argc--;
				argv++;
		}
		else if(STREQU2(1,argv[1],'e','n') 
				|| STREQU2(1,argv[1],'n','e')) {
				ext |= 3;
				argc--;	
				argv++;
		}
		else {
			break;
		}
	}
	if(argc == 1) goto e_exit;

	/*Copy first string without checking*/
	FEED_STR(ostr,is,argv[1]);
	argc--;argv++;
    ostr[is++]=' '; /*add suffix space*/

	while(argc > 1) {
		/*Checking strings spliter*/
		if(argv[1][1] == 0) {
			switch(argv[1][0]) {
				case CMD_S:
					is--; /*delete suffix space*/
					process(ext,ostr,is);
					argc--;
					argv++;
					goto recheck;
				case TAB_MARK:
					is--; /*delete suffix space*/
					ostr[is++]='\t';
					break;
				case NEWLINE_MARK:
					is--;
					ostr[is++]='\n';
					break;
				default:
					ostr[is++]=argv[1][0];
				    ostr[is++]=' '; /*add suffix space*/
					break;
			}
		}
		else {
	        FEED_STR(ostr,is,argv[1]);
		    ostr[is++]=' '; /*add suffix space*/
		}
		argc--;
		argv++;
	}
	is--;
	process(ext,ostr,is);

e_exit:
	if(ext&2) 
		process(0,"\n",1);
	return 0;

}


void process(unsigned char ext,char* ostr,int olen) {
	int is=olen;
	if(ext&1) {
		int i=0;
		is=0;
		for(i=0;i<olen ;i++) {
        	if(ostr[i+1] && ostr[i] == '\\') {
            	switch(ostr[++i]) {
                case 'a' : PUT_BREAK('\a');
                case 'f' : PUT_BREAK('\f');
                case 'v' : PUT_BREAK('\v');
                case 'r' : PUT_BREAK('\r');
                case 'b' : PUT_BREAK('\b');
                case 'n' : PUT_BREAK('\n');
                case 't' : PUT_BREAK('\t');
                case 'e' : PUT_BREAK(27);
                case '\\': PUT_BREAK('\\');
                default  : --i;PUT_BREAK('\\');
            	}
            }
            else {
                ostr[is++]=ostr[i];
            }
        }
	}

#if defined  USE_PRINTF
    {
		ostr[is]=0;
		printf("%s",ostr);
	}
#elif defined USE_PUTS
	{
		ostr[is]=0;
		puts(ostr);
	}
#elif defined USE_CPUTS
	{
		ostr[is]=0;
		cputs(ostr);
	}
#else
	{
		static int STDOUT=0;
		if(STDOUT==0)
			STDOUT=_open("CON",O_WRONLY | O_BINARY);
/*
		printf("called:STDOUT=%d,"
			"ext=%d,olen=%d,is=%d,STR=%s\n",
			STDOUT,ext,olen,is,ostr);
*/
		_write(STDOUT,ostr,is);
	}
#endif

	return;
}
