//
//  ViewController.swift
//  FeedbackSample
//
//  Created by Alan Wang on 11/14/18.
//  Copyright © 2018 Alan Wang. All rights reserved.
//

import UIKit
import ForeSee
import ForeSeeFeedback

class ViewController: UIViewController {

  override func viewDidLoad() {
    super.viewDidLoad()
    // Do any additional setup after loading the view, typically from a nib.
    ForeSee.setDebugLogEnabled(true)
    ForeSee.resetState()
  }

  @IBAction func launchFeedback1(_ sender: Any) {
    ForeSee.resetState()
    ForeSeeFeedbackComponent.showFeedbackSurvey()
  }
  
  @IBAction func launchFeedback2(_ sender: Any) {
    ForeSeeFeedbackComponent.showFeedbackForName("Sample 2")
  }

}

