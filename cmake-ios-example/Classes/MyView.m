#import "MyView.h"

@implementation MyView

- (void)drawRect:(CGRect)rect {
  [[UIColor whiteColor] set];
  CGRect bounds = self.bounds;
  [NSLocalizedString(@"Hello World", @"String for Main Screen Title")
    drawInRect:CGRectMake(0, bounds.size.height/2-50, bounds.size.width, 50)
    withFont:[UIFont fontWithName:@"Marker Felt" size:50]
    lineBreakMode:UILineBreakModeMiddleTruncation
    alignment:UITextAlignmentCenter];
}

@end 
