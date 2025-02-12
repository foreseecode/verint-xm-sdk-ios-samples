//
//  ViewController.swift
//  SwiftSample
//
//  Created by Wayne Burkett on 11/7/19.
//  Copyright © 2019 ForeSee. All rights reserved.
//

import UIKit
import EXPCore
import EXPSurveyManagement

class ViewController: UIViewController {
  
  @IBAction func checkEligibilityButtonTouchUpInside(_ sender: Any) {
    // Show a survey invitation to eligible users
    SurveyManagement.checkIfEligibleForSurvey()
  }
  
  @IBAction func resetStateButtonTouchUpInside(_ sender: Any) {
    // Reset the state of the SDK (for example after showing an invite, so that
    // the user is eligible to see another one). You wouldn't typically do this
    // in a production app, but it's useful when testing.
    EXPCore.resetState()
  }
}

