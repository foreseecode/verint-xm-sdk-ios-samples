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
class AppDelegate: UIResponder, UIApplicationDelegate, ForeSeeDelegate {
  
  var window: UIWindow?
  
  func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    ForeSee.setDelegate(self)
    
    if let path = Bundle.main.path(forResource: "foresee_configuration", ofType: "json") {
      do {
        let json = try String(contentsOfFile: path)
        ForeSee.start(withConfigurationJson: json)
      } catch {
        // failed ot load foresee_configuration.json
      }
    } else {
      // foresee_configuration.json file not found
    }
    return true
  }
  
  func didStartSDK() {
    print("ForeSeeDelegate - SDK started")
  }
   
}

