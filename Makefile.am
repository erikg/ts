
# $Id: Makefile.am,v 1.13 2005/03/14 01:02:09 erik Exp $

bin_PROGRAMS=ts
ts_SOURCES = help.c opt.c stamp.c ts.c
noinst_HEADERS = help.h opt.h stamp.h
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
	for file in $(SOURCES) $(HEADERS) ; do splint $(CPPFLAGS) $$file > $$file.lint ; done
	make lint
indent:
	gindent $(SOURCES) $(HEADERS)

docs:
	doxygen doxygen.conf
	make -C doxygen/latex 
	dvips -f doxygen/latex/refman.dvi > refman.ps
	ps2pdf refman.ps

