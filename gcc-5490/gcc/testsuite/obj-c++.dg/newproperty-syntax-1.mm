/* APPLE LOCAL file radar 4805321 */
/* { dg-options "-mmacosx-version-min=10.5 -fobjc-new-property" { target powerpc*-*-darwin* i?86*-*-darwin* } } */
/* { dg-options "-fobjc-new-property" { target arm*-*-darwin* } } */
/* { dg-do compile { target *-*-darwin* } } */

@interface INTF
{
	id IV;
	id IVXXX;
	int synthesize_ivar;
}
@property (readwrite, assign) int name1;
@property (readonly, retain)  id name2;
@property (readwrite, copy)   id name3;
@end

@implementation INTF
@dynamic name1,name2,name3;
@synthesize name1=synthesize_ivar, name2=IV, name3=IVXXX;
@end
