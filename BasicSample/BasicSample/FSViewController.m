//
//  FSViewController.m
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSViewController.h"
#import <ForeSee/ForeSee.h>

@implementation FSViewController

# pragma mark - Actions

- (void)checkEligibility:(id)sender {
  [ForeSee checkIfEligibleForSurvey];
}

- (void)resetState:(id)sender {
    [ForeSee resetState];
}

@end
