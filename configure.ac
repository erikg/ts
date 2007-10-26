dnl $Id: configure.ac,v 1.3 2007/10/26 20:55:15 erik Exp $

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
