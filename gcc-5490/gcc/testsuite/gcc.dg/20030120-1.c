/* PR 7154 */
/* { dg-do compile } */
/* { dg-options "-O -fpic" } */
/* APPLE LOCAL -mdynamic-no-pic incompatible with -fpic */
/* { dg-skip-if "Not valid with -mdynamic-no-pic" { *-*-darwin* } { "-mdynamic-no-pic" } { "" } } */
/* { dg-warning "not supported" "PIC unsupported" { target cris-*-elf* mmix-*-* } 0 } */

const int x[1]={ 1 };
void foo(int i, int *p)
{
  asm volatile("" : "+r"(i) : "m" (x[0]), "r"(p));
}
