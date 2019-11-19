//
//  AppDelegate.swift
//  SwiftSample
//
//  Created by Wayne Burkett on 11/7/19.
//  Copyright © 2019 ForeSee. All rights reserved.
//

import UIKit
import ForeSee

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
  
  var window: UIWindow?
  
  func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    ForeSee.start()
    return true
  }
  
  
}

