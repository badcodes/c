/*!
 * @file 05prepost.c
 * @brief test prefix and postfix of ++ and --
 */

#include <stdio.h>
#define FORMAT "%s C is coll!\n"

int main(void)
{
	int n=100;
	printf(FORMAT,FORMAT);
	printf("%d\n",n++);
	printf("%d\n",++n);
	printf("%d\n",n--);
	printf("%d\n",--n);
	return 0;
	
}
