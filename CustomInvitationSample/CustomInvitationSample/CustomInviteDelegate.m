//
//  CustomInviteDelegate.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "CustomInviteDelegate.h"
#import <EXPPredictive/EXPMeasure.h>

@implementation CustomInviteDelegate

#pragma mark - EXPInviteDelegate

/* These delegate methods capture SDK lifecycle events.
 
 */

- (void)willShowInviteForMeasure:(EXPMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)willNotShowInviteWithEligibilityFailedForMeasure:(EXPMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)willNotShowInviteWithSamplingFailedForMeasure:(EXPMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didShowInviteForMeasure:(EXPMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didAcceptInviteForMeasure:(EXPMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didDeclineInviteForMeasure:(EXPMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didShowSurveyForMeasure:(EXPMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didCancelSurveyForMeasure:(EXPMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didCompleteSurveyForMeasure:(EXPMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didFailForMeasure:(EXPMeasure *)measure withContactFormatError:(NSError *)error {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didFailForMeasure:(EXPMeasure *)measure withMissingInformationError:(NSError *)error {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didFailForMeasure:(EXPMeasure *)measure withNetworkError:(NSError *)error {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

#pragma mark - Status

- (void)showStatus:(NSString *)str measure:(EXPMeasure *)measure {
    NSLog(@"EXPInviteDelegate event = %@ (%@)", [self trim:str], measure.surveyID);
}

- (NSString *)trim:(NSString *)str {
    if ([str length] > 0) {
        return [str substringToIndex:[str length] - 1];
    }
    return str;
}

@end
