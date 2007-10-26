
/****************************************************************************\
 * timestamp - time stamp pipe                                               *
 *                                                                           *
 * Copyright (C) 2003-2007 Erik Greenwald <erik@smluc.org>                   *
 * All Rights Reserved.                                                      *
 *                                                                           *
 * Redistribution and use in source and binary forms, with or without        *
 * modification, are permitted provided that the following conditions are    *
 * met:                                                                      *
 *                                                                           *
 * 1. Redistributions of source code must retain the above copyright notice, *
 *    this list of conditions and the following disclaimer.                  *
 * 2. Redistributions in binary form must reproduce the above copyright      *
 *    notice, this list of conditions and the following disclaimer in the    *
 *    documentation and/or other materials provided with the distribution.   *
 * 3. The name of the author may not be used to endorse or promote products  *
 *    derived from this software without specific prior written permission.  *
 *                                                                           *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR      * 
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES *
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.   *
 * IN  NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,         *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, *
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY     *
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT       *
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  *
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.         *
 *                                                                           *
 \***************************************************************************/

/*
 * $Id: opt.c,v 1.3 2007/10/26 04:48:29 erik Exp $
 */

#ifndef lint
static const char rcsid[] = "$Id: opt.c,v 1.3 2007/10/26 04:48:29 erik Exp $";
#endif

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "help.h"

/**
 * Parse the command line parameters.
 * @param argc Number of arguments.
 * @param argv The argument vector.
 * @return The date format.
 */
char *
parse_opts (int argc, char **argv)
{
    char *format;
    int ch = 0;

    format = "%Y%m%d%H%M%S: ";
    while ((ch = getopt (argc, argv, "uvh")) != -1)
	switch (ch)
	  {
	  case 'u':
#if defined(HAVE_SETENV)
	      setenv ("TZ", "UTC0", 1);
#elif defined(HAVE_PUTENV)
	      putenv ("TZ=UTC");
#else
	      printf ("No support for setting env TZ=UTC. Aborting\n");
	      exit (EXIT_FAILURE);
#endif
	      break;
	  case 'h':
	      usage (stdout, argv[0]);
	      exit (EXIT_SUCCESS);
	  case 'v':
	      version (stdout, argv[0]);
	      exit (EXIT_SUCCESS);
	  default:
	      usage (stderr, argv[0]);
	      exit (EXIT_FAILURE);
	  }
    argc -= optind;
    argv += optind;

    if (*argv && **argv == '+')
      {
	  format = *argv + 1;
	  ++argv;
      }
    return format;
}
