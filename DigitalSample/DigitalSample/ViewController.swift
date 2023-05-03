//
//  ViewController.swift
//  DigitalSample
//
//  Created by Alan Wang on 11/14/18.
//  Copyright © 2018 Alan Wang. All rights reserved.
//

import UIKit
import EXPCore
import EXPDigital

class ViewController: UIViewController {

  override func viewDidLoad() {
    super.viewDidLoad()
    // Do any additional setup after loading the view, typically from a nib.
    EXPCore.setDebugLogEnabled(true)
    EXPCore.resetState()
  }

  @IBAction func launchFeedback1(_ sender: Any) {
    EXPCore.resetState()
    DigitalComponent.showDigitalSurvey()
  }
  
  @IBAction func launchFeedback2(_ sender: Any) {
    DigitalComponent.showDigitalSurveyForName("Sample 2")
  }

}

