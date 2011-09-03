// Test whether vtable for S is not put into read-only section.
// { dg-do compile }
// { dg-skip-if "No -fpic" { mmix-*-* } { "*" } { "" } }
// { dg-options "-O2 -fpic -fno-rtti" }
// APPLE LOCAL -mdynamic-no-pic incompatible with -fpic
// { dg-skip-if "Not valid with -mdynamic-no-pic" { *-*-darwin* } { "-mdynamic-no-pic" } { "" } }
// Origin: Jakub Jelinek <jakub@redhat.com>

struct S
{
  virtual void vm (void) {};
} x;

// { dg-final { scan-assembler-not "section\[^\n\r\]*_ZTV1S\[^\n\r\]*\"\[^w\"\n\r\]*\"" } }
