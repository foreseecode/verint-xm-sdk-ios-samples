//
//  ViewController.m
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "ViewController.h"
#import <EXPCore/EXPCore.h>
#import <UserNotifications/UserNotifications.h>

// must enable modules in your project settings
@import EXPSurveyManagement;

@implementation ViewController

# pragma mark - Actions

- (IBAction)checkEligibility:(id)sender {
    [EXPSurveyManagement checkIfEligibleForSurvey];
}

- (IBAction)resetState:(id)sender {
    [EXPCore resetState];

}

@end
