/*
 * Routines dealing with getting input from the keyboard (i.e. from the user).
 */

#include "less.h"

extern int kill_char;

#if !defined(TURBOC) && !defined(__WATCOMC__)

#if __MSDOS__
#include <io.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#endif

static int tty;

/*
 * Open keyboard for input.
 */
	public void
open_getchr()
{
#if __MDDOS__
	/*
	 * Open a new handle to CON: in binary mode 
	 * for unbuffered keyboard read.
	 */
	tty = open("CON", O_RDONLY|O_BINARY);
#else
	/*
	 * Try /dev/tty.
	 * If that doesn't work, use file descriptor 2,
	 * which in Unix is usually attached to the screen,
	 * but also usually lets you read from the keyboard.
	 */
	tty = open("/dev/tty", 0);
	if (tty < 0)
		tty = 2;
#endif
}

// void test_tty() {
	// int c;
	// printf("testing tty\n");
	// while((c=read(tty,&c,1))!='q') {
		// if(c==-1) {
			// perror("read(tty)");
			// return;
		// }
		// printf("c=%d\n",c);
	// }
// }

/*
 * Get a character from the keyboard.
 */
	public int
getchr()
{
	char c;
	int result;

	do
	{
		result = iread(tty, &c, sizeof(char));
		if (result == READ_INTR)
			return (READ_INTR);
		if (result < 0)
		{
			/*
			 * Don't call error() here,
			 * because error calls getchr!
			 */
			 printf("read error\n");
			quit(1);
		}
#if __MSDOS__
		/*
		 * In raw read, we don't see ^C so look here for it.
		 */
		if (c == kill_char) {
			printf("I'm killed\n");
			raise(SIGINT);
		}
#endif
		/*
		 * Various parts of the program cannot handle
		 * an input character of '\0'.
		 * If a '\0' was actually typed, convert it to '\200' here.
		 */
		if (c == '\0')
			c = '\200';
	} while (result != 1);

	return (c);
}
#else /* TURBOC */

#include <dos.h>
#include <signal.h>

/*
 * Open keyboard for input.
 */
	public void
open_getchr()
{
}

/*
 * Get a character directly from the PC BIOS.
 */
	public int
getchr()
{
	int c;
 	static int extrac = 0;
 
 	if (extrac) {
 		c = extrac;
 		extrac = 0;
 		return c;
 	}
 	flush ();
 	do {
		#ifdef TURBOC
 		asm {
			mov	ah,0	/* call:  BIOS read char into ax */
 			int	16h
 		};
		c = _AX;
		#else
		c = read_keyb();
	//        lower_left();
        //	clear_eol();
        //                flush();
        //        cprintf("\rread_keyb=%o",c);
	//'\200','\120',0,		A_F_LINE,		/* down arrow */
	//'\200','\121',0,		A_F_SCREEN,		/* page down */
	//'\200','\110',0,		A_B_LINE,		/* up arrow */
	//'\200','\111',0,		A_B_SCREEN,		/* page up */
		#endif
		if (c == 0) {
			raise (SIGINT);
			c = kill_char;
		} else {
			extrac = c >> 8;
			if (c &= 0xff)
				extrac = 0;
			else
				c = '\200';
		}
       //         cprintf(",%o,%o",extrac,c);
                flush();
 	} while (c == 0);
	return c;
}
#endif	/* TURBOC */
