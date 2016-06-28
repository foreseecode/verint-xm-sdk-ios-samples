//
//  FSViewController.m
//  OnExitSurveySample
//
//  Created by Michael Han on 12-06-08.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSViewController.h"
#import <ForeSee/ForeSee.h>

@implementation FSViewController

- (IBAction)resetCounters:(id)sender {
  [ForeSee resetState];
}

- (IBAction)checkEligibility:(id)sender {
  [ForeSee checkIfEligibleForSurvey];
}

@end
