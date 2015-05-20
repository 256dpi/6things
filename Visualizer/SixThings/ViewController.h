//
//  ViewController.h
//  SixThings
//
//  Created by Joël Gähwiler on 20.05.15.
//  Copyright (c) 2015 256dpi. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ConnectionManager.h"

@interface ViewController : UIViewController<ConnectionManagerDelegate>
  @property (strong) ConnectionManager* connectionManager;
@end
