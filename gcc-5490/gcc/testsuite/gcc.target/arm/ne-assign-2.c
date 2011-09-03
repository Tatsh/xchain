/* APPLE LOCAL file 4382996 */
/* { dg-do run } */
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
int sub1 (int a, int b) { return (a - b) != 0; }
int sub2 (int a) { return (a - 3) != 0; }
int sub3 (int a) { return (3 - a) != 0; }
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
int and6(int a) { return (a & 1) != 0; }
int ls31(unsigned int a) { return (a >> 31) != 0; }
int sl31(unsigned int a) { return (a << 31) != 0; }
int as31(int a) { return (a >> 31) != 0; }
main() {
  if (cmpz (1) != 1 || cmpz (0) != 0)
    return 1;
  if (and1 (3, 2) != 1 || and1 (0, 99) != 0)
    return 1;
  if (and2 (15) != 1 || and2 (16) != 0)
    return 1;
  if (and3 (15) != 1 || and3 (16) != 0)
    return 1;
  if (and4 (15) != 1 || and4 (16) != 0)
    return 1;
  if (and5 (15) != 1 || and5 (16) != 0)
    return 1;
  if (and6 (15) != 1 || and6 (16) != 0)
    return 1;
  if (or (1, 2) != 1 || or (0, 0) != 0)
    return 1;
  if (xor (1, 2) != 1 || xor (1, 1) != 0)
    return 1;
  if (add1 (3, 4) != 1 || add1 (2, -2) !=0)
    return 1;
  if (add2 (5) != 1 || add2 (-3) != 0)
    return 1;
  if (add3 (5) != 1 || add3 (-3) != 0)
    return 1;
  if (sub1 (5, 3) != 1 || sub1 (3, 3) != 0)
    return 1;
  if (sub2 (5) != 1 || sub2 (3) != 0)
    return 1;
  if (sub3 (5) != 1 || sub3 (3) != 0)
    return 1;
  if (mul (2, 3) != 1 || mul(3, 0) != 0)
    return 1;
  if (div (3, 2) != 1 || div (2, 3) != 0)
    return 1;
  if (slv (1, 3) != 1 || slv (0, 3 ) != 0)
    return 1;
  if (sl30 (2) != 1 || sl30 (16) != 0)
    return 1;
  if (sl31 (1) != 1 || sl31 (16) != 0)
    return 1;
  if (lsv (16, 2) != 1 || lsv (16, 5) != 0)
    return 1;
  if (ls30 (0x40000000) != 1 || ls30 (0x10000000) != 0)
    return 1;
  if (ls31 (0x80000000) != 1 || ls31 (0x10000000) != 0)
    return 1;
  if (asv (16, 2) != 1 || lsv (16, 5) !=0)
    return 1;
  if (as30 (0x40000000) != 1 || as30 (0x10000000) != 0)
    return 1;
  if (as31 (0x80000000) != 1 || as31 (0x10000000) != 0)
    return 1;
  if ( not (0) != 1 || not (-1) != 0)
    return 1;
  if ( neg (1) != 1 || neg (0) != 0)
    return 1;
  return 0;
}
