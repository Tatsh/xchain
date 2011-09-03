/* The string constant in this test case should be emitted exactly once.  */
/* { dg-do compile } */
/* APPLE LOCAL begin ARM strings in code */
/* On ARM with strings-in-code there are multiple copies.  */
/* { dg-options "-O2" { target { ! "arm-*-*" } } } */
/* { dg-options "-O2 -mno-strings-in-code" { target { "arm-*-*" } } } */
/* APPLE LOCAL end ARM strings in code */
/* { dg-final { scan-assembler-times "hi there" 1 } } */

static inline int returns_23() { return 23; }

const char *test1(void) { if (returns_23()) return 0; return "hi there"; }
const char *test2(void) { return "hi there"; }
const char *test3(void) { return "hi there"; }
