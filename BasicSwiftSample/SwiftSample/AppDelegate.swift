//
//  AppDelegate.swift
//  SwiftSample
//
//  Created by Wayne Burkett on 11/7/19.
//  Copyright © 2019 ForeSee. All rights reserved.
//

import UIKit
import EXPCore

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
  
  var window: UIWindow?
  
  func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    // Enable debug logs (not typically used in production, but helpful
    // when testing)
    EXPCore.setDebugLogEnabled(true)

    // Set a VerintDelegate (used to determine when the SDK has started (or if
    // it fails to start)
    EXPCore.setDelegate(self)

    // Set the configuration container. This defaults to "live" and only
    // needs to be supplied when testing with other containers (e.g. "draft").
    EXPCore.setConfigurationContainer("live")

    // Start the SDK with this app's site key
    EXPCore.start(withSiteKey: "mobsdk-basicsample")
    return true
  }
}

extension AppDelegate: VerintDelegate {

  func didStartSDK() {
    print("Verint XM iOS SDK started successfully!")
  }
  
  func didStartSDKWithError(_ error: EXPErrorCode, message: String!) {
    print("Verint XM iOS SDK failed to start: \(error), \(message ?? "No message")")
  }
  
  func didFailToStartSDK(withError error: Error) {
    print("Verint XM iOS SDK failed to start: \(error)")
  }
}
