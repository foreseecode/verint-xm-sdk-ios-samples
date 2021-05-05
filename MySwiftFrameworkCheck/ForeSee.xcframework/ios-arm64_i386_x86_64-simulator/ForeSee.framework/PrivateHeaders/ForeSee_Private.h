//
//  ForeSee_Private.h
//  Foresee
//
//  Created by Michael Han on 2013-05-17.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <ForeSee/ForeSee.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@protocol FSInviteDelegate;
@protocol FSInviteHandler;
@protocol FSTriggerDelegate;
@protocol FSFeedbackDelegate;
@protocol FSReplayDelegate;

@protocol ForeSeeComponent;
@class FSConfiguration;
@class FSEnvironment;

@interface ForeSee () {
}

@property (nonatomic, weak) id<ForeSeeDelegate> sdkDelegate;
@property (nonatomic, strong) FSConfiguration *configuration;
@property (nonatomic, strong) FSEnvironment *environment;
@property (nonatomic, strong) NSString *configurationContainer;
@property (nonatomic, strong) NSString *configSource;

#pragma mark - Components

// nothing else references these, so despite looking like normal delegates, they need to be strongly held
@property (nonatomic, strong) id<FSTriggerDelegate, ForeSeeComponent> triggerDelegate;
@property (nonatomic, strong) id<FSReplayDelegate, ForeSeeComponent> replayDelegate;
@property (nonatomic, strong) id<FSFeedbackDelegate, ForeSeeComponent> feedbackDelegate;

+ (ForeSee *)sharedInstance;
+ (BOOL)isSupported;

- (void)setup;
- (void)resetState;
- (void)endSession;

@end
