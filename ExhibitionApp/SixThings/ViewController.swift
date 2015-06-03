//
//  ViewController.swift
//  SixThings
//
//  Created by Joël Gähwiler on 26.05.15.
//  Copyright (c) 2015 256dpi. All rights reserved.
//

import UIKit
import WebKit

class ViewController: UIViewController {
  var webView: WKWebView?
  
  let page = "https://shiftr.io/256dpi/6things/embed?hide_logo=1";
  
  override func loadView() {
    super.loadView()
    
    self.webView = WKWebView()
    self.view = self.webView
  }
  
  override func viewDidLoad() {
    super.viewDidLoad()
    
    let url = NSURL(string: page);
    let req = NSURLRequest(URL: url!);
    self.webView!.loadRequest(req);
  }
  
  override func prefersStatusBarHidden() -> Bool {
    return true
  }
}
