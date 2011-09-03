/* APPLE LOCAL file ARM 6034515 */
/* { dg-do run { target arm*-*-darwin* } } */
/* { dg-options "-fvisibility-inlines-hidden -mthumb" } */
#include <typeinfo>

int main (void)
{
  typeid(int).name();
  return 0;
}
