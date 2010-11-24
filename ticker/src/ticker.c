/*!
 * @file ticker.c
 * @brief a simple time ticker
 */

#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#include <conio.h>

void startticker(void);

int main(void)
{
	int c;
	fputs("Press [q] to exit,others to start.\r",stderr);
	c=_getch();
	printf("                                                          \r");
	if (c=='q') return 0;
	startticker();
	fputs("\nPress [q] to exit,others to restart.\r",stderr);
	while (1) {
		if (_kbhit()) {
			c=_getch();
			switch(c){
			case 'q':case 'Q':
				return 0;
			default:
				startticker();
				fputs("\nPress [q] to exit,others to restart.\r",stderr);
				break;
			}
		}
	}
	return 0;
}

void startticker(void)
{
	int c;
	int s;
	int ms;
	struct _timeb pst;
	struct _timeb cst;
	_ftime(&pst);
	fputs("                                                                     \r",stderr);
	do {
			if(_kbhit()) {
				c=_getch();
				switch(c) {
				case 'q':case 'Q':
					return;
				case 'r':case 'R':case ' ':
					_ftime(&pst);
					break;
				default:
					break;
				}
			}
			_ftime(&cst);
			s=cst.time-pst.time;
			ms=cst.millitm-pst.millitm;
			if (ms<0) {
				s--;
				ms=1000+ms;
			}
			printf("%d.%-3d\r",s,ms);
		} while (1);
		return;
}

