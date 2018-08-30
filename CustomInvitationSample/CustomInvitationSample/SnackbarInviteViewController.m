//
//  SnackbarInviteViewController.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "SnackbarInviteViewController.h"
#import "CustomInviteTrackerSnackbar.h"

@implementation SnackbarInviteViewController

- (void)viewDidLoad {
    self.inviteHandler = [[CustomInviteTrackerSnackbar alloc] init];
    [ForeSee setInviteHandler:self.inviteHandler];
}

- (IBAction)handleShowInviteTouchUpInside:(id)sender {
    [ForeSee checkIfEligibleForSurvey];
}

@end
