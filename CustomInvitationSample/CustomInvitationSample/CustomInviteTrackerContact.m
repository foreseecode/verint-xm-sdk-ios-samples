//
//  CustomInviteTrackerContact.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "CustomInviteTrackerContact.h"
#import "CustomInviteContactView.h"

@interface CustomInviteTrackerContact ()

@property (nonatomic, strong) CustomInviteContactView *inviteView;

@end

@implementation CustomInviteTrackerContact

#pragma mark - FSInviteHandler

- (void)show {
    if (!self.inviteView) {
        // create your custom invitation
        self.inviteView = [[CustomInviteContactView alloc] init];
        self.inviteView.delegate = self;
    }
    // show your custom invite
    [self.inviteView showAndOnComplete:nil];
}

- (void)hideWithAnimation:(BOOL)animate {
    __weak CustomInviteTrackerContact *weakSelf = self;
    [self.inviteView hideWithAnimation:animate completion:^() {
        weakSelf.inviteView = nil;
    }];
}

#pragma mark - CustomInviteViewDelegate

- (void)didAcceptInviteView:(CustomInviteView *)inviteView {
    // notify the ForeSee tracker that an invitation was accepted; this helps
    // the tracker maintain the proper state for this user
    [ForeSee customInviteAccepted];
}

- (void)didCancelInviteView:(CustomInviteView *)inviteView {
    [ForeSee customInviteDeclined];
    self.inviteView = nil;
}

@end
