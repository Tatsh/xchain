/* APPLE LOCAL file CW asm blocks */
/* { dg-do compile { target powerpc*-*-darwin* i?86*-*-darwin* } } */
/* { dg-options { -fasm-blocks } } */
/* Radar 4766972 */

int f() { @@ }	/* { dg-error "syntax error before '@' token" } */
