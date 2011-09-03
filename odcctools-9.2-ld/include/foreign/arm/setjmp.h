#ifndef _BSD_ARM_SETJMP_H_
#define _BSD_ARM_SETJMP_H_

#define _JBLEN  27
typedef int jmp_buf[_JBLEN];
typedef int sigjmp_buf[_JBLEN + 1];

int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int val);

#ifndef _ANSI_SOURCE
int _setjmp(jmp_buf env);
void _longjmp(jmp_buf, int val);
int sigsetjmp(sigjmp_buf env, int val);
void siglongjmp(sigjmp_buf env, int val);
#endif

#if !defined(_ANSI_SOURCE) && !defined(_POSIX_C_SOURCE)
void longjmperror(void);
#endif

#endif

