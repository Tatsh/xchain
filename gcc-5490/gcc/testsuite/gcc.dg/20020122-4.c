/* Alpha -msmall-data didn't transform (mem (symbol_ref)) to
   (mem (lo_sum pic (symbol_ref))) within an asm at the right time.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fpic" } */
/* APPLE LOCAL -mdynamic-no-pic incompatible with -fpic */
/* { dg-skip-if "Not valid with -mdynamic-no-pic" { *-*-darwin* } { "-mdynamic-no-pic" } { "" } } */
/* { dg-warning "not supported" "PIC unsupported" { target cris-*-elf* cris-*-aout* mmix-*-* } 0 } */

void foo()
{
  static int test;
  int dummy;
  asm volatile ("" : "=m"(test), "=r"(dummy) : "m"(test));
}
