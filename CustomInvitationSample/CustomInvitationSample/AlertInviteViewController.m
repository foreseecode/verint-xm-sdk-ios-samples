//
//  SnackbarInviteViewController.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "AlertInviteViewController.h"
#import "CustomInviteTrackerSnackbar.h"

@implementation AlertInviteViewController

- (void)viewDidLoad {
    self.inviteHandler = [[CustomInviteTrackerSnackbar alloc] initWithViewController:self];
    [ForeSee setInviteHandler:self.inviteHandler];
}

- (IBAction)handleShowInviteTouchUpInside:(id)sender {
    [ForeSee checkIfEligibleForSurvey];
}

- (IBAction)resetState:(id)sender {
    [ForeSee resetState];
}

@end
