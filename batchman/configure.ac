#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)


AC_INIT(batchman,0.2, xiaoranzzz@gmail.com)

AC_CONFIG_SRCDIR([src/batchman.c])
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
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([malloc.h stdio_ext.h stdlib.h string.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_HEADER_TIME

# Checks for library functions.
AC_TYPE_SIGNAL
AC_CHECK_FUNCS([getline getcwd mkdir select strchr strdup strrchr])

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
