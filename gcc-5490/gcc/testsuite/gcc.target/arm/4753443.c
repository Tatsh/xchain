/* APPLE LOCAL file 4753443 */
/* Verify that a multiply-accumulate instruction is generated.  */
/* { dg-do compile } */
/* { dg-options "-O2" } */
int mac (int a, int b, int c)
{
  return a + b * c;
}

/* { dg-final { scan-assembler "mla" } } */
