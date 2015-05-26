//
//  ViewController.swift
//  SixThings
//
//  Created by Joël Gähwiler on 26.05.15.
//  Copyright (c) 2015 256dpi. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UIWebViewDelegate {
  @IBOutlet weak var webView: UIWebView!
  
  let page = "https://shiftr.io/256dpi/6things/embed?hide_logo=1";
  
  override func viewDidLoad() {
    super.viewDidLoad()
    let url = NSURL(string: page);
    let req = NSURLRequest(URL: url!);
    self.webView.loadRequest(req);
  }
  
  override func prefersStatusBarHidden() -> Bool {
    return true
  }

  func webView(webView: UIWebView, shouldStartLoadWithRequest request: NSURLRequest, navigationType: UIWebViewNavigationType) -> Bool {
    return request.URL.absoluteString == page;
  }
}
