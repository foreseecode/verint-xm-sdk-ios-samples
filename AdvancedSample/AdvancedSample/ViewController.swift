//
//  ViewController.swift
//  AdvancedSample
//
//  Created by Wayne Burkett on 11/12/19.
//  Copyright © 2019 ForeSee. All rights reserved.
//

import UIKit
import ForeSee
import ForeSeeCxMeasure
import ForeSeeFeedback

class ViewController: UIViewController {

  static let surveyId = "mobile_app-en"
  static let significantEventKey = "app_test_1"
  
  var counter: (() -> Int)? = nil
  
  // MARK: Outlets
  
  @IBOutlet weak var incrementEventButton: UIButton!
  
  // MARK: UIViewController
  
  override func viewDidLoad() {
    super.viewDidLoad()

    resetState()
  }
  
  // MARK: Actions
  
  @IBAction func checkEligibilityButtonTouchUpInside(_ sender: Any) {
    ForeSeeCxMeasure.checkIfEligibleForSurvey()
  }
  
  @IBAction func checkFeedbackEligibilityButtonTouchUpInside(_ sender: Any) {
    ForeSeeFeedbackComponent.showFeedbackSurvey()
  }
  
  @IBAction func incrementEventButtonTouchUpInside(_ sender: Any) {
    updateIncrementEventButtonLabel(counter!())
  }
  
  @IBAction func resetStateButtonTouchUpInside(_ sender: Any) {
    resetState()
  }
  
  // MARK: Helpers
  
  func updateIncrementEventButtonLabel(_ count: Int) {
    incrementEventButton.setTitle("Increment Count (\(count))", for: .normal)
  }
  
  func resetState() {
    counter = ViewController.makeCounter()
    updateIncrementEventButtonLabel(0)
  }
  
  static func makeCounter() -> () -> Int {
    var counter = 0
    // when we create the counter, we also reset the ForeSee state back to zero
    ForeSee.resetState()
    return {
      // now we incremenet the significant event count every time we update our
      // counter, so that our local value is always in sync with the ForeSee SDK (as
      // long as we don't increment this count anywhere else)
      ForeSeeCxMeasure.incrementSignificantEventCount(withKey: significantEventKey)
      counter += 1
      return counter
    }
  }
}

