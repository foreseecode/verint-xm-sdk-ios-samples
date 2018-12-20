//
//  ForeSee_Private.h
//  Foresee
//
//  Created by Michael Han on 2013-05-17.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <ForeSee/ForeSee.h>
#import <UIKit/UIKit.h>

@protocol FSInviteDelegate;
@protocol FSInviteHandler;
@protocol FSTriggerDelegate;
@protocol FSReplayDelegate;
@protocol FSFeedbackDelegate;

@protocol ForeSeeComponent;
@class FSConfiguration;
@class FSEnvironment;

@interface ForeSee () {
}

@property (nonatomic, retain) FSConfiguration *configuration;
@property (nonatomic, assign) id<FSInviteDelegate> delegate;
@property (nonatomic, assign) id<FSInviteHandler> inviteHandler;
@property (nonatomic, retain) FSEnvironment *environment;

#pragma mark - Components

@property (nonatomic, assign) id<FSTriggerDelegate, ForeSeeComponent> triggerDelegate;
@property (nonatomic, assign) id<FSReplayDelegate, ForeSeeComponent> replayDelegate;
@property (nonatomic, assign) id<FSFeedbackDelegate, ForeSeeComponent> feedbackDelegate;

+ (ForeSee *)sharedInstance;
+ (UIScrollView *)getScrollViewForWebView:(UIWebView *)webView;

- (void)setup;
- (void)resetState;
- (void)endSession;

@end
