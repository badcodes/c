#include <stdlib.h>
#define POSMARK '$'
#define MARK_BASENAME 'B'
#define MARK_ASSIGN '^'
#define MAX_LINE=256

int main(int argc,char** argv) {
	char CMD[MAX_LINE];
	int ic=0;
	int i;
	int m=0;
	int tc=0;
	if(argc<1)	return 0;
	while(argc!=1) {
		if(argv[1][0] == POSMARK && argv[1][1] && argv[1][2] == MARK_ASSIGN) {
			switch(argv[1][1]) {
				case MARK_BASENAME:
					while(*(argv[1]++)) {
						if(/						
					}
					break
				default:
					goto l_copy;
			}
		}
l_copy:
		while(CMD[ic++]=*(argv[1]++);
l_next:
		argc--;
		argv++;
	}
}
