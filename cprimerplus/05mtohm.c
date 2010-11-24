/*!
 * @file 05mtohm.c
 * @brief convert times in minutes to times in hours and minutes
 */

#include <stdio.h>
#define MOFH 60
#define POST_S(int_post_s) ((int_post_s)>1?"s":"")
int main(void)
{
	int m;
	int hh;
	int hm;
	printf("Enter times in mintues:");
	scanf("%d",&m);
	hh=m / MOFH;
	hm=m % MOFH;
	printf("[%d minute%s] is equal to [%d hour%s] and [%d minute%s]\n",
		m,
		POST_S(m),
		hh,
		POST_S(hh),
		hm,
		POST_S(hm)
		);
	return 0;
}
