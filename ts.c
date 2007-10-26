
/****************************************************************************\
 * timestamp - time stamp pipe                                               *
 *                                                                           *
 * Copyright (C) 2003-2007 Erik Greenwald <erik@smluc.org> All Rights        *
 * Reserved.                                                                 *
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
 * $Id: ts.c,v 1.15 2007/10/26 06:03:51 erik Exp $
 *                                                                           *
 \***************************************************************************/

#ifndef lint
/*@unused@*/static const char rcsid[] = "$Id: ts.c,v 1.15 2007/10/26 06:03:51 erik Exp $";
#endif

#include <stdio.h>
#include <stdlib.h>

#include "opt.h"
#include "stamp.h"

/**
 * Entry point for timestamp.
 * @param argc Number of arguments.
 * @param argv Argument vector.
 * @return Exit status.
 */
int
main (int argc, char **argv)
{
    char *format;

    format = parse_opts (argc, argv);

    if (format == NULL) {
	fprintf(stderr, "Unable to parse format\n");
	return EXIT_FAILURE;
    }

    if(stamp (format) > 0) {
	fprintf(stderr,"Error timestamping\n");
	return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
