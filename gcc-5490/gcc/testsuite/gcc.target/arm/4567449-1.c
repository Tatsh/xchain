/* APPLE LOCAL file 4567449 */

/* { dg-do compile } */
/* { dg-options "-O2 -mno-thumb-interwork" } */
/* { dg-final { global compiler_flags; if ![string match "*-mthumb *" $compiler_flags] { scan-assembler-not "bl\[^\n\]+func2" } } } */

/* A sibcall should be alllowed if any of the incoming args don't overlap
   their corollary outgoing args.  This is one case we were getting wrong
   -- when an outgoing arg is split between registers and stack.  */

typedef struct {
  int a;
  int b;
  int c;
  int d;
} s32_t;

void func2(int i, int j, s32_t s32);

void func1(int p1, int p2, int p3, int p4, int p5, int p6, s32_t s32) {
  func2(p5, p6, s32);
}
