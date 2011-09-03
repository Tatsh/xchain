/* APPLE LOCAL file ARM 4639731 */
/* Verify that builtin_trap generates a trap instruction.  */
/* { dg-options "-O" } */
/* { dg-do compile { target arm-*-darwin* } } */
/* { dg-final { scan-assembler "trap" } } */

void foobar (void)
{
  __builtin_trap();
}

