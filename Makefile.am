
# $Id: Makefile.am,v 1.11 2004/03/03 14:11:36 erik Exp $

bin_PROGRAMS=ts tstest
ts_SOURCES = help.c opt.c stamp.c ts.c
tstest_SOURCES =  help.c opt.c stamp.c test.c
tstest_CFLAGS = @CHECK_CFLAGS@
tstest_LDADD = @CHECK_LIBS@
dist_man_MANS=ts.1

EXTRA_DIST=ChangeLog $(PACKAGE).spec.in

.PHONY : rpm
rpm: dist
	cp $(PACKAGE)-$(VERSION).tar.gz ${HOME}/rpm/SOURCES/
	rpmbuild -ba $(PACKAGE).spec
	cp ${HOME}/rpm/RPMS/i386/$(PACKAGE)-$(VERSION)-*.i386.rpm .
	cp ${HOME}/rpm/SRPMS/$(PACKAGE)-$(VERSION)-*.src.rpm .

.PHONY : deb
deb:
	debian/rules
	debuild
	debc
	debi
	release

packages: rpm

lint:
	make -C src lint
indent:
	make -C src indent

docs:
	doxygen doxygen.conf
	make -C doxygen/latex 
	dvips -f doxygen/latex/refman.dvi > refman.ps
	ps2pdf refman.ps

test: tstest
	./tstest

