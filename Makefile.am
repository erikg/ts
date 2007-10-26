# *****************************************************************************
# * timestamp - time stamp pipe                                               *
# *                                                                           *
# * Copyright (C) 2003-2007 Erik Greenwald <erik@smluc.org>                   *
# * All Rights Reserved.                                                      *
# *                                                                           *
# * Redistribution and use in source and binary forms, with or without        *
# * modification, are permitted provided that the following conditions are    *
# * met:                                                                      *
# *                                                                           *
# * 1. Redistributions of source code must retain the above copyright notice, *
# *    this list of conditions and the following disclaimer.                  *
# * 2. Redistributions in binary form must reproduce the above copyright      *
# *    notice, this list of conditions and the following disclaimer in the    *
# *    documentation and/or other materials provided with the distribution.   *
# * 3. The name of the author may not be used to endorse or promote products  *
# *    derived from this software without specific prior written permission.  *
# *                                                                           *
# * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR      * 
# * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES *
# * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.   *
# * IN  NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,         *
# * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *
# * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, *
# * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY     *
# * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT       *
# * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  *
# * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.         *
# *                                                                           *
# \***************************************************************************/
#
# $Id: Makefile.am,v 1.19 2007/10/26 21:32:10 erik Exp $

bin_PROGRAMS=ts
ts_SOURCES = help.c opt.c stamp.c ts.c
noinst_HEADERS = help.h opt.h stamp.h
dist_man_MANS=ts.1

EXTRA_DIST=ChangeLog $(PACKAGE).spec.in install-sh

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
	-for file in $(SOURCES) $(HEADERS) ; do splint +posixlib $(CPPFLAGS) $$file > $$file.lint && \
		if [ ! -s $$file.lint ] ; then rm $$file.lint ; fi ; done
	ls -l *.lint
indent:
	gindent $(SOURCES) $(HEADERS)
flawfinder:
	flawfinder $(SOURCES) $(HEADERS)

docs:
	doxygen doxygen.conf
	make -C doxygen/latex 
	dvips -f doxygen/latex/refman.dvi > refman.ps
	ps2pdf refman.ps

