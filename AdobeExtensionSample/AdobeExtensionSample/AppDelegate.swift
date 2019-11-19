//
//  AppDelegate.swift
//  AdobeExtensionSample
//
//  Created by Wayne Burkett on 11/19/19.
//  Copyright © 2019 ForeSee. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, ForeSeeAdobeExtensionDelegate {

  let adobeAppId = "launch-ENd52c4e388a484e68955cb76df95d66b6-development"
  var window: UIWindow?

  func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
    startAdobe()
    return true
  }
  
  // MARK: Startup

  func startAdobe() {
    ACPCore.setLogLevel(.debug)
    ACPCore.configure(withAppId: adobeAppId)
    
    ForeSeeAdobeExtension.register()
    ACPIdentity.registerExtension()
    ACPLifecycle.registerExtension()
    ACPSignal.registerExtension()
    ACPUserProfile.registerExtension()
    
    ForeSeeAdobeExtension.setDelegate(self)

    ACPCore.start {
      ACPCore.lifecycleStart(nil)
    }
  }
  
  // MARK: ForeSeeAdobeExtensionDelegate
  
  func shouldStartSDK() -> Bool {
    return true
  }

  func didStartSDK() {
    print("started ForeSee SDK")
  }
}

