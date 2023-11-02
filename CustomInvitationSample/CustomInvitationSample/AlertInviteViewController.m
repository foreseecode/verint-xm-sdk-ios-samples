//
//  AlertInviteViewController.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "AlertInviteViewController.h"
#import "CustomInviteHandler.h"

@implementation AlertInviteViewController

- (void)viewDidLoad {
    self.inviteHandler = [[CustomInviteHandler alloc] initWithViewController:self];
    [EXPPredictive setInviteHandler:self.inviteHandler];
}

- (IBAction)handleShowInviteTouchUpInside:(id)sender {
    [EXPPredictive checkIfEligibleForSurvey];
}

- (IBAction)resetState:(id)sender {
    [EXPCore resetState];
}

@end
