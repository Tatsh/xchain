/* APPLE LOCAL file ARM 4683958 (-fstrict-aliasing added explictly) */
/* { dg-do compile { target arm*-*-darwin* } } */
/* { dg-options "-Wstrict-aliasing=2 -O2 -fstrict-aliasing" } */

float foo ()
{
  unsigned int MASK = 0x80000000;
  return (float &) MASK; /* { dg-warning "strict-aliasing" } */
}

