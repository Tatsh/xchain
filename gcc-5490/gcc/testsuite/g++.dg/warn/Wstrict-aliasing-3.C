/* APPLE LOCAL file ARM 4683958 (-fstrict-aliasing added explictly) */
/* { dg-do compile { target arm*-*-darwin* } } */
/* { dg-options "-Wstrict-aliasing=2 -fstrict-aliasing -O2" } */

double x;

template <typename T>
T *foo(void)
{
  return (T *)&x; /* { dg-warning "strict-aliasing" } */
}

template int *foo<int>(void); /* { dg-warning "instantiated from here" } */
template char *foo<char>(void); /* { dg-bogus "instantiated from here" } */

