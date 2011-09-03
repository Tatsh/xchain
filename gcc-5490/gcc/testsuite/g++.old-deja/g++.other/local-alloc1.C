// { dg-do assemble  }
// { dg-options "-O0 -fpic" }
// Origin: Jakub Jelinek <jakub@redhat.com>
// { dg-skip-if "No -fpic" { cris-*-elf* cris-*-aout* mmix-*-* } { "*" } { "" } }
// APPLE LOCAL -mdynamic-no-pic incompatible with -fpic
// { dg-skip-if "Not valid with -mdynamic-no-pic" { *-*-darwin* } { "-mdynamic-no-pic" } { "" } }

struct bar {
  bar() {}
  double x[3];
};

static bar y[4];

void foo(int z)
{
  bar w;
  y[z] = w;
}
