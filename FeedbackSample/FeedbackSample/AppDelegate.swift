//
//  AppDelegate.swift
//  FeedbackSample
//
//  Created by Alan Wang on 11/14/18.
//  Copyright © 2018 Alan Wang. All rights reserved.
//

import UIKit
import ForeSee

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

  var window: UIWindow?

  func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    // Override point for customization after application launch.
    ForeSee.start()
    return true
  }

}

