/* APPLE LOCAL file radar 4537821 */
/* A sibcall may be allowed to overwrite caller's stack if the sibcaller
   generates pretend argument stack space.  */

#include <alloca.h>
#include <stdlib.h>
#include <string.h>

#define STR "Hello, world!"

struct vfa_type {
  float f1, f2, f3, f4;
} vfa = {1.0, 2.0, 3.0, 4.0};

void level2 (int a, int b, struct vfa_type vals, int c)
{
}

void level1 (int a, int b, struct vfa_type vals)
{
  /* Should not be a sibcall, because level2 requires more stack space than 
     level1.  */
  level2 (a, b, vals, 0);
}

int main (int argc, char *argv[])
{
  char *msg = (char *) alloca (sizeof (STR));

  strcpy (msg, STR);
  level1 (1, 2, vfa);
  return strcmp (msg, STR);
}

