//
//  ViewController.m
//  ContactInvitationSample
//
//  Created by Wayne Burkett on 6/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "ViewController.h"
#import <QuartzCore/QuartzCore.h>
#import <ForeSee/ForeSee.h>

@interface ViewController ()

@end

@implementation ViewController

#pragma mark - UIViewController

#pragma mark - IBActions

- (IBAction)handleShowInviteTouchUpInside:(id)sender {
    [ForeSee checkIfEligibleForSurvey];
}

@end
