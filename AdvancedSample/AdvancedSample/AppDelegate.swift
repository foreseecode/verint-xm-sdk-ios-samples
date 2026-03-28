//
//  AppDelegate.swift
//  AdvancedSample
//
//  Created by Wayne Burkett on 11/12/19.
//  Copyright © 2019 ForeSee. All rights reserved.
//

import UIKit
import EXPCore
import EXPSurveyManagement

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

  var window: UIWindow?

  func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    EXPCore.setDebugLogEnabled(true)
    EXPCore.setEventLogEnabled(true)
    EXPCore.start()
    SurveyManagement.setSkipPoolingCheck(true)
    EXPCore.resetState()
    // Critical note: userId will be cleared after resetState().
    EXPCore.setUserId("SJL - DT Event test")
    return true
  }

}

