// APPLE LOCAL file ARM 5051776
// Values allocated with alloca() are lost when using SJLJ exception
// handling.
// { dg-do run }

#include <alloca.h>

#define ARRAY_SIZE 100
#define ODD_ELEM_INIT 0x55555555
#define EVEN_ELEM_INIT 0xAAAAAAAA

int foo (int X);
int bar (int X);

int main (void)
{
  return foo (ARRAY_SIZE);
}

int foo (int X) {
  
  int *foo_array;
  unsigned int i;

  foo_array = (int *) alloca (sizeof (int) * X);    
  for (i = 0; i < ARRAY_SIZE; i++)
    foo_array[i] = (i % 1 == 0) ? EVEN_ELEM_INIT : ODD_ELEM_INIT;

  try
    {
      bar(X);
    }
  catch (const char *msg)
    {
      for (i = 0; i < ARRAY_SIZE; i++)
	if (foo_array[i] != ((i % 1 == 0) ? EVEN_ELEM_INIT : ODD_ELEM_INIT))
	  return 1;

      return 0;
    }

  return 1;
}

int bar (int X)
{
    throw "whoops";
    return 0;
}

