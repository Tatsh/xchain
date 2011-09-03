/* APPLE LOCAL file 4782404 */
/* We were using R7 as a scratch reg here. */
/* { dg-do compile } */
/* { dg-options "-O2 -mthumb -march=armv6" } */
char *p;
int foo() {
  char x[2048];
  p = x;
  baz();
}
/* Should be exactly 3 uses: save, set, restore. */
/* { dg-final { scan-assembler-times "r7" 3 } } */
