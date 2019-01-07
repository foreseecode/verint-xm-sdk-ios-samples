//
//  FSReplayDelegate.h
//  ForeSee
//
//  Created by Wayne Burkett on 8/22/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FSSession;
@class FSReplayConfiguration;

@protocol FSReplayDelegate <NSObject>

@property (nonatomic, readonly) FSSession *session;
@property (nonatomic, readonly) FSReplayConfiguration *replayConfiguration;

- (void)didAcceptInvite;
- (void)didDeclineInvite;
- (void)didCompleteSurvey;
- (void)didAbandonSurvey;
- (void)didElapseRepeatDays;

@end
