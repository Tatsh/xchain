/* APPLE LOCAL file 4382996 */
/* { dg-do compile } */
/* { dg-options "-O2 -mno-thumb -march=armv6" } */
/* None of these should use MOVEQ, which is redundant. */
int cmpz(int a) { return a != 0; }
int and1(int a, int b) { return (a & b) != 0; }
int and2(int a) { return (a & 3) != 0; }
int and3(int a) { return (a & 7) != 0; }
int and4(int a) { return (a & 0xf) != 0; }
int and5(int a) { return (a & 5) != 0; }
int or(int a, int b) { return (a | b) != 0; }
int xor(int a, int b) { return (a ^ b) != 0; }
int add1(int a, int b) { return (a + b) != 0; }
int add2(int a) { return (a + 3) != 0; }
int add3(int b) { return (3 + b) != 0; }
int sub1(int a, int b) { return (a - b) != 0; }
int sub2(int a) { return (a - 3) != 0; }
int sub3(int a) { return (3 - a) != 0; }
int mul (int a, int b) { return (a * b) != 0; }
int div (int a, int b) { return (a / b) != 0; }
int slv(int a, int b) { return (a << b) != 0; }
int sl30(unsigned int a) { return (a << 30) != 0; }
int lsv(unsigned int a, unsigned int b) { return (a >> b) != 0; }
int ls30(unsigned int a) { return (a >> 30) != 0; }
int asv(int a, int b) { return (a >> b) != 0; }
int as30(int a) { return (a >> 30) != 0; }
int not(int a) { return (~a) != 0; }
int neg(int a) { return (-a) != 0; }
/* These 4 do not even need a movne. */
int and6(int a) { return (a & 1) != 0; }
int ls31(unsigned int a) { return (a >> 31) != 0; }
int sl31(unsigned int a) { return (a << 31) != 0; }
int as31(int a) { return (a >> 31) != 0; }
/* { dg-final { scan-assembler-not "moveq" } } */
/* { dg-final { scan-assembler-times "movne" 24 } } */
