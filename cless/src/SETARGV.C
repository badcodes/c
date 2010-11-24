/* setargv -- setup argv with wild card expansion                           */
/* copyright 1987  Michael M Rubenstein                                     */
 
/* This program may be freely distributed provided no fee is assessed.      */
 
/* This file implements wild card expansion in argv for Turbo C 1.5.        */
/* Strings of characters in either quotes (") or appostrophes (') on the    */
/* command line are considered a single argument.  However, backslash       */
/* escapes are not implemented.  A quote may be included in an argument     */
/* which is enclosed in appostrophes and an appostrophe may be included     */
/* in an argument enclosed in quotes.  Either may be included as an         */
/* in an argument starting with any other character.                        */
 
/* Any argument which is not enclosed in quotes or appostrophes, does not   */
/* begin with a hyphen (-), and which contains an asterisk (*) or question  */
/* mark (?) will be expanded.  It is NOT an error for an argument to have a */
/* null expansion (no matching files).  Only ordinary files (not            */
/* directories or hidden or system files) will be included in the           */
/* expansion.                                                               */
 
/* To use this function, simply compile it with the appropriate memory      */
/* model and include in the link.  This can be accomplished very simply     */
/* in the integrated environment by simply including this file in the       */
/* project file.  In the command line version, simply include this file     */
/* (or a precompiled .OBJ version) on the command line.                     */
 
#include <stdio.h>
#include <ctype.h>
#include <dos.h>
#include "compiler.h"
#include <process.h>
#include <errno.h>
 
#define FALSE           0
#define TRUE            1
 
void putarg(unsigned char far *, unsigned char far *, int lcase);
 
extern int              _C0argc;
extern char             **_C0argv;
extern unsigned         _psp;
extern unsigned         _envseg;
extern unsigned         _envLng;
extern unsigned char    _osmajor;
extern void             _abort();
extern char             *sbrk(int);
 
void _setargv__(void)
{
  unsigned char         far *cmdtail;
  unsigned char         *firstarg;
  unsigned char         far *cmdarg;
  int                   wild;
  int                   c;
  unsigned char         buffer[129];
  unsigned char         *p, *q;
  unsigned char         *lastdir;
  char                  **wargv;
  int                   i;
  struct ffblk          ffb;
 
  cmdtail = MK_FP(_psp, 0x81);
  cmdtail[cmdtail[-1]] = '\0';      /* make sure null at end */
  firstarg = (unsigned char *) sbrk(0);
  _C0argc = 1;
 
  while (*cmdtail != '\0')
  {
    /* skip white space */
    while (isascii(*cmdtail) && isspace(*cmdtail))
      ++cmdtail;
 
    /* done with command loop if end of command tail */
    if (*cmdtail == '\0')
      break;
 
    /* if quoted string, just save the argument */
    if ((c = *cmdtail) == '"' || c == '\'')
    {
      cmdarg = ++cmdtail;
      while (*cmdtail != c && *cmdtail != '\0')
        ++cmdtail;
      putarg(cmdarg, cmdtail, 0);
      if (*cmdtail != '\0')
        ++cmdtail;
      continue;
    }
 
    /* find word */
    cmdarg = cmdtail;
    wild = FALSE;
    p = lastdir = buffer;
    while ((c = *cmdtail) != '\0'
        && (!isascii(c) || !isspace(c)))
    {
      /* wild is TRUE if word contains * or ? */
      wild |= (c == '*' || c == '?');
/*  Next line was added to make the treatment of / and \ alike  */
      if (c == '/') c = '\\';
      *(p++) = c;
 
      /* lastdir points to the first character of the base file name */
      if (c == '\\' || c == ':')
        lastdir = p;
      ++cmdtail;
    }
    *p = '\0';
 
    if (*cmdarg == '-' || *cmdarg == '+')
      putarg(cmdarg, cmdtail, 0);
    else if (wild)
    {
      c = findfirst((char *) buffer, &ffb, 0);
      if (c)
        putarg(cmdarg, cmdtail, 0);
      else
        while (!c)
        {
          for (p = lastdir, q = (unsigned char *) FILENAME(ffb); *q != '\0';)
               *(p++) = *(q++);
          putarg(buffer, p, 1); /* use lowercase for filenames */
          c = findnext(&ffb);
        }
    }
    else
      putarg(cmdarg, cmdtail, 1); /* use lowercase for filenames */
  }
 
  /* allocate argv */
  if ((wargv = (char **) sbrk(sizeof(char *) * (_C0argc + 1))) == (char **) -1)
    abort();
  _C0argv = wargv;
 
  /* store program name */
  if (_osmajor < 3)
    *(wargv++) = "C";
  else
  {
      cmdtail = cmdarg = MK_FP(_envseg, _envLng + 2);
#   if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
      *(wargv++) = sbrk(0);
      while (*cmdtail != '\0')
        ++cmdtail;
      putarg(cmdarg, cmdtail, 0);
      --_C0argc;
#   else
      *(wargv++) = (char *) cmdarg;
      (void) sbrk(15);  /* kludge for TC++ library bug */
#   endif
  }
 
  /* store arguments */
  for (i = _C0argc; --i;)
  {
    *(wargv++) = (char *) firstarg;
    while(*++firstarg != '\0')
      ;
    ++firstarg;
  }
  *wargv = (char *) 0;
  errno = 0;
}
#pragma startup _setargv__ 80
 
static void putarg(from, to, lcase)
  unsigned char         far *from, far *to;
  int lcase;
{
  char                  *p;
 
  if ((p = sbrk((unsigned)(to - from) + 1)) == (char *) -1)
    abort();
  while (from < to)
    if (lcase)
      *(p++) = tolower(*(from++));
    else
      *(p++) = *(from++);
  *p = '\0';
  ++_C0argc;
}
 
