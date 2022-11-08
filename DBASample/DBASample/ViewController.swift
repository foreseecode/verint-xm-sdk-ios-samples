//
//  ViewController.swift
//  DBASample
//
//  Created by Roman Tylets (E) on 04.11.2022.
//

import UIKit
import EXPDBA

class ViewController: UIViewController {
  
  override func viewDidLoad() {
    super.viewDidLoad()
    EXPCore.start(withConfigurationFile: "exp_configuration.json")
    EXPCore.setDebugLogEnabled(true)
    EXPDBA.setMaskingDebugEnabled(true)
  }
  
  @IBAction func startRecordingAction(_ sender: Any) {
    EXPDBA.requestBeginRecording()
  }
  
  @IBAction func stopRecordingAction(_ sender: Any) {
    EXPDBA.stopRecording()
  }

}

