/* Definition file for less */
/* Generated  by linstall. */

#ifdef	__TURBOC__
#ifndef __MSDOS__
#define __MSDOS__	1
#endif
#ifndef	TURBOC
#define	TURBOC
#endif
#endif

#ifdef	__MSDOS__
#undef	__MSDOS__
#endif
#define __MSDOS__	1
/*
 * Define XENIX if running under XENIX 3.0.
 */
#define	XENIX		0

/*
 * VOID is 1 if your C compiler supports the "void" type,
 * 0 if it does not.
 */
#define	VOID		1
#if VOID
#define	VOID_POINTER	void *
#else
#define	VOID_POINTER	char *
#endif

/*
 * offset_t is the type which lseek() returns.
 * It is also the type of lseek()'s second argument.
 */
#define	offset_t	long

/*
 * STAT is 1 if your system has the stat() call.
 */
#define	STAT		1

/*
 * PERROR is 1 if your system has the perror() call.
 * (Actually, if it has sys_errlist, sys_nerr and errno.)
 */
#define	PERROR		1

/*
 * GET_TIME is 1 if your system has the time() call.
 */
#define	GET_TIME	1

/*
 * TERMIO is 1 if your system has /usr/include/termio.h.
 * This is normally the case for System 5.
 * If TERMIO is 0 your system must have /usr/include/sgtty.h.
 * This is normally the case for BSD.
 */
#define	TERMIO		0

/*
 * HAS__SETJMP is 1 if your system has the _setjmp() call.
 * This is normally the case only for BSD 4.2 and up,
 * not for BSD 4.1 or System 5.
 */
#define	HAS__SETJMP	0

/*
 * SIGSETMASK is 1 if your system has the sigsetmask() call.
 * This is normally the case only for BSD 4.2,
 * not for BSD 4.1 or System 5.
 */
#define	SIGSETMASK	0

/*
 * REGCMP is 1 if your system has the regcmp() function.
 * This is normally the case for System 5.
 * RECOMP is 1 if your system has the re_comp() function.
 * This is normally the case for BSD.
 * If neither is 1, pattern matching is supported, but without metacharacters.
 */
#define	REGCMP		0
#define	RECOMP		0

/*
 * SHELL_ESCAPE is 1 if you wish to allow shell escapes.
 * (This is possible only if your system supplies the system() function.)
 */
#define	SHELL_ESCAPE	1

/*
 * EDITOR is 1 if you wish to allow editor invocation (the "v" command).
 * (This is possible only if your system supplies the system() function.)
 * EDIT_PGM is the name of the (default) editor to be invoked.
 */
#define	EDITOR		1
#define	EDIT_PGM	"vi"

/*
 * TAGS is 1 if you wish to support tag files.
 */
#define	TAGS		0

/*
 * USERFILE is 1 if you wish to allow a .less (_less under MSDOS) file to specify 
 * user-defined key bindings.
 */
#define	USERFILE	0

/*
 * GLOB is 1 if you wish to have shell metacharacters expanded in filenames.
 * This will generally work if your system provides the "popen" function
 * and the "echo" shell command.
 */
#define	GLOB		0

/*
 * PIPEC is 1 if you wish to have the "|" command
 * which allows the user to pipe data into a shell command.
 */
#define	PIPEC		0

/*
 * LOGFILE is 1 if you wish to allow the -l option (to create log files).
 */
#define	LOGFILE		0

/*
 * ONLY_RETURN is 1 if you want RETURN to be the only input which
 * will continue past an error message.
 * Otherwise, any key will continue past an error message.
 */
#define	ONLY_RETURN	0

/*
 * For MSDOS, HELPFILE is simply the name. The entire PATH is searched
 */
#define	HELPFILE	"less.hlp"

