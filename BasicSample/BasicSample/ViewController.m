//
//  ViewController.m
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "ViewController.h"
#import <EXPCore/EXPCore.h>

// must enable modules in your project settings
@import EXPSurveyManagement;

@implementation ViewController

# pragma mark - Actions

- (void)checkEligibility:(id)sender {
  // Show a survey invitation to eligible users
  [EXPSurveyManagement checkIfEligibleForSurvey];
}

- (void)resetState:(id)sender {
  // Reset the state of the SDK (for example after showing an invite, so that
  // the user is eligible to see another one). You wouldn't typically do this
  // in a production app, but it's useful when testing.
  [EXPCore resetState];
}

@end
