/* APPLE LOCAL file 4468410 */
/* { dg-do run } */
/* { dg-options "-O2 -mno-thumb" } */
long long foo(long long x) { return x + 1; }
long long foo2(long long x) { return x & 1; }
long long foo4 (long long x) { return x | 1; }
long long foo5 (long long x) { return x ^ 1; }
long long foo3(long long x) { return x - 1; }
long long foo6(long long x) { return x + (-1); }
long long foo7(long long x) { return x - (-1); }
int main() {
  if (foo(0x1234567812345678LL) != 0x1234567812345679LL)
    return 1;
  if (foo2(0x1234567812345678LL) != 0x0LL)
    return 1;
  if (foo4(0x1234567812345678LL) != 0x1234567812345679LL)
    return 1;
  if (foo5(0x1234567812345678LL) != 0x1234567812345679LL)
    return 1;
  if (foo3(0x1234567812345678LL) != 0x1234567812345677LL)
    return 1;
  if (foo6(0x1234567812345678LL) != 0x1234567812345677LL)
    return 1;
  if (foo7(0x1234567812345678LL) != 0x1234567812345679LL)
    return 1;
  return 0;
}
