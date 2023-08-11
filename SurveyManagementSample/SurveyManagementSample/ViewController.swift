//
//  ViewController.swift
//  SurveyManagementSample
//
//  Created by Burkett, Wayne on 8/11/23.
//

import UIKit
import EXPSurveyManagement

class ViewController: UIViewController {

  override func viewDidLoad() {
    super.viewDidLoad()
    // Do any additional setup after loading the view.
    
  }

  @IBAction func checkEligibility(_ sender: Any) {
    SurveyManagement.checkIfEligibleForSurvey()
  }
  
}

