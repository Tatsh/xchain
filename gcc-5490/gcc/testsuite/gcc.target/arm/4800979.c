/* APPLE LOCAL file 4800979 */
/* { dg-do compile } */
/* { dg-options "-Os -march=armv6" } */
void write_data(char *);
void *do_alloc (int);

void
write_array(float *v, int count)
{
  long i;
  long *t;

  t = (long *) do_alloc (2 * count * sizeof(long));
  for (i = 0; i < count; i++)
    {
      float fv = v[i];
      long den;

      den = 1L;
      if (fv > 0)
        while (fv < (1L << 28) && den < (1L << 28))
	  fv *= 8, den *= 8;

      t[2 * i + 0] = (long) (fv + 0.5);
      t[2 * i + 1] = den;
    }

  write_data((char *) t);
}
