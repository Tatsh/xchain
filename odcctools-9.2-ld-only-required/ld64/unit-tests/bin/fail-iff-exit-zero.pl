#!/usr/bin/perl -w

#
# Usage:
#
#		${FALL_IFF} command
#

use strict;

my $test_name = "";
if ( exists $ENV{UNIT_TEST_NAME} ) {
	$test_name = $ENV{UNIT_TEST_NAME};
}

if(0 == system(@ARGV))
{
    printf("FAIL $test_name\n");
}
else
{
    printf("PASS $test_name\n");
}
exit 0;

