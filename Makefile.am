
# $Id: Makefile.am,v 1.8 2003/02/15 02:04:07 erik Exp $

bin_PROGRAMS=ts
ts_SOURCES=ts.c
man_MANS=ts.1

EXTRA_DIST=ChangeLog $(PACKAGE).spec $(man_MANS)
 
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

