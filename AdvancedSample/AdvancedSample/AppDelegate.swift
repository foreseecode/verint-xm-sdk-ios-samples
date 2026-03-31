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

  static let userId = "SJL - DT Event test";

  var window: UIWindow?

  func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    EXPCore.setDebugLogEnabled(true)
    EXPCore.setEventLogEnabled(true)
    EXPCore.setDatacenter("EU")
    EXPCore.setConfigurationContainer("draft")
    EXPCore.start(withSiteKey: "mobsdk-tmp-telekom-de-events")
    SurveyManagement.setSkipPoolingCheck(true)
    EXPCore.resetState()
    // Critical note: userId will be cleared after resetState().
    EXPCore.setUserId(AppDelegate.userId)
    return true
  }

}

