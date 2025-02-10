//
//  InvitelessExampleViewController.swift
//  CustomInvitationSample
//
//  Created by Burkett, Wayne on 4/3/24.
//  Copyright © 2024 Verint. All rights reserved.
//

import Foundation
import EXPCore
import EXPSurveyManagement

class NoInviteExampleViewController : InviteExampleViewController, EXPInviteHandler, VerintDelegate  {

    @IBOutlet weak var showSurveyButton: UIButton!

    // MARK: UIViewController

    override func viewDidLoad() {
        self.inviteHandler = self
        self.showSurveyButton.isUserInteractionEnabled = false
        EXPCore.setDelegate(self)
        EXPCore.start(withAppId: "telekomcfmkeymeinmagentaapp9test")
        
    }

    // MARK: Outlets

    @IBAction func showInvitelessSurvey(_ sender: Any) {
        SurveyManagement.incrementSignificantEventCount(withKey: "mma-nps")
        SurveyManagement.checkIfEligibleForSurvey()
    }

    @IBAction func resetState(_ sender: Any) {
        EXPCore.resetState()
    }
    
    // MARK: VerintDelegate
    
    func didStartSDK() {
        self.showSurveyButton.isUserInteractionEnabled = true
        EXPPredictive.setInviteHandler(self.inviteHandler)
    }

    // MARK: EXPInviteHandler

    func show() {
        // In this example we're going to skip the invite and implicitly accept it
        EXPPredictive.customInviteAccepted()
    }

    func hide(withAnimation animate: Bool) {
        // noop; nothing to do
    }
}
