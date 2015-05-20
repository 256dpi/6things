//
//  ConnectionManager.m
//  SixThings
//
//  Created by Joël Gähwiler on 20.05.15.
//  Copyright (c) 2015 256dpi. All rights reserved.
//

#import "ConnectionManager.h"

@implementation ConnectionManager

- (void)establishConnection {
  self.client = [[MQTTClient alloc] initWithClientId:@"visualiser"];
  [self.client setUsername:@"0c90c3f09b4fa34c"];
  [self.client setPassword:@"8125de517a549ceb426765d4ceb12414"];
  
  [self.client setMessageHandler:^(MQTTMessage* message){
    NSError* e;
    NSDictionary* json = [NSJSONSerialization JSONObjectWithData:message.payload options:NSJSONReadingMutableContainers error: &e];
    
    NSString* topic = json[@"message"][@"topic"];
    NSString* payload = json[@"message"][@"payload"];
    
    NSNumber* channel = [[NSNumber alloc]initWithInteger:topic.lastPathComponent.integerValue];
    NSNumber* value = [[NSNumber alloc]initWithInteger:payload.integerValue];
    
    [self.delegate connectionManagerDidReceiveValue:channel withValue:value];
  }];
 
  [self.client connectToHost:@"connect.shiftr.io" completionHandler:^(NSUInteger code) {
    if (code == ConnectionAccepted) {
      [self.client subscribe:@"$events" withCompletionHandler:^(NSArray *grantedQos) {
        [self.delegate connectionManagerDidEstablishConnection];
      }];
    }
  }];
}

- (void)clearConnection {
  [self.client disconnectWithCompletionHandler:nil];
}

@end