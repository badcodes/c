/*!
 * @file	09fibonacci.c
 * @brief	get fibonacci number using loop or recursion
 */

#include <stdio.h>

unsigned long long fibonacci(int d);
unsigned long long r_fibonacci(int d);

int main(void)
{
	int d;
	printf("Enter a integer number:");
	if (scanf("%d",&d)==1) {
		printf("Loop Version:\t%llu\n",fibonacci(d));
		printf("Recursion Version:\t%llu\n",r_fibonacci(d));
	}
	return 0;
	
}

unsigned long long fibonacci(int d)
{
	unsigned long long pre;
	unsigned long long ppre;
	unsigned long long fb=0;
	int i;
	ppre=1;
	pre=0;
	for (i=0;i<d;i++){
		fb=pre+ppre;
		ppre=pre;
		pre=fb;
	}
	return fb;
}

unsigned long long r_fibonacci(int d)
{
	if (d>2)
		return r_fibonacci(d-1)+r_fibonacci(d-2);
	else
		return 1;
}
