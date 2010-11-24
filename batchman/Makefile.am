
SUBDIRS = src

EXTRA_DIST = batchman.spec

RPMBUILD=rpmbuild
RPMBUILDFLAG=--clean --rmsource --rmspec
RPMDST=egrep -o "^Wrote:[[:print:]]*\.rpm" | \
       sed "s/^Wrote:\s\+\([[:print:]]*\.rpm\)/\1/g" | \
       sed "s/\\n/ /g" | \
       sed "s/\n/ /g"

rpm: dist-gzip
	RPM_DST=`$(RPMBUILD) $(RPMBUILDFLAG) -ta $(distdir).tar.gz | $(RPMDST)`;\
	echo mv $$RPM_DST -t . ;\
	mv $$RPM_DST -t . 
rpm-binary: dist-gzip
	RPM_DST=`$(RPMBUILD) $(RPMBUILDFLAG) -tb $(distdir).tar.gz | $(RPMDST)`;\
	echo mv $$RPM_DST -t . ;\
	mv $$RPM_DST -t . 
rpm-source: dist-gzip
	RPM_DST=`$(RPMBUILD) $(RPMBUILDFLAG) -ts $(distdir).tar.gz | $(RPMDST)`;\
	echo mv $$RPM_DST -t . ;\
	mv $$RPM_DST -t . 

