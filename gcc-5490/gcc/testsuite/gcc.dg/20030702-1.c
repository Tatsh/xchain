/* This tests whether REG_ALWAYS_RETURN notes are handled
   correctly in combine.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fpic -fprofile-arcs" } */
/* APPLE LOCAL -mdynamic-no-pic incompatible with -fpic */
/* { dg-skip-if "Not valid with -mdynamic-no-pic" { *-*-darwin* } { "-mdynamic-no-pic" } { "" } } */

void test (void)
{
  fork ();
}

