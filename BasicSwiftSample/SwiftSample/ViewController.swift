//
//  ViewController.swift
//  SwiftSample
//
//  Created by Wayne Burkett on 11/7/19.
//  Copyright © 2019 ForeSee. All rights reserved.
//

import UIKit
import ForeSee
import ForeSeeCxMeasure

class ViewController: UIViewController {
  
  override func viewDidLoad() {
    super.viewDidLoad()
    
    ForeSee.setDebugLogEnabled(true)
    ForeSee.resetState()
  }
  
  @IBAction func checkEligibilityButtonTouchUpInside(_ sender: Any) {
    ForeSeeCxMeasure.checkIfEligibleForSurvey()
  }
  
  @IBAction func resetStateButtonTouchUpInside(_ sender: Any) {
    ForeSee.resetState()
  }
}

