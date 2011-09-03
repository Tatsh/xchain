#!/usr/bin/perl -w

#
# Usage:
#
#		${PASS_UNLESS} "test name" command
#

use strict;

my $string = shift @ARGV;

if(0 == system(@ARGV))
{
    printf("FAIL $string\n");
}
else
{
    printf("PASS $string\n");
}
exit 0;

