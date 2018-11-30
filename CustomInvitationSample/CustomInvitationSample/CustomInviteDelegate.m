//
//  CustomInviteDelegate.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "CustomInviteDelegate.h"
#import <ForeSee/TRMeasure.h>

@implementation CustomInviteDelegate

#pragma mark - FSInviteDelegate

/* These delegate methods capture ForeSee SDK lifecycle events.
 
 */

- (void)willShowInviteForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)willNotShowInviteWithEligibilityFailedForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)willNotShowInviteWithSamplingFailedForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didShowInviteForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didAcceptInviteForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didDeclineInviteForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didShowSurveyForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didCancelSurveyForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didCompleteSurveyForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didFailForMeasure:(TRMeasure *)measure withContactFormatError:(NSError *)error {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didFailForMeasure:(TRMeasure *)measure withMissingInformationError:(NSError *)error {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

- (void)didFailForMeasure:(TRMeasure *)measure withNetworkError:(NSError *)error {
    [self showStatus:NSStringFromSelector(_cmd) measure:measure];
}

#pragma mark - Status

- (void)showStatus:(NSString *)str measure:(TRMeasure *)measure {
    NSLog(@"FSInviteDelegate event = %@ (%@)", [self trim:str], measure.surveyID);
}

- (NSString *)trim:(NSString *)str {
    if ([str length] > 0) {
        return [str substringToIndex:[str length] - 1];
    }
    return str;
}

@end
