dnl $Id: configure.ac,v 1.2 2007/10/26 06:27:39 erik Exp $
AC_INIT(ts.c)
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE(timestamp, 1.1)

AC_PROG_CC
AC_PROG_INSTALL
AC_C_CONST
AC_CHECK_HEADERS(stdio.h stdlib.h string.h time.h unistd.h)

AC_CHECK_FUNC(setenv,AC_DEFINE(HAVE_SETENV,,UNIX style environment setting))
AC_CHECK_FUNC(putenv,AC_DEFINE(HAVE_PUTENV,,BSD style environment setting))
AC_FUNC_STRFTIME

AC_OUTPUT(Makefile timestamp.spec doxygen.conf)
