/* Test that -fvisibility=hidden prevents PLT. */
/* { dg-do compile } */
/* { dg-require-visibility "" } */
/* { dg-options "-fPIC -fvisibility=hidden" } */
/* APPLE LOCAL -mdynamic-no-pic incompatible with -fPIC */
/* { dg-skip-if "Not valid with -mdynamic-no-pic" { *-*-darwin* } { "-mdynamic-no-pic" } { "" } } */
/* { dg-final { scan-assembler-not "methodEv@PLT" } } */

class Foo
{
public:
  void method();
};

void Foo::method() { }

int main(void)
{
  Foo f;
  f.method();
  return 0;
}
