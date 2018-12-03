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

- (void)triggerInvite:(id)sender {
  [ForeSee resetState];
  [ForeSee checkIfEligibleForSurvey];
}

@end
