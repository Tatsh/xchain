#import <UIKit/UIKit.h>

@class CMMainViewController;

@interface CMAppDelegate : NSObject <UIApplicationDelegate> {
  UIWindow *window;
  CMMainViewController *myViewController;
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) CMMainViewController *myViewController;

@end
 
