/* APPLE LOCAL file 5820763 */
/* Assigning the result of a byteswap operation into a packed structure
   field was ICEing.  */
/* { dg-do compile } */
/* { dg-options "-O" } */

struct syment {
  unsigned long e_offset;
} __attribute ((packed));

void
swap_syment (struct syment * s, unsigned long n) {
  s[n].e_offset = (((s[n].e_offset) << 24)
		   | (((s[n].e_offset) << 8) & 0x00ff0000)
		   | (((s[n].e_offset) >> 8) & 0x0000ff00)
		   | ((unsigned long) (s[n].e_offset) >> 24));
}
