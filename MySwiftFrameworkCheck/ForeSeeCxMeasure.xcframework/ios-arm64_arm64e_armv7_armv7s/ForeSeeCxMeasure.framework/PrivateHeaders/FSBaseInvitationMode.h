//
//  FSBaseInvitationMode.h
//  TriggerTestApp
//
//  Created by Michael Han on 12-05-09.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSInvitationMode.h"
#import <ForeSeeCxMeasure/FSInviteViewDelegate.h>
#import <ForeSeeCxMeasure/FSInviteResultDelegate.h>
#import <ForeSee/FSConfiguration.h>

@protocol FSInviteHandler_Private;
@class TRMeasure;
@class FSInviteViewController;

@interface FSBaseInvitationMode : NSObject <FSInvitationMode, FSInviteViewDelegate>

#pragma mark - FSInvitationMode

@property (nonatomic, strong) FSTracker *tracker;
@property (nonatomic, strong) id<FSInviteResultDelegate> inviteResultDelegate;
@property (nonatomic, strong) id<FSInviteHandler_Private> inviteViewController;

@end
