
/****************************************************************************\
 * timestamp - time stamp pipe                                               *
 *                                                                           *
 * Copyright (C) 2003 Erik Greenwald <erik@smluc.org> All Rights Reserved.   *
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
 * $Id: ts.c,v 1.8 2003/02/15 16:15:35 erik Exp $
 *                                                                           *
 \***************************************************************************/

#ifndef lint
static char const copyright[] =
"@(#) Copyright (c) 2003\n\
	Erik Greenwald <erik@smluc.org>.  All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static const char rcsid[] =
  "$Id: ts.c,v 1.8 2003/02/15 16:15:35 erik Exp $";
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

void version(FILE *f, char *name)
{
	fprintf(f,"%s (%s) %s  (C) 2003 Erik Greenwald <erik@smluc.org>\n %s\n", name, PACKAGE, VERSION, rcsid);
	return;	
}

void usage(FILE *f,char *name)
{
	version(f,name);
	fprintf(f,"Usage:\n\t%s [-u] [-v|-h] [+val[ymwdHMS]]\n", name);
	return;
}

int main(int argc, char **argv)
{
	int ch=0, utc=0, a=0;
	char buf[1024], *format, c;
	struct tm lt;
	time_t tval;
	
	format="%Y%m%d%H%M%S: ";

	while((ch=getopt(argc, argv, "uvh"))!=-1)
		switch(ch)
		{
			case 'u':
#if defined(HAVE_SETENV)
				setenv("TZ", "UTC0", 1);
#elif defined(HAVE_PUTENV)
				putenv("TZ=UTC");
#else
				printf("No support for setting env TZ=UTC. Aborting\n");
				exit(EXIT_FAILURE);
#endif
				break;
			case 'h':
				usage(stdout, argv[0]);
				return EXIT_SUCCESS;
			case 'v':
				version(stdout, argv[0]);
				return EXIT_SUCCESS;
			default:
				usage(stderr,argv[0]);
				return EXIT_FAILURE;
		}
	argc -= optind;
	argv += optind;

	if (*argv && **argv == '+') {
		format = *argv + 1;
		++argv;
	}

	while(read(STDIN_FILENO, &c, 1)==1)
	{
		static int stamplen = 0;
		if(a==0)
		{
			if(c == '\r')
				continue;
			time(&tval);
			lt = *localtime(&tval);
			strftime(buf, sizeof(buf), format, &lt);
			stamplen = strlen(buf);
			write(STDOUT_FILENO, buf, stamplen);
			a=1;
		}
		write(STDOUT_FILENO, &c, 1);
		switch(c)
		{
		case '\n':
			a=0;
			break;
		case '\r':
			write(STDOUT_FILENO, buf, stamplen);
			break;
		default:
			break;
		}
	}

	return 0;
}
