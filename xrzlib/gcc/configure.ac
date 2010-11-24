#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([XRZ C Library],[1.0],[xiaoranzzz@gmail.com],[XRZLib])
AC_COPYRIGHT([xiaoranzzz@myplace])
AC_REVISION([$Revision: 1.0 $])
AC_PREFIX_DEFAULT([/myplace])
AC_CONFIG_SRCDIR([src/debug.h])
AC_CONFIG_HEADER([config.h])

AM_INIT_AUTOMAKE([foreign])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stddef.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([strdup strstr])

AC_CONFIG_FILES([makefile
                 src/makefile])
AC_OUTPUT
