/*
 * Display some help.
 * Just invoke another "less" to display the help file.
 *
 * {{ This makes this function very simple, and makes changing the
 *    help file very easy, but it may present difficulties on
 *    (non-Unix) systems which do not supply the "system()" function. }}
 */

#include  "less.h"

#if __MSDOS__
#include <io.h>
#include <direct.h>
#include <string.h>
#include <stdlib.h>
#ifndef TURBOC
extern int output_mode;
#endif
#endif

extern char *progname;

	public void
help()
{
	char *helpfile;
	char *cmd;

	helpfile = find_helpfile();
	if (helpfile == NULL)
	{
		error("Cannot find help file", NULL_PARG);
		return;
	}
#if __MSDOS__
	putenv("LESS=-+v -+E -+s -mHPmHELP -- ?eEND -- Press g to see "
		"it again:Press RETURN for more., or q when done ");
	cmd = (char *) ecalloc(strlen(helpfile) + strlen(progname) + 50,
				sizeof(char));
#ifdef TURBOC
	if (directvideo)
		sprintf(cmd, "-%s %s", progname, helpfile);
	else
		sprintf(cmd, "-%s -v %s", progname, helpfile);
#else
	if (output_mode == 0)
		sprintf(cmd, "-%s %s", progname, helpfile);
	else
		sprintf(cmd, "-%s -qVW4,4,76,23,Help %s", progname, helpfile);
#endif	/* TURBOC */
#else
	cmd = (char *) ecalloc(strlen(helpfile) + strlen(progname) + 150,
				sizeof(char));
	sprintf(cmd, 
	 "-%s -m -H -+E -+s '-PmHELP -- ?eEND -- Press g to see it again:Press RETURN for more., or q when done ' %s",
		progname, helpfile);
	free(helpfile);
#endif
	lsystem(cmd);
	error("End of help", NULL_PARG);
	free(cmd);
}
