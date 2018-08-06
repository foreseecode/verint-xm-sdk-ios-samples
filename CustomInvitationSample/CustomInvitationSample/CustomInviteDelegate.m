//
//  CustomInviteDelegate.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "CustomInviteDelegate.h"
#import "SVProgressHUD.h"
#import <ForeSee/TRMeasure.h>

@implementation CustomInviteDelegate

#pragma mark - FSInviteDelegate

- (void)willShowInviteForMeasure:(TRMeasure *)measure {
    NSLog(@"Showing invite for %@", measure.surveyID);
    [self showStatus:NSStringFromSelector(_cmd)];
}

- (void)willNotShowInviteWithEligibilityFailedForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd)];
}

- (void)willNotShowInviteWithSamplingFailedForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd)];
}

- (void)didShowInviteForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd)];
}

- (void)didAcceptInviteForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd)];
}

- (void)didDeclineInviteForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd)];
}

- (void)didShowSurveyForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd)];
}

- (void)didCancelSurveyForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd)];
}

- (void)didCompleteSurveyForMeasure:(TRMeasure *)measure {
    [self showStatus:NSStringFromSelector(_cmd)];
}

- (void)didFailForMeasure:(TRMeasure *)measure withContactFormatError:(NSError *)error {
    [self showStatus:NSStringFromSelector(_cmd)];
}

- (void)didFailForMeasure:(TRMeasure *)measure withMissingInformationError:(NSError *)error {
    [self showStatus:NSStringFromSelector(_cmd)];
}

- (void)didFailForMeasure:(TRMeasure *)measure withNetworkError:(NSError *)error {
    [self showStatus:NSStringFromSelector(_cmd)];
}

#pragma mark - Status

- (void)showStatus:(NSString *)str {
    [SVProgressHUD setDefaultStyle:SVProgressHUDStyleDark];
    [SVProgressHUD setDefaultStyle:SVProgressHUDStyleLight];
    [SVProgressHUD setInfoImage:nil];
    [SVProgressHUD setOffsetFromCenter:UIOffsetMake(0, 220)];
    [SVProgressHUD showInfoWithStatus:[NSString stringWithFormat:@"[%@]", [self trim:str]]];
}

- (NSString *)trim:(NSString *)str {
    if ([str length] > 0) {
        return [str substringToIndex:[str length] - 1];
    }
    return str;
}

@end
