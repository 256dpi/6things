//
//  ViewController.m
//  SixThings
//
//  Created by Joël Gähwiler on 20.05.15.
//  Copyright (c) 2015 256dpi. All rights reserved.
//

#import "ViewController.h"


@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  self.connectionManager = [[ConnectionManager alloc] init];
  self.connectionManager.delegate = self;
  [self.connectionManager establishConnection];
}

- (BOOL)prefersStatusBarHidden {
  return YES;
}

- (void)connectionManagerDidEstablishConnection {
  NSLog(@"connected!");
}

- (void)connectionManagerDidReceiveValue:(NSNumber*)channel withValue:(NSNumber*)value {
  NSLog(@"value: %@ - %@", channel, value);
}

- (void)connectionManagerDidReceivePresence:(NSString *)box {
  NSLog(@"presence %@", box);
}

- (void)dealloc {
  [self.connectionManager clearConnection];
}

@end
