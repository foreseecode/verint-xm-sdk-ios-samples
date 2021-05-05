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

typedef NS_ENUM(NSUInteger, FSContactType);

@protocol FSTriggerDelegate <NSObject>

@property (nonatomic, readonly) FSTracker *tracker;
@property (nonatomic, readonly) TriggerConfiguration *triggerConfiguration;
@property (nonatomic, readonly) NSString *invitationModeName;
@property (nonatomic, readonly) NSUInteger measureCount;
@property (nonatomic, assign) id<FSInviteDelegate> delegate;
@property (nonatomic, assign) id<FSInviteHandler> inviteHandler;

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
- (NSString *)surveyIdForNotificationResponse:(UNNotificationResponse *)response API_AVAILABLE(ios(10));
- (void)showSurveyForNotificationResponse:(UNNotificationResponse *)response API_AVAILABLE(ios(10));
- (void)customInviteAccepted;
- (void)customInviteDeclined;
- (NSString *)contactDetailsForType:(FSContactType)type;
- (void)setContactDetails:(NSString *)contactDetails forType:(FSContactType)type;
- (void)setPreferredContactType:(FSContactType)type;
- (FSContactType)preferredContactType;
- (NSDictionary<NSNumber *, NSString *> *)allContactDetails;
- (void)clearUserData;

@end
