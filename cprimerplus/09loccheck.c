/*!
 * @file	09loccheck.c
 * @brief print address of variables in main and in func
 */

#include <stdio.h>
void func(int);

int main(void)
{
	int i=2;
	int j=3;
	printf("In main,i=%d,&i=%p.\n",i,&i);
	printf("In main,j=%d,&j=%p.\n",j,&j);
	func(i);
	return 0;
}

void func(int i)
{
	int j=4;
	printf("In func,i=%d,&i=%p.\n",i,&i);
	printf("In func,j=%d,&j=%p.\n",j,&j);
	return;
}

	
