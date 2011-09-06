/*
 * Copyright (c) 1999 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
#ifndef RLD
#include "config.h"
#include <libc.h> /* first to get rid of pre-comp warning */
#include <mach/mach.h> /* first to get rid of pre-comp warning */
#include "stdio.h"
#include <signal.h>
#include <sys/wait.h>
#include <sys/file.h>
#include "stuff/errors.h"
#include "stuff/allocate.h"
#include "stuff/execute.h"
#include "mach-o/dyld.h"

/*
 * execute() does an execvp using the argv passed to it.  If the parameter
 * verbose is non-zero the command is printed to stderr.  A non-zero return
 * value indicates success zero indicates failure.
 */
__private_extern__
int
execute(
char **argv,
int verbose)
{
    char *name, **p;
    int forkpid, waitpid, termsig;
#ifndef __OPENSTEP__
    int waitstatus;
#else
    union wait waitstatus;
#endif

    name = argv[0];

	if(verbose){
	    fprintf(stderr, "+ %s ", name);
	    p = &(argv[1]);
	    while(*p != (char *)0)
		    fprintf(stderr, "%s ", *p++);
	    fprintf(stderr, "\n");
	}

	forkpid = fork();
	if(forkpid == -1)
	    system_fatal("can't fork a new process to execute: %s", name);

	if(forkpid == 0){
	    if(execvp(name, argv) == -1)
		system_fatal("can't find or exec: %s", name);
	    return(1); /* can't get here, removes a warning from the compiler */
	}
	else{
	    waitpid = wait(&waitstatus);
	    if(waitpid == -1)
		system_fatal("wait on forked process %d failed", forkpid);
#ifndef __OPENSTEP__
	    termsig = WTERMSIG(waitstatus);
#else
	    termsig = waitstatus.w_termsig;
#endif
	    if(termsig != 0 && termsig != SIGINT)
		fatal("fatal error in %s", name);
	    return(
#ifndef __OPENSTEP__
		WEXITSTATUS(waitstatus) == 0 &&
#else
		waitstatus.w_retcode == 0 &&
#endif
		termsig == 0);
	}
}

/*
 * runlist is used by the routine execute_list() to execute a program and it 
 * contains the command line arguments.  Strings are added to it by
 * add_execute_list().  The routine reset_execute_list() resets it for new use.
 */
static struct {
    int size;
    int next;
    char **strings;
} runlist;

/*
 * This routine is passed a string to be added to the list of strings for 
 * command line arguments.
 */
__private_extern__
void
add_execute_list(
char *str)
{
	if(runlist.strings == (char **)0){
	    runlist.next = 0;
	    runlist.size = 128;
	    runlist.strings = allocate(runlist.size * sizeof(char **));
	}
	if(runlist.next + 1 >= runlist.size){
	    runlist.strings = reallocate(runlist.strings,
				(runlist.size * 2) * sizeof(char **));
	    runlist.size *= 2;
	}
	runlist.strings[runlist.next++] = str;
	runlist.strings[runlist.next] = (char *)0;
}

/*
 * This routine is passed a string to be added to the list of strings for 
 * command line arguments and is then prefixed with the path of the executable.
 */
__private_extern__
void
add_execute_list_with_prefix(
char *str)
{
	add_execute_list(cmd_with_prefix(str));
}

#ifndef HAVE__NSGETEXECUTABLEPATH
/**
 * Based on MonetDB's get_bin_path
 * http://dev.monetdb.org/hg/MonetDB/file/54ad354daff8/common/utils/mutils.c#l340
 */
int _NSGetExecutablePath(char *buf, unsigned long *bufsize) {
#if defined(_MSC_VER)
	if (GetModuleFileName(NULL, buf, (DWORD)*bufsize) != 0) {
		return strlen;
	}
	return -1;
#elif defined(HAVE_READLINK) /* Linux */
	return readlink("/proc/self/exe", buf, *bufsize);
#else
	return -1; /* Fail on all other systems for now */
#endif /* _MSC_VER */
}
#endif/* HAVE__NSGETEXECUTABLEPATH */

/*
 * This routine is passed a string of a command name and a string is returned
 * prefixed with the path of the executable and that command name.
 */
__private_extern__
char *
cmd_with_prefix(
char *str)
{
	int i;
	char *p;
	char *prefix, buf[MAXPATHLEN], resolved_name[PATH_MAX];
	unsigned long bufsize;
	
	/*
	 * Construct the prefix to the program running.
	 */
	bufsize = MAXPATHLEN;
	p = buf;
	memset(p, 0, MAXPATHLEN);
	memset(resolved_name, 0, PATH_MAX);
	i = _NSGetExecutablePath(p, &bufsize);
	if(i == -1){
	    p = allocate(bufsize);
	    _NSGetExecutablePath(p, &bufsize);
	}
	prefix = realpath(p, resolved_name);
	p = rindex(prefix, '/');
	if(p != NULL)
	    p[1] = '\0';

#if defined(__APPLE__)
	return(makestr(prefix, str, NULL));
#else
	return makestr(prefix, CROSS_BIN_PREFIX, "-", str, NULL);
#endif
}

/*
 * This routine reset the list of strings of command line arguments so that
 * an new command line argument list can be built.
 */
__private_extern__
void
reset_execute_list(void)
{
	runlist.next = 0;
}

/*
 * This routine calls execute() to run the command built up in the runlist
 * strings.
 */
__private_extern__
int
execute_list(
int verbose)
{
	return(execute(runlist.strings, verbose));
}
#endif /* !defined(RLD) */
