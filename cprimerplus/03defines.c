/*!
 * @file	03defines.c
 * @brief	show some limits defines.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("Some number limits for this system.\n");
	printf("Max Int:%d\n",INT_MAX);
	printf("Min Int:%d\n",INT_MIN);
	printf("Max Unsigned Int:%u\n",UINT_MAX);
	printf("Max Char:%d\n",CHAR_MAX);
	printf("Max Char:%d\n",CHAR_MIN);
	printf("Char Bit:%d\n",CHAR_BIT);
	printf("Max Short:%d\n",SHRT_MAX);
	printf("Min Short:%d\n",SHRT_MIN);
	printf("Max Long:%d\n",LONG_MAX);
	printf("Min Long:%d\n",LONG_MIN);
	printf("Max Unsigned Long:%u\n",ULONG_MAX);
	printf("Max Float:%e\n",FLT_MAX);
	printf("Min Float:%e\n",FLT_MIN);
	printf("Max Double:%e\n",DBL_MAX);
	printf("Min Double:%e\n",DBL_MIN);
	
}
