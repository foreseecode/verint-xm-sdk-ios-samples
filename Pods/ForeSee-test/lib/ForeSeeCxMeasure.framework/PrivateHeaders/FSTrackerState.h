//
//  FSTrackerState.h
//  TriggerTestApp
//
//  Created by Michael Han on 12-05-15.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FSTracker;
@class FSParameters;
@class FSContactDetails;

@protocol FSTrackerState <NSObject>

@required
@property (nonatomic) FSTracker *trackerContext;
@property (nonatomic) FSParameters *cppParameters;
@property (nonatomic, copy) NSString *contactDetails;
@property (nonatomic, readonly) NSString *name;

@required
- (void)checkState;
- (void)incrementSignificantEventCountForKey:(NSString *)key;
- (void)incrementLaunchCount;
- (void)incrementPageViews;
- (void)resetPageViews;
- (void)updateLastLaunchDate;
- (void)onDeclineInvite;
- (void)onSurveyShown;
- (void)onAbandonSurvey;
- (void)onCompleteSurvey;
- (void)onEnableTracking;
- (void)onInviteShown;
- (void)onAcceptInvite;
- (void)showInviteIfEligible;
 
@end
