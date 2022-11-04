//
//  ViewController.swift
//  SwiftSample
//
//  Created by Wayne Burkett on 11/7/19.
//  Copyright © 2019 ForeSee. All rights reserved.
//

import UIKit
import EXPCore
import EXPPredictive

class ViewController: UIViewController {
  
  override func viewDidLoad() {
    super.viewDidLoad()
    
    EXPCore.setDebugLogEnabled(true)
    EXPCore.resetState()
  }
  
  @IBAction func checkEligibilityButtonTouchUpInside(_ sender: Any) {
    EXPPredictive.checkIfEligibleForSurvey()
  }
  
  @IBAction func resetStateButtonTouchUpInside(_ sender: Any) {
    EXPCore.resetState()
  }
}

