
/****************************************************************************\
 * timestamp - time stamp pipe                                               *
 *                                                                           *
 * Copyright (C) 2003-2004 Erik Greenwald <erik@smluc.org>                   *
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
 * $Id: stamp.c,v 1.1 2004/03/03 14:13:18 erik Exp $
 */

#ifndef lint
static const char rcsid[] = "$Id: stamp.c,v 1.1 2004/03/03 14:13:18 erik Exp $";
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "config.h"

/**
 * Do the pipe operation. Time is taken on the first character of a line.
 * Carraige returns are ignored. Input is taken from stdin and sent to stdout.
 * @param format The date format to use.
 * @return Always 0.
 */
int
stamp (char *format)
{
    char buf[1024];
    char c = 0, a = 0;
    struct tm lt;
    time_t tval;

    while (read (STDIN_FILENO, &c, 1) == 1)
      {
	  static int stamplen = 0;

	  if (a == 0)
	    {
		if (c == '\r')
		    continue;
		time (&tval);
		lt = *localtime (&tval);
		strftime (buf, sizeof (buf), format, &lt);
		stamplen = strlen (buf);
		write (STDOUT_FILENO, buf, stamplen);
		a = 1;
	    }
	  write (STDOUT_FILENO, &c, 1);
	  switch (c)
	    {
	    case '\n':
		a = 0;
		break;
	    case '\r':
		write (STDOUT_FILENO, buf, stamplen);
		break;
	    default:
		break;
	    }
      }
    return 0;
}
