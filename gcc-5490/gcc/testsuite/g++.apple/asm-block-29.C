/* APPLE LOCAL file CW asm blocks */
/* { dg-do assemble { target i?86*-*-darwin* powerpc-*-darwin* } } */
/* { dg-options { -fasm-blocks -msse3 } } */
/* Radar 4298005 */

void foo() {
  _asm nop
}
