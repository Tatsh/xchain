/* APPLE LOCAL file add this peephole */
/* { dg-do compile } */
/* { dg-options "-O2 -mthumb -march=armv6" } */
extern int bar(), baz();
int foo(int p) {
   int y=p;
   int x= bar();
   if (x==0)
     y =  baz();
   return x+y;
}
/* { dg-final { scan-assembler-not "cmp" } } */
