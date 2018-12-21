//
//  ForeSee Results iOS Trigger Code Framework
//
//  Created by ForeSee Results.
//  Copyright 2011 ForeSee Results. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ForeSee/FSWebViewControllerDelegate.h>
#import <ForeSee/FSLogger.h>
#import "FSInviteResultDelegate.h"
#import <ForeSee/ForeSee_Private.h>
#import <ForeSee/FSContactDetails.h>
#import <ForeSee/FSEnvironment.h>
#import "TriggerConfiguration.h"
#import "FSMeasureSurveyViewController.h"

@class FSSurveyViewController;

@protocol FSTrackerDelegate;
@protocol FSTrackerState;
@class FSTrackerStorage;
@class FSConfiguration;

@interface FSTracker : NSObject <FSWebViewControllerDelegate, FSInviteResultDelegate, FSInviteResultDelegate>

@property (nonatomic, strong) id<FSTrackerDelegate> delegate;
@property (nonatomic, strong) id<FSTrackerState> state;
@property (nonatomic, strong) FSTrackerStorage *storage;
@property (nonatomic, strong) FSConfiguration *configuration;
@property (nonatomic, copy, getter=respondentID) NSString *respondentID;
@property (nonatomic, strong) FSMeasureSurveyViewController *surveyViewController;
@property (nonatomic, strong) FSLogger *logger;
@property (nonatomic, assign, getter = shouldSkipPoolingCheck) BOOL skipPoolingCheck;
@property (nonatomic, strong) FSContactDetails *contactDetails;
@property (nonatomic, copy) NSString *sessionID;
@property (nonatomic, readonly) NSUInteger sessionDurationInSeconds;
@property (nonatomic, readonly) TriggerConfiguration *triggerConfiguration;
@property (nonatomic, readonly) FSEnvironment *environment;

- (id)initWithConfiguration:(FSConfiguration *)configuration environment:(FSEnvironment *)environment;
- (void)checkIfEligibleForSurvey;
- (void)showInviteForSurveyID:(NSString *)surveyID completion:(void(^)(void))completion;
- (void)showSurveyForSurveyID:(NSString *)surveyID completion:(void(^)(void))completion;
- (NSURL *)surveyURLForSurveyID:(NSString *)surveyID;
- (void)incrementSignificantEventsCountWithKey:(NSString *)key;
- (void)incrementSignificantEventCountAndCheckEligibilityWithKey:(NSString *)key;
- (void)incrementLaunchCount;
- (void)incrementPageViews;
- (void)resetPageViews;
- (void)updateLastLaunchDate;
- (void)disableTracking;
- (void)enableTracking;
- (void)resetState;
- (void)saveContactDetails;
- (void)clearContactDetails;

@end
