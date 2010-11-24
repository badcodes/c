#include <stdio.h>

int main(void)
{
	int i;
	for(i=0;i<101;i++)
		printf("Dec:%d\tHex:%#x\tOctal:%#o\n",i,i,i);
	return 0;
}
