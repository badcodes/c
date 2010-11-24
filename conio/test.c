
#include "conio.h"

int main() {
	int i;
	clrscr();
	for(i=0;i<16;i++) {
		gotoxy(20,i);
		textcolor(i);
		_cputs("HELLO,WORLD!\n");
	}
	return 0;
}
