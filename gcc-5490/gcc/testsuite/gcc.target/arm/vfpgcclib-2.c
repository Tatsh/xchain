/* APPLE LOCAL file 4636728 */
/* { dg-do compile } */
/* { dg-options "-O2 -mthumb -march=armv6" } */
volatile double x = 2.5, y = 5.0;
volatile float fx = 2.5f, fy = 5.0f;
volatile int ix = -2, iy = -5;
volatile long long llx = -2LL, lly = -5LL;
volatile unsigned uix = 2U, uiy = 5U;
volatile unsigned long long ullx = 2ULL, ully = 5ULL;
main() {
  if (x*y != 12.5) return 1;
  if (x+y != 7.5) return 1;
  if (x-y != -2.5) return 1;
  if (x/y != 0.5) return 1;
  if (-x != -2.5) return 1;

  if (x==y) return 1;
  if (!(x<y)) return 1;
  if (x>y) return 1;
  if (!(x<=y)) return 1;
  if (x>=y) return 1;
  if (!(x!=y)) return 1;
  if (__builtin_isunordered(x,y)) return 1;

  if ((int)x != 2)  return 1;
  if ((unsigned)x != 2) return 1;
  if ((long long)x  != 2LL) return 1;
  if ((unsigned long long)x != 2LL) return 1;

  if ((double)fx != 2.5) return 1;
  if ((float)x != 2.5f) return 1;

  if ((double)ix != -2.0) return 1;
  if ((double)uix != 2.0) return 1;
  if ((double)llx != -2.0) return 1;
  if ((double)ullx != 2.0) return 1;

  if (fx*fy != 12.5f) return 1;
  if (fx+fy != 7.5f) return 1;
  if (fx-fy != -2.5f) return 1;
  if (fx/fy != 0.5f) return 1;
  if (-fx != -2.5f) return 1;

  if (fx==fy) return 1;
  if (!(fx<fy)) return 1;
  if (fx>fy) return 1;
  if (!(fx<=fy)) return 1;
  if (fx>=fy) return 1;
  if (!(fx!=fy)) return 1;
  if (__builtin_isunordered(fx,fy)) return 1;

  if ((int)fx != 2)  return 1;
  if ((unsigned)fx != 2) return 1;
  if ((long long)fx  != 2LL) return 1;
  if ((unsigned long long)fx != 2LL) return 1;

  if ((double)fx != 2.5) return 1;
  if ((float)x != 2.5f) return 1;

  if ((float)ix != -2.0f) return 1;
  if ((float)uix != 2.0f) return 1;
  if ((float)llx != -2.0f) return 1;
  if ((float)ullx != 2.0f) return 1;

  return 0;
}

/* { dg-final { scan-assembler-times "vfp" 238 } } */
