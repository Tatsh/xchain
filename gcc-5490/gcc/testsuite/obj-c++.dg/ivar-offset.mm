/* APPLE LOCAL file 5694615 */
/* ivar offset incorrectly emitted as zerofill common symbol.  */
/* Radar 5694615 */

/* { dg-options "-mmacosx-version-min=10.5 -m64" { target powerpc*-*-darwin* i?86*-*-darwin* } } */
/* { dg-options "" { target arm*-*-darwin* } } */
/* { dg-do compile { target *-*-darwin* } } */

@interface Foo {
    id isa;
    Foo *badvar;
}
@property(retain) id badvar;
@end
@implementation Foo
@synthesize badvar;
-(void)method { 
    badvar = 0;
}
@end

