/*
*/

#ifndef lint
static char const copyright[] =
"@(#) Copyright (c) 2003\n\
	Erik Greenwald <erik@smluc.org>.  All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static const char rcsid[] =
  "$Id: ts.c,v 1.3 2003/02/14 18:50:39 erik Exp $";
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	char buf[1024], *format;
	struct tm lt;
	time_t tval;
	
	format="%Y%m%d%H%M%S: ";

	while((ch=getopt(argc, argv, "uvh"))!=-1)
		switch(ch)
		{
			case 'u':
				setenv("TZ", "UTC0", 1);
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

	while(read(STDIN_FILENO, &ch, 1)==1)
	{
		if(a==0)
		{
			time(&tval);
			lt = *localtime(&tval);
			strftime(buf, sizeof(buf), format, &lt);
			write(STDOUT_FILENO, buf, strlen(buf));
			a=1;
		}
		write(STDOUT_FILENO, &ch, 1);
		if((char)ch=='\n')
			a=0;
	}

	return 0;
}
