
#include <stdio.h>
#include "string.h"

int main(int argc,char** argv) {
	if(argc<4) return 1;

	printf("stridx(%s,%s)=%d\n",argv[1],argv[2],stridx(argv[1],argv[2]));
	printf("strridx(%s,%s)=%d\n",argv[1],argv[2],strridx(argv[1],argv[2]));

	printf("dstrrpl(%s, %s , %s) = %s\n",
		argv[1],argv[2],argv[3],
		dstrrpl(argv[1],argv[2],argv[3])
		);

	return 0;

}

