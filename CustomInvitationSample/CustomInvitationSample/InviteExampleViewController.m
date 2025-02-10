//
//  InviteExampleViewController.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 6/1/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "InviteExampleViewController.h"

@implementation InviteExampleViewController

- (void)viewWillAppear:(BOOL)animated {
    // reset state so that we always show the example; a
    // normal production application should not reset state
    // every time -- you *want* to track the user's state!
    //[EXPCore resetState]; // Disable for testing
}

- (void)viewWillDisappear:(BOOL)animated {
    self.inviteHandler = nil;
    [EXPPredictive setInviteHandler:nil];
}

@end
