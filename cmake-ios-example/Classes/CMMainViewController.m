#import "CMMainViewController.h"
#import "MyView.h"

@implementation CMMainViewController

- (void)loadView {
  UIView *view = [[MyView alloc] initWithFrame:[UIScreen mainScreen].applicationFrame];
  view.autoresizesSubviews = YES;
  view.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
  self.view = view;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
  return YES;
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
}

- (void)dealloc {
  [super dealloc];
}

@end