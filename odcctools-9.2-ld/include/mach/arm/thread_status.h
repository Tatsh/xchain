/* ----------------------------------------------------------------------------
 *   iphone-binutils: development tools for the Apple iPhone       07/12/2007
 *   Copyright (c) 2007 Patrick Walton <pcwalton@uchicago.edu> but freely
 *   redistributable under the terms of the GNU General Public License.
 *
 *   mach/arm/thread_status.h: information needed to save/restore threads
 * ------------------------------------------------------------------------- */

#ifndef MACH_ARM_THREAD_STATUS_H
#define MACH_ARM_THREAD_STATUS_H

#define ARM_THREAD_STATE 1
#define ARM_THREAD_STATE_COUNT ((mach_msg_type_number_t) \
    ( sizeof (arm_thread_state_t) / sizeof (int) ))

#define THREAD_STATE_NONE 1

struct arm_thread_state {
    unsigned int r0;
    unsigned int r1;
    unsigned int r2;
    unsigned int r3;
    unsigned int r4;
    unsigned int r5;
    unsigned int r6;
    unsigned int r7;
    unsigned int r8;
    unsigned int r9;
    unsigned int r10;
    unsigned int r11;
    unsigned int r12;
    unsigned int r13;
    unsigned int r14;
    unsigned int r15;
    unsigned int r16;   /* Apple's thread_state has this 17th reg, bug?? */
};

typedef struct arm_thread_state arm_thread_state_t;

#endif

