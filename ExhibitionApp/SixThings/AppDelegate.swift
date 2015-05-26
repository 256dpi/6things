//
//  AppDelegate.swift
//  SixThings
//
//  Created by Joël Gähwiler on 26.05.15.
//  Copyright (c) 2015 256dpi. All rights reserved.
//

import UIKit

@UIApplicationMain

class AppDelegate: UIResponder, UIApplicationDelegate {
  var window: UIWindow?
  
  func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject : AnyObject]?) -> Bool {
    NSURLCache.sharedURLCache().removeAllCachedResponses();
    return true;
  }
}
