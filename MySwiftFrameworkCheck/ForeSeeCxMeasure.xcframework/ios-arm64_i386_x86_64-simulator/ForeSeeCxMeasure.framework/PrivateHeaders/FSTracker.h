//
//  ForeSee Results iOS Trigger Code Framework
//
//  Created by ForeSee Results.
//  Copyright 2011 ForeSee Results. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ForeSee/FSWebViewControllerDelegate.h>
#import <IngestionLogger/FSLogger.h>
#import "FSInviteResultDelegate.h"
#import <ForeSee/ForeSee_Private.h>
#import <ForeSee/FSEnvironment.h>
#import "TriggerConfiguration.h"

@class FSSurveyViewController;
@class FSMeasureSurveyViewController;

@protocol FSTrackerDelegate;
@protocol FSTrackerState;
@class FSTrackerStorage;
@class FSConfiguration;
@class FSContactDetails;

@interface FSTracker : NSObject <FSWebViewControllerDelegate, FSInviteResultDelegate>

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

- (id)initWithConfiguration:(FSConfiguration *)configuration;
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
