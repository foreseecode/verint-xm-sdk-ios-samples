//
//  AppDelegate.swift
//  AdvancedSample
//
//  Created by Wayne Burkett on 11/12/19.
//  Copyright © 2019 ForeSee. All rights reserved.
//

import UIKit
import EXPCore
import EXPPredictive

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

  var window: UIWindow?

  func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    EXPCore.setDebugLogEnabled(true)
    EXPCore.setEventLogEnabled(false)
    EXPCore.start()
    EXPPredictive.setSkipPoolingCheck(true)
    EXPCore.resetState()
    return true
  }

}

