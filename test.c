
/****************************************************************************\
 * timestamp - time stamp pipe                                               *
 *                                                                           *
 * Copyright (C) 2004 Erik Greenwald <erik@smluc.org>                        *
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
 * $Id: test.c,v 1.1 2004/03/03 14:11:36 erik Exp $
 */

#ifndef lint
static const char rcsid[] = "$Id: test.c,v 1.1 2004/03/03 14:11:36 erik Exp $";
#endif

#include <stdio.h>
#include <stdlib.h>
#include <check.h>

/*
    fail_unless(expr,msg);
    fail(msg);
* char *parse_opts (int argc, char **argv);
* int stamp (char *format);
*
*/

START_TEST (test_parse_opts)
END_TEST

START_TEST (test_stamp)
END_TEST

Suite *
ts_opt_suite (void)
{
    Suite *s = suite_create ("opt.c");
    TCase *tc_opt = tcase_create ("opt");

    suite_add_tcase (s, tc_opt);

    tcase_add_test (tc_opt, test_parse_opts);
    return s;
}

Suite *
ts_stamp_suite (void)
{
    Suite *s = suite_create ("stamp.c");
    TCase *tc_stamp = tcase_create ("stamp");

    suite_add_tcase (s, tc_stamp);

    tcase_add_test (tc_stamp, test_stamp);
    return s;
}

int
main (void)
{
    int nf;
    Suite *s = ts_opt_suite ();
    SRunner *sr = srunner_create (s);

    srunner_run_all (sr, CK_NORMAL);
    nf = srunner_ntests_failed (sr);
    srunner_free (sr);
    suite_free (s);

    s = ts_stamp_suite ();
    sr = srunner_create (s);

    srunner_run_all (sr, CK_NORMAL);
    nf = srunner_ntests_failed (sr);
    srunner_free (sr);
    suite_free (s);
    return (nf == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
