//
//  FSViewController.m
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSViewController.h"
#import <ForeSee/ForeSee.h>
#import <ForeSeeCxMeasure/ForeSeeCxMeasure.h>

@implementation FSViewController

# pragma mark - Actions

- (IBAction)checkEligibility:(id)sender {
    [ForeSeeCxMeasure checkIfEligibleForSurvey];
}

- (IBAction)resetState:(id)sender {
    [ForeSee resetState];

}

@end
