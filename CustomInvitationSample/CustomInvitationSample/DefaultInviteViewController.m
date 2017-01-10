//
//  DefaultInviteViewController.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 6/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "DefaultInviteViewController.h"
#import <ForeSee/ForeSee.h>

@interface DefaultInviteViewController ()

@end

@implementation DefaultInviteViewController

- (IBAction)handleShowInviteTouchUpInside:(id)sender {
    [ForeSee checkIfEligibleForSurvey];
}

@end
