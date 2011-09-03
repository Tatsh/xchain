/* APPLE LOCAL file CW asm blocks */
/* { dg-do compile { target powerpc*-*-darwin* i?86*-*-darwin* } } */
/* { dg-options { -fasm-blocks } } */
/* Radar 4197305 */

#if 1
@@		/* { dg-error "syntax error before '@' token" } */
#endif
