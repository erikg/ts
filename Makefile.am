
# $Id: Makefile.am,v 1.5 2003/02/14 18:59:56 erik Exp $

bin_PROGRAMS=ts
ts_SOURCES=ts.c

EXTRA_DIST=ChangeLog $(PACKAGE).spec
 
.PHONY : rpm
rpm: dist
	cp $(PACKAGE)-$(VERSION).tar.gz /usr/src/redhat/SOURCES/
	rpm -ba $(PACKAGE).spec
	cp /usr/src/redhat/RPMS/i386/$(PACKAGE)-$(VERSION)-*.i386.rpm .
	cp /usr/src/redhat/SRPMS/$(PACKAGE)-$(VERSION)-*.src.rpm .
 
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

