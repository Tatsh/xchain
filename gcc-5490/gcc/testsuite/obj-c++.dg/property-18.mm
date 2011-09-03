/* APPLE LOCAL file radar 4727191 */
/* Test that assigning local variable to a property does not ICE. */
/* APPLE LOCAL radar 4899595 */
/* { dg-options "-fno-objc-new-property -mmacosx-version-min=10.5" { target powerpc*-*-darwin* i?86*-*-darwin* } } */
/* { dg-options "-fno-objc-new-property" { target arm*-*-darwin* } } */
/* { dg-do compile { target *-*-darwin* } } */

@interface Link 
  @property(ivar) id test;
@end

@implementation Link @end

int main() {
    id pid;
    Link *link;
    link.test = pid;
}
