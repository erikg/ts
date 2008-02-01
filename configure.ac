# *****************************************************************************
# * timestamp - time stamp pipe                                               *
# *                                                                           *
# * Copyright (C) 2003-2008 Erik Greenwald <erik@smluc.org>                   *
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
# $Id: configure.ac,v 1.5 2008/02/01 20:11:46 erik Exp $

AC_INIT(ts.c)
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE(timestamp, 1.2)

AC_PROG_CC
AC_PROG_INSTALL
AC_C_CONST
AC_CHECK_HEADERS(time.h)

AC_CHECK_FUNC(setenv,AC_DEFINE(HAVE_SETENV,,UNIX style environment setting))
AC_CHECK_FUNC(putenv,AC_DEFINE(HAVE_PUTENV,,BSD style environment setting))
AC_FUNC_STRFTIME

AC_CONFIG_FILES(Makefile timestamp.spec doxygen.conf)
AC_OUTPUT
