//
//  FSInvitationMode.h
//  TriggerTestApp
//
//  Created by Michael Han on 12-05-09.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FSTracker;
@class TRMeasure;
@protocol FSInviteResultDelegate;
@protocol FSInviteHandler_Private;

@protocol FSInvitationMode <NSObject>

@required

@property (nonatomic, retain) FSTracker *tracker;
@property (nonatomic) id<FSInviteResultDelegate> inviteDelegate;
@property (nonatomic) id<FSInviteHandler_Private> inviteViewController;
@property (nonatomic, retain) TRMeasure *measure;
@property (nonatomic, assign, getter = isActive) BOOL active;

- (void)showInviteForMeasure:(TRMeasure *)measure completion:(void(^)(void))completion;
- (void)didAcceptInvite;
- (void)didDeclineInvite;

@end
