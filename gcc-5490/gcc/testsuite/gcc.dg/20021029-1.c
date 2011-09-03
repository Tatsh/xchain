/* Test whether difference of local labels doesn't force
   variables into writable sections.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fpic" } */
/* APPLE LOCAL -mdynamic-no-pic incompatible with -fpic */
/* { dg-skip-if "Not valid with -mdynamic-no-pic" { *-*-darwin* } { "-mdynamic-no-pic" } { "" } } */
/* { dg-final { scan-assembler-not ".data.rel.ro.local" } } */

int foo (int a)
{
  static const int ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
  void *p = &&l1 + ar[a];
  goto *p;
  l1:
    return 1;
  l2:
    return 2;
}
