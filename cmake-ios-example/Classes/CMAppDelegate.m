#import "CMAppDelegate.h"
#import "CMMainViewController.h"

@implementation CMAppDelegate
@synthesize window;
@synthesize myViewController;

- (void)applicationDidFinishLaunching:(UIApplication *)application {
  // Create window
  self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];

  // Create view controller
  CMMainViewController *aViewController = [[CMMainViewController alloc] init];
  self.myViewController = aViewController;
  [aViewController release];

  [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleBlackOpaque];
  
  // Add the view controller's view as a subview of the window
  [window addSubview:[myViewController view]];
  
  // Show window
  [window makeKeyAndVisible];
}

- (void)dealloc {
  [myViewController release];
  [window release];
  [super dealloc];
}

@end