/* APPLE LOCAL file 4956366 */
/* { dg-do compile } */
/* { dg-options "-O2 -march=armv6" } */

void my_fn (void) __attribute__((weak));
void my_fn (void) { }
int main (void)
{
  my_fn ();
}
/* Branch to my_fn mustn't be a sibcall.  */
/* { dg-final { scan-assembler "\[ \t\]+bl.*my_fn" } } */
