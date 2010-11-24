/*!
 * @file	03escape.c
 * @brief	use escape charactors
 */
#include <stdio.h>

int main(void)
{
	float salary;

	printf("\aEnter you desired monthly salary:");
	printf(" $_______\b\b\b\b\b\b\b");
	scanf("%f",&salary);
	printf("\t$%.2f a month is $%.2f a year.",salary,salary*12.0);
	printf("\rGee!");
	return 0;
}
