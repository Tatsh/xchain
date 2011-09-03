/* APPLE LOCAL file 4587904 */
/* CSE incorrectly optimizing multiple comparisons.  */

/* { dg-do run } */
/* { dg-options "-O2" } */

int
get_len()
{
  return 37;
}

int 
validate_data(int data_type, int data_length)
{
  int len;

  switch (data_type) {
    case 8:
      if (!data_length)
	return 0;
      len = get_len();
      return (len <= 253 && data_length == len);

    case 13:
      if (!data_length)
        return 0;
      return (data_length == 43);

    default:
      return 0;
    }

  return 0;
}

int 
main(int argc, const char *argv[])
{
  if (validate_data(8, 37) == 1)
    return 0;
  else
    return 1;
}
