/*
 * Copyright (c) 2000-2002 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*
 * Copyright (c) 1992 NeXT Computer, Inc.
 *
 */

#ifndef	_ARM_SIGNAL_
#define	_ARM_SIGNAL_ 1

#ifndef _ANSI_SOURCE
typedef int sig_atomic_t; 

#ifndef _POSIX_C_SOURCE

#include <sys/appleapiopts.h>

#ifdef __APPLE_API_OBSOLETE

/*
 * Information pushed on stack when a signal is delivered.
 * This is used by the kernel to restore state following
 * execution of the signal handler.  It is also made available
 * to the handler to allow it to properly restore state if
 * a non-standard exit is performed.
 */
struct	sigcontext {
    int			sc_onstack;	/* sigstack state to restore */
    int			sc_mask;	/* signal mask to restore */
    unsigned int    sc_r0;
    unsigned int    sc_r1;
    unsigned int    sc_r2;
    unsigned int    sc_r3;
    unsigned int    sc_r4;
    unsigned int    sc_r5;
    unsigned int    sc_r6;
    unsigned int    sc_r7;
    unsigned int    sc_r8;
    unsigned int    sc_r9;
    unsigned int    sc_r10;
    unsigned int    sc_r11;
    unsigned int    sc_r12;
    unsigned int    sc_r13;
    unsigned int    sc_r14;
    unsigned int    sc_r15;
    unsigned int    sc_r16;
};

#endif /* __APPLE_API_OBSOLETE */
#endif /* ! _POSIX_C_SOURCE */
#endif /* ! _ANSI_SOURCE */

#endif	/* _ARM_SIGNAL_ */

