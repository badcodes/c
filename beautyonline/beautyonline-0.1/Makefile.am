## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = po \
	src 

beautyonlinedocdir = ${prefix}/doc/beautyonline
beautyonlinedoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS

EXTRA_DIST = $(beautyonlinedoc_DATA)

# Copy all the spec files. Of cource, only one is actually used.
dist-hook:
	for specfile in *.spec; do \
		if test -f $$specfile; then \
			cp -p $$specfile $(distdir); \
		fi \
	done

