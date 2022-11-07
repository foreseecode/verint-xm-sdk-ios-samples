//
//  ViewController.swift
//  DBASample
//
//  Created by Roman Tylets (E) on 04.11.2022.
//

import UIKit
import EXPCore

class ViewController: UIViewController {
  
  override func viewDidLoad() {
    super.viewDidLoad()
    EXPCore.start(withConfigurationFile: "exp_configuration.json")
  }
  
  @IBAction func startRecordingAction(_ sender: Any) {
    
  }
  
  @IBAction func stopRecordingAction(_ sender: Any) {
    
  }

}

