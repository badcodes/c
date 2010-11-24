#ifndef XRZ_INCLUDE_COMPILER
#define XRZ_INCLUDE_COMPILER
#ifdef __WATCOMC__
	#include <graph.h>
	
	#define findfirst(a,b,c) _dos_findfirst((a),(c),(b))
	#define findnext _dos_findnext
	#define findclose _dos_findclose
	#define ffblk	find_t
	#define FILENAME(X) (X).name
	extern char* searchpath(const char* filename);
	#define restore_screen() ;
	extern struct videoconfig _video;
	#define _videoattr  _gettextcolor()
	extern int directvideo;
	//#define flush flushall
	#define textcolor(L) _settextcolor((short)(L))
	#define textbackground(I) _setbkcolor((long)(I))
        extern enum TEXT_COLORS {
               BLACK=0, BLUE, GREEN, CYAN,
               RED, MAGENTA, BROWN, WHITE,
               GRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN,
               LIGHTRED, LIGHTMAGENTA, YELLOW, BRIGHTWHITE
        };
        #define LIGHTGRAY BRIGHTWHITE
	#define BLINK 0x10
	#define gotoxy(x,y) _settextposition((y),(x))
	#define clrscr()	_clearscreen(_GCLEARSCREEN)
	#define insline()	_scrolltextwindow(_GSCROLLDOWN)
	extern void clreol(void);
#else

	#define FILENAME(X) (X).ff_name
#endif
#endif

