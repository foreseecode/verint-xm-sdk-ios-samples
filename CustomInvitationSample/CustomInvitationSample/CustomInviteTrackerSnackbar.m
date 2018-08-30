//
//  CustomInviteTrackerSnackbar.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "CustomInviteTrackerSnackbar.h"
#import "SSSnackbar.h"

#define DURATION 6

@interface CustomInviteTrackerSnackbar ()

@property (nonatomic) SSSnackbar *inviteView;

@end

@implementation CustomInviteTrackerSnackbar

#pragma mark - FSInviteHandler

- (void)show {
    if (!self.inviteView) {
        self.inviteView = [[SSSnackbar alloc] initWithMessage:@"Would you like to take a survey?"
                                                   actionText:@"Yes!"
                                                     duration:DURATION
                                                  actionBlock:^(SSSnackbar *sender) {
                                                      [ForeSee customInviteAccepted];
                                                  } dismissalBlock:^(SSSnackbar *sender) {
                                                      [ForeSee customInviteDeclined];
                                                  }];
        [self.inviteView show];
    }
}

- (void)hideWithAnimation:(BOOL)animate {
    self.inviteView.dismissalBlock = nil;
    self.inviteView = nil;
}

- (void)dealloc {
    if (self.inviteView) {
        [self.inviteView dismiss];
        [ForeSee customInviteDeclined];
    }
    
}

@end
