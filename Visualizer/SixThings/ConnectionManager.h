//
//  ConnectionManager.h
//  SixThings
//
//  Created by Joël Gähwiler on 20.05.15.
//  Copyright (c) 2015 256dpi. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <MQTTKit/MQTTKit.h>

@protocol ConnectionManagerDelegate <NSObject>

- (void)connectionManagerDidEstablishConnection;
- (void)connectionManagerDidReceiveValue:(NSNumber*)channel withValue:(NSNumber*)value;
- (void)connectionManagerDidReceivePresence:(NSString*)box;
@end

@interface ConnectionManager : NSObject
  @property (strong) MQTTClient* client;
  @property (weak) id <ConnectionManagerDelegate>delegate;

  - (void)establishConnection;
  - (void)clearConnection;
@end
