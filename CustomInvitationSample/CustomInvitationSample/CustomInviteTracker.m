//
//  CustomInviteTracker.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "CustomInviteTracker.h"
#import "CustomInviteView.h"

@interface CustomInviteTracker ()

@property (nonatomic, strong) CustomInviteView *inviteView;
@property (nonatomic) NSString *surveyId;

@end

@implementation CustomInviteTracker

#pragma mark - FSInviteHandler

- (void)show {
    if (!self.inviteView) {
        // create your custom invitation
        self.inviteView = [[CustomInviteView alloc] init];
        self.inviteView.delegate = self;
    }
    // show your custom invite
    [self.inviteView showAndOnComplete:nil];
}

- (void)hideWithAnimation:(BOOL)animate {
    __weak CustomInviteTracker *weakSelf = self;
    [self.inviteView hideWithAnimation:animate completion:^() {
        weakSelf.inviteView = nil;
    }];
}

#pragma mark - CustomInviteViewDelegate

- (void)didAcceptInviteView:(CustomInviteView *)inviteView {
    // notify the ForeSee tracker that an invitation was accepted; this helps
    // the tracker maintain the proper state for this user
    [EXPPredictive customInviteAccepted];
}

- (void)didCancelInviteView:(CustomInviteView *)inviteView {
    [EXPPredictive customInviteDeclined];
    self.inviteView = nil;
}

@end
