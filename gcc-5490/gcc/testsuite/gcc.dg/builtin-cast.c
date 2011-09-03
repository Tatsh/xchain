/* APPLE LOCAL file radar 4629695 */
/* { dg-do compile { target powerpc*-*-darwin* i?86*-*-darwin* } } */
/* { dg-options "-m64" } */
/* { dg-final { scan-assembler "_memcmp" } } */
extern void abort (void);
typedef __SIZE_TYPE__ size_t;
extern int memcmp (const void *, const void *, size_t);

void foo () {
  const void *a, *b;
  int c, d;
  d = ((int (*) (const void *, const void *, int ))(void*)memcmp) (a, b, c);
}
/* APPLE LOCAL file radar 4629695 */
