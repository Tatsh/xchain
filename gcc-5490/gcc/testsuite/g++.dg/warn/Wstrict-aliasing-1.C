/* APPLE LOCAL file ARM 4683958 (-fstrict-aliasing added explictly) */
/* { dg-do compile { target arm*-*-darwin* } } */
/* { dg-options "-Wstrict-aliasing=2 -O2 -fstrict-aliasing" } */

double x;
int *foo(void)
{
  return (int *)&x; /* { dg-warning "strict-aliasing" } */
}

