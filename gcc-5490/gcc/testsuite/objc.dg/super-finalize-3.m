/* APPLE LOCAL file radar 5432522 */
/* Don't warn about missing [super finalize] calls without gc.  */

/* { dg-do compile } */
/* { dg-options "-fno-objc-gc" } */

@interface Foo {
  void *isa;
}
- (void) finalize;
- (void) some_other;
@end

@interface Bar: Foo {
  void *casa;
}
- (void) finalize;
@end

@interface Baz: Bar {
  void *usa;
}
- (void) finalize;
@end

@implementation Foo
- (void) finalize {
  isa = 0;   /* Should not warn here.  */
}
- (void) some_other {
  isa = (void *)-1;
}
@end

@implementation Bar
- (void) finalize {
  casa = 0;
  [super some_other];
}  /* Should not warn here.  */
@end

@implementation Baz
- (void) finalize {
  usa = 0;
  [super finalize];  /* Should not warn here.  */
}
@end
