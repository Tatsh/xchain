/* APPLE LOCAL file 4468410 */
/* { dg-do compile } */
/* { dg-options "-O2 -mno-thumb" } */
long long foo(long long x) { return x + 1; }
long long foo2(long long x) { return x & 1; }
long long foo4 (long long x) { return x | 1; }
long long foo5 (long long x) { return x ^ 1; }
long long foo3(long long x) { return x - 1; }
long long foo6(long long x) { return x + (-1); }
long long foo7(long long x) { return x - (-1); }
/* { dg-final { scan-assembler-not "mov" } } */
