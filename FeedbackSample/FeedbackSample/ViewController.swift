//
//  ViewController.swift
//  FeedbackSample
//
//  Created by Alan Wang on 11/14/18.
//  Copyright © 2018 Alan Wang. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

  override func viewDidLoad() {
    super.viewDidLoad()
    // Do any additional setup after loading the view, typically from a nib.
    ForeSee.setDebugLogEnabled(true)
    ForeSee.resetState()
    ForeSeeFeedback.checkIfFeedbackEnabledForName("Sample 2");
  }


}

