/* APPLE LOCAL file ARM 4683958 (-fstrict-aliasing added explictly) */
/* { dg-do compile { target arm*-*-darwin* } } */
/* { dg-options "-Wstrict-aliasing=2 -O2 -fstrict-aliasing" } */

int foo ()
{
  char buf[8];
  return *((int *)buf); /* { dg-warning "strict-aliasing" } */
}

