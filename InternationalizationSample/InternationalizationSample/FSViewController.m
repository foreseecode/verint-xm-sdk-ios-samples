//
//  FSViewController.m
//  InternationalizationSample
//
//  Created by Michael Han on 12-03-05.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSViewController.h"
#import <ForeSee/ForeSee.h>

@implementation FSViewController

# pragma mark - Actions

- (IBAction)checkEligibility:(id)sender {
  [ForeSee checkIfEligibleForSurvey];
}

- (IBAction)resetState:(id)sender {
  [ForeSee resetState];
}

@end
