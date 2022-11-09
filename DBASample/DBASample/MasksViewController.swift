//
//  MasksViewController.swift
//  DBASample
//
//  Created by Roman Tylets (E) on 07.11.2022.
//

import UIKit
import EXPDBA

class MasksViewController: UIViewController {
  
  @IBOutlet weak var textField: UITextField!
  @IBOutlet weak var imageView: UIImageView!
  
  @IBAction func textFieldMaskSwitchChanged(_ sender: UISwitch) {
    if sender.isOn {
      EXPDBA.maskView(textField)
    } else {
      EXPDBA.unmaskView(textField)
    }
  }
  
  @IBAction func imageViewMaskSwitchChanged(_ sender: UISwitch) {
    if sender.isOn {
      EXPDBA.maskView(imageView)
    } else {
      EXPDBA.unmaskView(imageView)
    }
  }
  
}
