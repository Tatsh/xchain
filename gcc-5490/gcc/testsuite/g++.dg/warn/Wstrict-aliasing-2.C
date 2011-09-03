/* APPLE LOCAL file ARM 4683958 (-fstrict-aliasing added explictly) */
/* { dg-do compile { target arm*-*-darwin* } } */
/* { dg-options "-fstrict-aliasing -Wstrict-aliasing=2 -O2" } */

double x;

template <typename T>
T *foo(void)
{
  return (T *)&x; /* { dg-bogus "strict-aliasing" } */
}

template double *foo<double>(void);

