//
//  VerintSurveyInviteManager.swift
//  BasicSample
//
//  Created by Leeke, Selwyn on 11/18/25.
//  Copyright © 2025 Verint. All rights reserved.
//

import EXPPredictive


@objc class SurveyInviteManager: NSObject, EXPInviteDelegate {
  
    func willShowInvite(for measure: EXPMeasure!) {
        print("InviteDelegate::willShowInvite", measure!)
    }
    
    func didShowInvite(for measure: EXPMeasure!) {
        print("InviteDelegate::didShowInvite", measure!)
    }
   
    func willNotShowInviteWithEligibilityFailed(for measure: EXPMeasure!) {
        print("InviteDelegate::willNotShowInviteWithEligibilityFailed", measure!)
    }
   
    func willNotShowInviteWithSamplingFailed(for measure: EXPMeasure!) {
        print("InviteDelegate::willNotShowInviteWithSamplingFailed", measure!)
    }
   
    func didAcceptInvite(for measure: EXPMeasure!) {
        print("InviteDelegate::didAcceptInvite", measure!)
    }
   
    func didDeclineInvite(for measure: EXPMeasure!) {
        print("InviteDelegate::didDeclineInvite", measure!)
    }
   
    func didShowSurvey(for measure: EXPMeasure!) {
        print("InviteDelegate::didShowSurvey", measure!)
    }
   
    func didCancelSurvey(for measure: EXPMeasure!) {
        print("InviteDelegate::didCancelSurvey", measure!)
    }
   
    func didCompleteSurvey(for measure: EXPMeasure!) {
        print("InviteDelegate::didCompleteSurvey", measure!)
    }
}
