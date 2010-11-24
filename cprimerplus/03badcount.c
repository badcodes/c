//!@file 03badcount.c
//!@brief incorrect arguments count
#include <stdio.h>

int main(void)
{
	int i=1024;
	float f=1024.1024;

	printf("%d\t%d\n",i);
	printf("%d\n",i,f);
	printf("%f\t%f\n",f);
	printf("%f\n",f,i);
	return 0;
}

