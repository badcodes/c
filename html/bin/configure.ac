#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)


AC_INIT(htmllink,0.1, xiaoranzzz@gmail.com)

AC_CONFIG_SRCDIR([src/debug.h])
AC_CONFIG_HEADER([src/config.h])
AC_PREFIX_DEFAULT([/usr])

AC_DEFINE([AUTHOR],["xrLin,xiaoranzzz@gmail.com"],[AUTHOR INFORMATION])
AC_DEFINE_UNQUOTED([PACKAGE_BUILDDATE],"`date`",[Date of last build])

AM_INIT_AUTOMAKE($PACKAGE_NAME,$PACKAGE_VERSION,$PACKAGE_BUGREPORT)
# Checks for programs.

AC_GNU_SOURCE
AC_PROG_CC

CFLAGS="$CFLAGS -O2 -Wall"

# Checks for header files.
AC_HEADER_STDC
#AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([malloc.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
#AC_HEADER_STDBOOL
#AC_HEADER_TIME

# Checks for library functions.
#AC_TYPE_SIGNAL
AC_CHECK_FUNCS([strchr strdup strrchr])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
