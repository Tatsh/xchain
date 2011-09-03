/* APPLE LOCAL file ARM 4683958 (-fstrict-aliasing added explictly) */
/* { dg-do compile { target arm*-*-darwin* } } */
/* { dg-options "-Wstrict-aliasing -O2 -fstrict-aliasing" } */

int a[2];

double *foo1(void)
{
  return (double *)a; /* { dg-warning "strict-aliasing" } */
}

double *foo2(void)
{
  return (double *)&a[0]; /* { dg-warning "strict-aliasing" } */
}

__complex__ double x;
int *bar(void)
{
  return (int *)&__imag__ x; /* { dg-warning "strict-aliasing" } */
}
