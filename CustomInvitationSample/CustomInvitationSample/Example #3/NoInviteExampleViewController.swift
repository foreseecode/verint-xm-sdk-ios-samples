//
//  InvitelessExampleViewController.swift
//  CustomInvitationSample
//
//  Created by Burkett, Wayne on 4/3/24.
//  Copyright © 2024 Verint. All rights reserved.
//

import Foundation
import EXPSurveyManagement

class NoInviteExampleViewController : InviteExampleViewController, EXPInviteHandler  {

    // MARK: UIViewController

    override func viewDidLoad() {
        self.inviteHandler = self
        EXPPredictive.setInviteHandler(self.inviteHandler)
    }

    // MARK: Outlets

    @IBAction func showInvitelessSurvey(_ sender: Any) {
        SurveyManagement.checkIfEligibleForSurvey()
    }

    @IBAction func resetState(_ sender: Any) {
        EXPCore.resetState()
    }

    // MARK: EXPInviteHandler

    func show() {
        // In this example we're going to skip the invite and implicitly accept it
        SurveyManagement.customInviteAccepted()
    }

    func hide(withAnimation animate: Bool) {
        // noop; nothing to do
    }
}
