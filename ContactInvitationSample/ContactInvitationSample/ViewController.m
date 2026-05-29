//
//  ViewController.m
//  ContactInvitationSample
//
//  Created by Wayne Burkett on 6/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "ViewController.h"
#import <QuartzCore/QuartzCore.h>
#import <EXPCore/EXPCore.h>
#import <EXPSurveyManagement/EXPSurveyManagement.h>

@interface ViewController ()

@end

@implementation ViewController

#pragma mark - UIViewController



#pragma mark - IBActions

- (IBAction)handleShowInviteTouchUpInside:(id)sender {
    [EXPSurveyManagement checkIfEligibleForSurvey];
}

- (IBAction)handleResetState:(id)sender {
    [EXPCore resetState];
    [EXPSurveyManagement setInviteHandler:nil];
}

@end
