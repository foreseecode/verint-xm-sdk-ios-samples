//
//  ForeSee Results iOS Trigger Code Framework
//
//  Created by ForeSee Results.
//  Copyright 2011 ForeSee Results. All rights reserved.
//

@class TRMeasure;

@protocol FSTrackerDelegate <NSObject>

@optional
- (UINavigationBar *)navigationBarForSurveyViewController;

- (void)trackerWillShowInviteForMeasure:(TRMeasure *)measure;
- (void)trackerDidShowInviteForMeasure:(TRMeasure *)measure;

- (void)trackerDidDeclineInviteForMeasure:(TRMeasure *)measure;
- (void)trackerDidAcceptInviteForMeasure:(TRMeasure *)measure;

- (BOOL)trackerWillShowSurveyForMeasure:(TRMeasure *)measure;
- (void)trackerDidShowSurveyForMeasure:(TRMeasure *)measure;

- (void)trackerDidCompleteSurveyForMeasure:(TRMeasure *)measure;
- (void)trackerDidAbandonSurveyForMeasure:(TRMeasure *)measure;

- (void)trackerDidElapseRepeatDays;

- (void)trackerDidFailForMeasure:(TRMeasure *)measure withContactFormatError:(NSError *)error;
- (void)trackerDidFailForMeasure:(TRMeasure *)measure withMissingInformationError:(NSError *)error;
- (void)trackerDidFailForMeasure:(TRMeasure *)measure withNetworkError:(NSError *)error;

- (void)trackerWillNotShowInviteWithEligibilityFailedForMeasure:(TRMeasure *)measure;
- (void)trackerWillNotShowInviteWithSamplingFailedForMeasure:(TRMeasure *)measure;

@end

