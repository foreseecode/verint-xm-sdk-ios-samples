//
//  FSTriggerDelegate.h
//  ForeSee
//
//  Created by Wayne Burkett on 8/20/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FSTracker;
@class TriggerConfiguration;

@protocol FSTriggerDelegate <NSObject>

@property (nonatomic, readonly) FSTracker *tracker;
@property (nonatomic, readonly) TriggerConfiguration *triggerConfiguration;
@property (nonatomic, readonly) NSString *invitationModeName;
@property (nonatomic, readonly) NSUInteger measureCount;

- (void)setSkipPoolingCheck:(BOOL)shouldSkip;
- (BOOL)shouldSkipPoolingCheck;
- (void)incrementSignificantEventCountWithKey:(NSString *)key;
- (void)incrementSignificantEventCountAndCheckEligibilityWithKey:(NSString *)key;
- (void)incrementPageViews;
- (void)showSurveyForSurveyID:(NSString *)surveyID;
- (void)showInviteForSurveyID:(NSString *)surveyID;
- (void)checkIfEligibleForSurvey;
- (void)disableTracking;
- (void)enableTracking;
- (void)resetTracking;
- (NSString *)surveyIdForNotificationResponse:(UNNotificationResponse *)response;
- (void)showSurveyForNotificationResponse:(UNNotificationResponse *)response;
- (void)customInviteAccepted;
- (void)customInviteAcceptedWithContactDetails:(NSString *)contactDetails;
- (void)customInviteDeclined;
- (NSString *)contactDetailsForType:(FSContactType)type;
- (void)setContactDetails:(NSString *)contactDetails forType:(FSContactType)type;
- (void)setPreferredContactType:(FSContactType)type;
- (FSContactType)preferredContactType;
- (NSDictionary<NSNumber *, NSString *> *)allContactDetails;
- (void)clearUserData;
- (void)setContactDetails:(NSString *)contactDetails;
- (NSString *)contactDetails;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
- (NSString *)surveyIDForLocalNotification:(UILocalNotification *)note;
- (void)showSurveyForLocalNotification:(UILocalNotification *)note;
#pragma clang diagnostic pop

@end
