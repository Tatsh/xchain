/*
 * Copyright (c) 2004-2006 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 * 
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */
/*
 * @OSF_COPYRIGHT@
 */

#ifndef	_MACH_I386__STRUCTS_H_
#define	_MACH_I386__STRUCTS_H_

#if __DARWIN_UNIX03
#define i386_exception_state __darwin_i386_exception_state 
#define i386_float_state __darwin_i386_float_state 
#define i386_thread_state __darwin_i386_thread_state
#define __cr cr
#define __ctr ctr
#define __dar dar
#define __dsisr dsisr
#define __exception exception
#define __fpregs fpregs
#define __fpscr fpscr
#define __fpscr_pad fpscr_pad
#define __lr lr
#define __mq mq
#define __pad0 pad0
#define __pad1 pad1
#define __r0 r0
#define __r1 r1
#define __r10 r10
#define __r11 r11
#define __r12 r12
#define __r13 r13
#define __r14 r14
#define __r15 r15
#define __r16 r16
#define __r17 r17
#define __r18 r18
#define __r19 r19
#define __r2 r2
#define __r20 r20
#define __r21 r21
#define __r22 r22
#define __r23 r23
#define __r24 r24
#define __r25 r25
#define __r26 r26
#define __r27 r27
#define __r28 r28
#define __r29 r29
#define __r3 r3
#define __r30 r30
#define __r31 r31
#define __r4 r4
#define __r5 r5
#define __r6 r6
#define __r7 r7
#define __r8 r8
#define __r9 r9
#define __srr0 srr0
#define __srr1 srr1
#define __vrsave vrsave
#define __xer xer
#define __busy busy
#define __c0 c0
#define __c1 c1
#define __c2 c2
#define __c3 c3
#define __cs cs
#define __darwin_fp_control fp_control
#define __darwin_fp_status fp_status
#define __darwin_mmst_reg mmst_reg
#define __darwin_xmm_reg xmm_reg
#define __denorm denorm
#define __ds ds
#define __eax eax
#define __ebp ebp
#define __ebx ebx
#define __ecx ecx
#define __edi edi
#define __edx edx
#define __eflags eflags
#define __eip eip
#define __err err
#define __errsumm errsumm
#define __es es
#define __esi esi
#define __esp esp
#define __faultvaddr faultvaddr
#define __fpu_cs fpu_cs
#define __fpu_dp fpu_dp
#define __fpu_ds fpu_ds
#define __fpu_fcw fpu_fcw
#define __fpu_fop fpu_fop
#define __fpu_fsw fpu_fsw
#define __fpu_ftw fpu_ftw
#define __fpu_ip fpu_ip
#define __fpu_mxcsr fpu_mxcsr
#define __fpu_mxcsrmask fpu_mxcsrmask
#define __fpu_reserved fpu_reserved
#define __fpu_reserved1 fpu_reserved1
#define __fpu_rsrv1 fpu_rsrv1
#define __fpu_rsrv2 fpu_rsrv2
#define __fpu_rsrv3 fpu_rsrv3
#define __fpu_rsrv4 fpu_rsrv4
#define __fpu_stmm0 fpu_stmm0
#define __fpu_stmm1 fpu_stmm1
#define __fpu_stmm2 fpu_stmm2
#define __fpu_stmm3 fpu_stmm3
#define __fpu_stmm4 fpu_stmm4
#define __fpu_stmm5 fpu_stmm5
#define __fpu_stmm6 fpu_stmm6
#define __fpu_stmm7 fpu_stmm7
#define __fpu_xmm0 fpu_xmm0
#define __fpu_xmm1 fpu_xmm1
#define __fpu_xmm2 fpu_xmm2
#define __fpu_xmm3 fpu_xmm3
#define __fpu_xmm4 fpu_xmm4
#define __fpu_xmm5 fpu_xmm5
#define __fpu_xmm6 fpu_xmm6
#define __fpu_xmm7 fpu_xmm7
#define __fpu_xmm8 fpu_xmm8
#define __fpu_xmm9 fpu_xmm9
#define __fpu_xmm10 fpu_xmm10
#define __fpu_xmm11 fpu_xmm11
#define __fpu_xmm12 fpu_xmm12
#define __fpu_xmm13 fpu_xmm13
#define __fpu_xmm14 fpu_xmm14
#define __fpu_xmm15 fpu_xmm15
#define __fs fs
#define __gs gs
#define __invalid invalid
#define __mmst_reg mmst_reg
#define __mmst_rsrv mmst_rsrv
#define __ovrfl ovrfl
#define __pc pc
#define __precis precis
#define __rc rc
#define __ss ss
#define __stkflt stkflt
#define __tos tos
#define __trapno trapno
#define __undfl undfl
#define __xmm_reg xmm_reg
#define __zdiv zdiv

#define __rax rax
#define __rbx rbx
#define __rcx rcx
#define __rdx rdx
#define __rdi rdi
#define __rsi rsi
#define __rbp rbp
#define __rsp rsp
#define __r8 r8
#define __r9 r9
#define __r10 r10
#define __r11 r11
#define __r12 r12
#define __r13 r13
#define __r14 r14
#define __r15 r15
#define __rip rip
#define __rflags rflags

#define __dr0 dr0
#define __dr1 dr1
#define __dr2 dr2
#define __dr3 dr3
#define __dr4 dr4
#define __dr5 dr5
#define __dr6 dr6
#define __dr7 dr7

#else

#define __darwin_i386_exception_state i386_exception_state
#define __darwin_i386_float_state i386_float_state
#define __darwin_i386_thread_state i386_thread_state

#endif

#include <stdint.h>
#define __uint8_t uint8_t
#define __uint16_t uint16_t
#define __uint32_t uint32_t
#define __uint64_t uint64_t

/*
 * i386 is the structure that is exported to user threads for 
 * use in status/mutate calls.  This structure should never change.
 *
 */

#if __DARWIN_UNIX03
#define	_STRUCT_X86_THREAD_STATE32	struct __darwin_i386_thread_state
_STRUCT_X86_THREAD_STATE32
{
    unsigned int    __eax;
    unsigned int	__ebx;
    unsigned int	__ecx;
    unsigned int	__edx;
    unsigned int	__edi;
    unsigned int	__esi;
    unsigned int	__ebp;
    unsigned int	__esp;
    unsigned int	__ss;
    unsigned int	__eflags;
    unsigned int	__eip;
    unsigned int	__cs;
    unsigned int	__ds;
    unsigned int	__es;
    unsigned int	__fs;
    unsigned int	__gs;
};
#else /* !__DARWIN_UNIX03 */
#define	_STRUCT_X86_THREAD_STATE32	struct i386_thread_state
_STRUCT_X86_THREAD_STATE32
{
    unsigned int	eax;
    unsigned int	ebx;
    unsigned int	ecx;
    unsigned int	edx;
    unsigned int	edi;
    unsigned int	esi;
    unsigned int	ebp;
    unsigned int	esp;
    unsigned int	ss;
    unsigned int	eflags;
    unsigned int	eip;
    unsigned int	cs;
    unsigned int	ds;
    unsigned int	es;
    unsigned int	fs;
    unsigned int	gs;
};
#endif /* !__DARWIN_UNIX03 */

/* This structure should be double-word aligned for performance */

#if __DARWIN_UNIX03
#define _STRUCT_FP_CONTROL	struct __darwin_fp_control
_STRUCT_FP_CONTROL
{
    unsigned short		__invalid	:1,
    				__denorm	:1,
				__zdiv		:1,
				__ovrfl		:1,
				__undfl		:1,
				__precis	:1,
						:2,
				__pc		:2,
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define FP_PREC_24B		0
#define	FP_PREC_53B		2
#define FP_PREC_64B		3
#endif /* !_POSIX_C_SOURCE || _DARWIN_C_SOURCE */
				__rc		:2,
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define FP_RND_NEAR		0
#define FP_RND_DOWN		1
#define FP_RND_UP		2
#define FP_CHOP			3
#endif /* !_POSIX_C_SOURCE || _DARWIN_C_SOURCE */
					/*inf*/	:1,
						:3;
};
typedef _STRUCT_FP_CONTROL	__darwin_fp_control_t;
#else /* !__DARWIN_UNIX03 */
#define _STRUCT_FP_CONTROL	struct fp_control
_STRUCT_FP_CONTROL
{
    unsigned short		invalid	:1,
    				denorm	:1,
				zdiv	:1,
				ovrfl	:1,
				undfl	:1,
				precis	:1,
					:2,
				pc	:2,
#define FP_PREC_24B		0
#define	FP_PREC_53B		2
#define FP_PREC_64B		3
				rc	:2,
#define FP_RND_NEAR		0
#define FP_RND_DOWN		1
#define FP_RND_UP		2
#define FP_CHOP			3
				/*inf*/	:1,
					:3;
};
typedef _STRUCT_FP_CONTROL	fp_control_t;
#endif /* !__DARWIN_UNIX03 */

/*
 * Status word.
 */

#if __DARWIN_UNIX03
#define _STRUCT_FP_STATUS	struct __darwin_fp_status
_STRUCT_FP_STATUS
{
    unsigned short		__invalid	:1,
    				__denorm	:1,
				__zdiv		:1,
				__ovrfl		:1,
				__undfl		:1,
				__precis	:1,
				__stkflt	:1,
				__errsumm	:1,
				__c0		:1,
				__c1		:1,
				__c2		:1,
				__tos		:3,
				__c3		:1,
				__busy		:1;
};
typedef _STRUCT_FP_STATUS	__darwin_fp_status_t;
#else /* !__DARWIN_UNIX03 */
#define _STRUCT_FP_STATUS	struct fp_status
_STRUCT_FP_STATUS
{
    unsigned short		invalid	:1,
    				denorm	:1,
				zdiv	:1,
				ovrfl	:1,
				undfl	:1,
				precis	:1,
				stkflt	:1,
				errsumm	:1,
				c0	:1,
				c1	:1,
				c2	:1,
				tos	:3,
				c3	:1,
				busy	:1;
};
typedef _STRUCT_FP_STATUS	fp_status_t;
#endif /* !__DARWIN_UNIX03 */
				
/* defn of 80bit x87 FPU or MMX register  */

#if __DARWIN_UNIX03
#define _STRUCT_MMST_REG	struct __darwin_mmst_reg
_STRUCT_MMST_REG
{
	char	__mmst_reg[10];
	char	__mmst_rsrv[6];
};
#else /* !__DARWIN_UNIX03 */
#define _STRUCT_MMST_REG	struct mmst_reg
_STRUCT_MMST_REG
{
	char	mmst_reg[10];
	char	mmst_rsrv[6];
};
#endif /* !__DARWIN_UNIX03 */


/* defn of 128 bit XMM regs */

#if __DARWIN_UNIX03
#define _STRUCT_XMM_REG		struct __darwin_xmm_reg
_STRUCT_XMM_REG
{
	char		__xmm_reg[16];
};
#else /* !__DARWIN_UNIX03 */
#define _STRUCT_XMM_REG		struct xmm_reg
_STRUCT_XMM_REG
{
	char		xmm_reg[16];
};
#endif /* !__DARWIN_UNIX03 */

/* 
 * Floating point state.
 */

#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define FP_STATE_BYTES		512	/* number of chars worth of data from fpu_fcw */
#endif /* !_POSIX_C_SOURCE || _DARWIN_C_SOURCE */

#if __DARWIN_UNIX03
#define	_STRUCT_X86_FLOAT_STATE32	struct __darwin_i386_float_state
_STRUCT_X86_FLOAT_STATE32
{
	int 			__fpu_reserved[2];
	_STRUCT_FP_CONTROL	__fpu_fcw;		/* x87 FPU control word */
	_STRUCT_FP_STATUS	__fpu_fsw;		/* x87 FPU status word */
	__uint8_t		__fpu_ftw;		/* x87 FPU tag word */
	__uint8_t		__fpu_rsrv1;		/* reserved */ 
	__uint16_t		__fpu_fop;		/* x87 FPU Opcode */
	__uint32_t		__fpu_ip;		/* x87 FPU Instruction Pointer offset */
	__uint16_t		__fpu_cs;		/* x87 FPU Instruction Pointer Selector */
	__uint16_t		__fpu_rsrv2;		/* reserved */
	__uint32_t		__fpu_dp;		/* x87 FPU Instruction Operand(Data) Pointer offset */
	__uint16_t		__fpu_ds;		/* x87 FPU Instruction Operand(Data) Pointer Selector */
	__uint16_t		__fpu_rsrv3;		/* reserved */
	__uint32_t		__fpu_mxcsr;		/* MXCSR Register state */
	__uint32_t		__fpu_mxcsrmask;	/* MXCSR mask */
	_STRUCT_MMST_REG	__fpu_stmm0;		/* ST0/MM0   */
	_STRUCT_MMST_REG	__fpu_stmm1;		/* ST1/MM1  */
	_STRUCT_MMST_REG	__fpu_stmm2;		/* ST2/MM2  */
	_STRUCT_MMST_REG	__fpu_stmm3;		/* ST3/MM3  */
	_STRUCT_MMST_REG	__fpu_stmm4;		/* ST4/MM4  */
	_STRUCT_MMST_REG	__fpu_stmm5;		/* ST5/MM5  */
	_STRUCT_MMST_REG	__fpu_stmm6;		/* ST6/MM6  */
	_STRUCT_MMST_REG	__fpu_stmm7;		/* ST7/MM7  */
	_STRUCT_XMM_REG		__fpu_xmm0;		/* XMM 0  */
	_STRUCT_XMM_REG		__fpu_xmm1;		/* XMM 1  */
	_STRUCT_XMM_REG		__fpu_xmm2;		/* XMM 2  */
	_STRUCT_XMM_REG		__fpu_xmm3;		/* XMM 3  */
	_STRUCT_XMM_REG		__fpu_xmm4;		/* XMM 4  */
	_STRUCT_XMM_REG		__fpu_xmm5;		/* XMM 5  */
	_STRUCT_XMM_REG		__fpu_xmm6;		/* XMM 6  */
	_STRUCT_XMM_REG		__fpu_xmm7;		/* XMM 7  */
	char			__fpu_rsrv4[14*16];	/* reserved */
	int 			__fpu_reserved1;
};
#else /* !__DARWIN_UNIX03 */
#define	_STRUCT_X86_FLOAT_STATE32	struct i386_float_state
_STRUCT_X86_FLOAT_STATE32
{
	int 			fpu_reserved[2];
	_STRUCT_FP_CONTROL	fpu_fcw;		/* x87 FPU control word */
	_STRUCT_FP_STATUS	fpu_fsw;		/* x87 FPU status word */
	__uint8_t		fpu_ftw;		/* x87 FPU tag word */
	__uint8_t		fpu_rsrv1;		/* reserved */ 
	__uint16_t		fpu_fop;		/* x87 FPU Opcode */
	__uint32_t		fpu_ip;			/* x87 FPU Instruction Pointer offset */
	__uint16_t		fpu_cs;			/* x87 FPU Instruction Pointer Selector */
	__uint16_t		fpu_rsrv2;		/* reserved */
	__uint32_t		fpu_dp;			/* x87 FPU Instruction Operand(Data) Pointer offset */
	__uint16_t		fpu_ds;			/* x87 FPU Instruction Operand(Data) Pointer Selector */
	__uint16_t		fpu_rsrv3;		/* reserved */
	__uint32_t		fpu_mxcsr;		/* MXCSR Register state */
	__uint32_t		fpu_mxcsrmask;		/* MXCSR mask */
	_STRUCT_MMST_REG	fpu_stmm0;		/* ST0/MM0   */
	_STRUCT_MMST_REG	fpu_stmm1;		/* ST1/MM1  */
	_STRUCT_MMST_REG	fpu_stmm2;		/* ST2/MM2  */
	_STRUCT_MMST_REG	fpu_stmm3;		/* ST3/MM3  */
	_STRUCT_MMST_REG	fpu_stmm4;		/* ST4/MM4  */
	_STRUCT_MMST_REG	fpu_stmm5;		/* ST5/MM5  */
	_STRUCT_MMST_REG	fpu_stmm6;		/* ST6/MM6  */
	_STRUCT_MMST_REG	fpu_stmm7;		/* ST7/MM7  */
	_STRUCT_XMM_REG		fpu_xmm0;		/* XMM 0  */
	_STRUCT_XMM_REG		fpu_xmm1;		/* XMM 1  */
	_STRUCT_XMM_REG		fpu_xmm2;		/* XMM 2  */
	_STRUCT_XMM_REG		fpu_xmm3;		/* XMM 3  */
	_STRUCT_XMM_REG		fpu_xmm4;		/* XMM 4  */
	_STRUCT_XMM_REG		fpu_xmm5;		/* XMM 5  */
	_STRUCT_XMM_REG		fpu_xmm6;		/* XMM 6  */
	_STRUCT_XMM_REG		fpu_xmm7;		/* XMM 7  */
	char			fpu_rsrv4[14*16];	/* reserved */
	int 			fpu_reserved1;
};
#endif /* !__DARWIN_UNIX03 */

#if __DARWIN_UNIX03
#define _STRUCT_X86_EXCEPTION_STATE32	struct __darwin_i386_exception_state
_STRUCT_X86_EXCEPTION_STATE32
{
    unsigned int	__trapno;
    unsigned int	__err;
    unsigned int	__faultvaddr;
};
#else /* !__DARWIN_UNIX03 */
#define _STRUCT_X86_EXCEPTION_STATE32	struct i386_exception_state
_STRUCT_X86_EXCEPTION_STATE32
{
    unsigned int	trapno;
    unsigned int	err;
    unsigned int	faultvaddr;
};
#endif /* !__DARWIN_UNIX03 */

#if __DARWIN_UNIX03
#define _STRUCT_X86_DEBUG_STATE32	struct __darwin_x86_debug_state32
_STRUCT_X86_DEBUG_STATE32
{
	unsigned int	__dr0;
	unsigned int	__dr1;
	unsigned int	__dr2;
	unsigned int	__dr3;
	unsigned int	__dr4;
	unsigned int	__dr5;
	unsigned int	__dr6;
	unsigned int	__dr7;
};
#else /* !__DARWIN_UNIX03 */
#define _STRUCT_X86_DEBUG_STATE32	struct x86_debug_state32
_STRUCT_X86_DEBUG_STATE32
{
	unsigned int	dr0;
	unsigned int	dr1;
	unsigned int	dr2;
	unsigned int	dr3;
	unsigned int	dr4;
	unsigned int	dr5;
	unsigned int	dr6;
	unsigned int	dr7;
};
#endif /* !__DARWIN_UNIX03 */

/*
 * 64 bit versions of the above
 */

#if __DARWIN_UNIX03
#define	_STRUCT_X86_THREAD_STATE64	struct __darwin_x86_thread_state64
_STRUCT_X86_THREAD_STATE64
{
	__uint64_t	__rax;
	__uint64_t	__rbx;
	__uint64_t	__rcx;
	__uint64_t	__rdx;
	__uint64_t	__rdi;
	__uint64_t	__rsi;
	__uint64_t	__rbp;
	__uint64_t	__rsp;
	__uint64_t	__r8;
	__uint64_t	__r9;
	__uint64_t	__r10;
	__uint64_t	__r11;
	__uint64_t	__r12;
	__uint64_t	__r13;
	__uint64_t	__r14;
	__uint64_t	__r15;
	__uint64_t	__rip;
	__uint64_t	__rflags;
	__uint64_t	__cs;
	__uint64_t	__fs;
	__uint64_t	__gs;
};
#else /* !__DARWIN_UNIX03 */
#define	_STRUCT_X86_THREAD_STATE64	struct x86_thread_state64
_STRUCT_X86_THREAD_STATE64
{
	__uint64_t	rax;
	__uint64_t	rbx;
	__uint64_t	rcx;
	__uint64_t	rdx;
	__uint64_t	rdi;
	__uint64_t	rsi;
	__uint64_t	rbp;
	__uint64_t	rsp;
	__uint64_t	r8;
	__uint64_t	r9;
	__uint64_t	r10;
	__uint64_t	r11;
	__uint64_t	r12;
	__uint64_t	r13;
	__uint64_t	r14;
	__uint64_t	r15;
	__uint64_t	rip;
	__uint64_t	rflags;
	__uint64_t	cs;
	__uint64_t	fs;
	__uint64_t	gs;
};
#endif /* !__DARWIN_UNIX03 */


#if __DARWIN_UNIX03
#define	_STRUCT_X86_FLOAT_STATE64	struct __darwin_x86_float_state64
_STRUCT_X86_FLOAT_STATE64
{
	int 			__fpu_reserved[2];
	_STRUCT_FP_CONTROL	__fpu_fcw;		/* x87 FPU control word */
	_STRUCT_FP_STATUS	__fpu_fsw;		/* x87 FPU status word */
	__uint8_t		__fpu_ftw;		/* x87 FPU tag word */
	__uint8_t		__fpu_rsrv1;		/* reserved */ 
	__uint16_t		__fpu_fop;		/* x87 FPU Opcode */

	/* x87 FPU Instruction Pointer */
	__uint32_t		__fpu_ip;		/* offset */
	__uint16_t		__fpu_cs;		/* Selector */

	__uint16_t		__fpu_rsrv2;		/* reserved */

	/* x87 FPU Instruction Operand(Data) Pointer */
	__uint32_t		__fpu_dp;		/* offset */
	__uint16_t		__fpu_ds;		/* Selector */

	__uint16_t		__fpu_rsrv3;		/* reserved */
	__uint32_t		__fpu_mxcsr;		/* MXCSR Register state */
	__uint32_t		__fpu_mxcsrmask;	/* MXCSR mask */
	_STRUCT_MMST_REG	__fpu_stmm0;		/* ST0/MM0   */
	_STRUCT_MMST_REG	__fpu_stmm1;		/* ST1/MM1  */
	_STRUCT_MMST_REG	__fpu_stmm2;		/* ST2/MM2  */
	_STRUCT_MMST_REG	__fpu_stmm3;		/* ST3/MM3  */
	_STRUCT_MMST_REG	__fpu_stmm4;		/* ST4/MM4  */
	_STRUCT_MMST_REG	__fpu_stmm5;		/* ST5/MM5  */
	_STRUCT_MMST_REG	__fpu_stmm6;		/* ST6/MM6  */
	_STRUCT_MMST_REG	__fpu_stmm7;		/* ST7/MM7  */
	_STRUCT_XMM_REG		__fpu_xmm0;		/* XMM 0  */
	_STRUCT_XMM_REG		__fpu_xmm1;		/* XMM 1  */
	_STRUCT_XMM_REG		__fpu_xmm2;		/* XMM 2  */
	_STRUCT_XMM_REG		__fpu_xmm3;		/* XMM 3  */
	_STRUCT_XMM_REG		__fpu_xmm4;		/* XMM 4  */
	_STRUCT_XMM_REG		__fpu_xmm5;		/* XMM 5  */
	_STRUCT_XMM_REG		__fpu_xmm6;		/* XMM 6  */
	_STRUCT_XMM_REG		__fpu_xmm7;		/* XMM 7  */
	_STRUCT_XMM_REG		__fpu_xmm8;		/* XMM 8  */
	_STRUCT_XMM_REG		__fpu_xmm9;		/* XMM 9  */
	_STRUCT_XMM_REG		__fpu_xmm10;		/* XMM 10  */
	_STRUCT_XMM_REG		__fpu_xmm11;		/* XMM 11 */
	_STRUCT_XMM_REG		__fpu_xmm12;		/* XMM 12  */
	_STRUCT_XMM_REG		__fpu_xmm13;		/* XMM 13  */
	_STRUCT_XMM_REG		__fpu_xmm14;		/* XMM 14  */
	_STRUCT_XMM_REG		__fpu_xmm15;		/* XMM 15  */
	char			__fpu_rsrv4[6*16];	/* reserved */
	int 			__fpu_reserved1;
};
#else /* !__DARWIN_UNIX03 */
#define	_STRUCT_X86_FLOAT_STATE64	struct x86_float_state64
_STRUCT_X86_FLOAT_STATE64
{
	int 			fpu_reserved[2];
	_STRUCT_FP_CONTROL	fpu_fcw;		/* x87 FPU control word */
	_STRUCT_FP_STATUS	fpu_fsw;		/* x87 FPU status word */
	__uint8_t		fpu_ftw;		/* x87 FPU tag word */
	__uint8_t		fpu_rsrv1;		/* reserved */ 
	__uint16_t		fpu_fop;		/* x87 FPU Opcode */

	/* x87 FPU Instruction Pointer */
	__uint32_t		fpu_ip;			/* offset */
	__uint16_t		fpu_cs;			/* Selector */

	__uint16_t		fpu_rsrv2;		/* reserved */

	/* x87 FPU Instruction Operand(Data) Pointer */
	__uint32_t		fpu_dp;			/* offset */
	__uint16_t		fpu_ds;			/* Selector */

	__uint16_t		fpu_rsrv3;		/* reserved */
	__uint32_t		fpu_mxcsr;		/* MXCSR Register state */
	__uint32_t		fpu_mxcsrmask;		/* MXCSR mask */
	_STRUCT_MMST_REG	fpu_stmm0;		/* ST0/MM0   */
	_STRUCT_MMST_REG	fpu_stmm1;		/* ST1/MM1  */
	_STRUCT_MMST_REG	fpu_stmm2;		/* ST2/MM2  */
	_STRUCT_MMST_REG	fpu_stmm3;		/* ST3/MM3  */
	_STRUCT_MMST_REG	fpu_stmm4;		/* ST4/MM4  */
	_STRUCT_MMST_REG	fpu_stmm5;		/* ST5/MM5  */
	_STRUCT_MMST_REG	fpu_stmm6;		/* ST6/MM6  */
	_STRUCT_MMST_REG	fpu_stmm7;		/* ST7/MM7  */
	_STRUCT_XMM_REG		fpu_xmm0;		/* XMM 0  */
	_STRUCT_XMM_REG		fpu_xmm1;		/* XMM 1  */
	_STRUCT_XMM_REG		fpu_xmm2;		/* XMM 2  */
	_STRUCT_XMM_REG		fpu_xmm3;		/* XMM 3  */
	_STRUCT_XMM_REG		fpu_xmm4;		/* XMM 4  */
	_STRUCT_XMM_REG		fpu_xmm5;		/* XMM 5  */
	_STRUCT_XMM_REG		fpu_xmm6;		/* XMM 6  */
	_STRUCT_XMM_REG		fpu_xmm7;		/* XMM 7  */
	_STRUCT_XMM_REG		fpu_xmm8;		/* XMM 8  */
	_STRUCT_XMM_REG		fpu_xmm9;		/* XMM 9  */
	_STRUCT_XMM_REG		fpu_xmm10;		/* XMM 10  */
	_STRUCT_XMM_REG		fpu_xmm11;		/* XMM 11 */
	_STRUCT_XMM_REG		fpu_xmm12;		/* XMM 12  */
	_STRUCT_XMM_REG		fpu_xmm13;		/* XMM 13  */
	_STRUCT_XMM_REG		fpu_xmm14;		/* XMM 14  */
	_STRUCT_XMM_REG		fpu_xmm15;		/* XMM 15  */
	char			fpu_rsrv4[6*16];	/* reserved */
	int 			fpu_reserved1;
};
#endif /* !__DARWIN_UNIX03 */

#if __DARWIN_UNIX03
#define _STRUCT_X86_EXCEPTION_STATE64	struct __darwin_x86_exception_state64
_STRUCT_X86_EXCEPTION_STATE64
{
    unsigned int	__trapno;
    unsigned int	__err;
    __uint64_t		__faultvaddr;
};
#else /* !__DARWIN_UNIX03 */
#define _STRUCT_X86_EXCEPTION_STATE64	struct x86_exception_state64
_STRUCT_X86_EXCEPTION_STATE64
{
    unsigned int	trapno;
    unsigned int	err;
    __uint64_t		faultvaddr;
};
#endif /* !__DARWIN_UNIX03 */

#if __DARWIN_UNIX03
#define _STRUCT_X86_DEBUG_STATE64	struct __darwin_x86_debug_state64
_STRUCT_X86_DEBUG_STATE64
{
	__uint64_t	__dr0;
	__uint64_t	__dr1;
	__uint64_t	__dr2;
	__uint64_t	__dr3;
	__uint64_t	__dr4;
	__uint64_t	__dr5;
	__uint64_t	__dr6;
	__uint64_t	__dr7;
};
#else /* !__DARWIN_UNIX03 */
#define _STRUCT_X86_DEBUG_STATE64	struct x86_debug_state64
_STRUCT_X86_DEBUG_STATE64
{
	__uint64_t	dr0;
	__uint64_t	dr1;
	__uint64_t	dr2;
	__uint64_t	dr3;
	__uint64_t	dr4;
	__uint64_t	dr5;
	__uint64_t	dr6;
	__uint64_t	dr7;
};
#endif /* !__DARWIN_UNIX03 */

#endif /* _MACH_I386__STRUCTS_H_ */
