//
//  CustomInviteViewController.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "CustomInviteViewController.h"
#import "CustomInviteTracker.h"
#import <ForeSee/ForeSee.h>
#import <ForeSee/FSInviteHandler.h>

@implementation CustomInviteViewController

- (void)viewDidLoad {
    self.inviteHandler = [[CustomInviteTracker alloc] init];
    [ForeSee setInviteHandler:self.inviteHandler];
}

- (IBAction)handleShowInviteTouchUpInside:(id)sender {
    // check for eligibility (which is what triggers the invite)
    [ForeSee checkIfEligibleForSurvey];
}

@end
