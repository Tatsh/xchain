/* APPLE LOCAL file 4649718, 4651088 */
/* Test for bogus property declarations. */
/* APPLE LOCAL radar 4899595 */
/* { dg-options "-fno-objc-new-property -mmacosx-version-min=10.5" { target powerpc*-*-darwin* i?86*-*-darwin* } } */
/* { dg-options "-fno-objc-new-property" { target arm*-*-darwin* } } */
/* { dg-do compile } */

@interface MyClass {

};
@property (ivar) unsigned char bufferedUTF8Bytes[4]; /* { dg-error "bad property declaration" } */
@end

@implementation MyClass
@end

