#import <Foundation/Foundation.h>

@interface PZMailMessage : NSObject {
  NSString *message;
  NSString *recipient;
}

@end

@implementation PZMailMessage
- (id)initWithString:(NSString *)string recipient:(NSString *)aRecipient {
  message = string;
  recipient = aRecipient;
  return self;
}

- (void)deliver {
  NSLog(@"Are you %@?", recipient);
  NSLog(@"%@", message);
}
@end

int main() {
  PZMailMessage *msg = [[PZMailMessage alloc] initWithString:@"My message" recipient:@"John smith"];
  [msg deliver];
  [msg release];
  return 0;
}
