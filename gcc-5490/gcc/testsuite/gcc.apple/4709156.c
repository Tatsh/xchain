/* APPLE LOCAL file radar 4709156 */
/* { dg-do run } */
/* { dg-options "-Os -fno-inline-functions" } */

void abort (void);

typedef struct {
  long mbr1;
  long mbr2;
} agg;

int expected = 31415;

int GetConst (int a, int b, int c, agg d)
{
  return expected;
}

void VerifyValues (int a, int b, int c, int d, int e, int f)
{
  if (e != 123 || f != expected)
    abort ();
}

void RunTest (agg a)
{
  int result;
	
  result = GetConst (1, 2, 3, a);
  VerifyValues (111, 222, 333, 444, a.mbr1, result);
}

int main(void)
{
  agg result = {123, 456};
  RunTest (result);
  return 0;
}

