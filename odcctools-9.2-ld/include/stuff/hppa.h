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
#if defined(__MWERKS__) && !defined(__private_extern__)
#define __private_extern__ __declspec(private_extern)
#endif

extern void calc_hppa_HILO(
    unsigned long base,
    unsigned long offset,
    unsigned long *left21,
    unsigned long *right14);

extern unsigned long assemble_17(
    unsigned long x,
    unsigned long y,
    unsigned long z);

extern unsigned long assemble_21(
    unsigned long x);

extern unsigned long assemble_12(
    unsigned long x,
    unsigned long y);

extern unsigned long assemble_3(
    unsigned long x);

extern unsigned long sign_ext(
    unsigned long x,
    unsigned long len);

extern unsigned long low_sign_ext(
    unsigned long x,
    unsigned long len);

extern unsigned long dis_assemble_21(
    unsigned long as21);

extern unsigned long low_sign_unext(
    unsigned long x,
    unsigned long len);

extern void dis_assemble_17(
    unsigned long as17,
    unsigned long *x,
    unsigned long *y,
    unsigned long *z);

extern unsigned long sign_unext(
    unsigned long x,
    unsigned long len);

extern unsigned long dis_assemble_3(
    unsigned long x);

extern void dis_assemble_12(
    unsigned long as12,
    unsigned long *x,
    unsigned long *y);
