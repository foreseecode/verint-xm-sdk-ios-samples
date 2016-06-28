//
//  CustomInviteViewBox.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/10/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "CustomInviteViewBox.h"

#define HEIGHT 300
#define MAX_WIDTH 460
#define HORIZONTAL_MARGIN 10

@interface CustomInviteViewBox ()

@end

@implementation CustomInviteViewBox

#pragma mark - UIView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self setup];
    }
    return self;
}

- (void)layoutSubviews {
    
    [self.superview setNeedsLayout];
    
    CGSize inviteSize = [self size];
    self.bounds = CGRectMake(0, 0, inviteSize.width, inviteSize.height);
    self.center = self.superview.center;
    self.frame = CGRectIntegral(self.frame);
}

#pragma mark - Setup

- (void)setup {
    self.alpha = 0;
    self.backgroundColor = [UIColor whiteColor];
    self.layer.cornerRadius = 6;
    self.center = self.center;
    self.frame = CGRectIntegral(self.frame);
    self.autoresizingMask = UIViewAutoresizingNone;
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(handleOrientationChange:)
                                                 name:UIApplicationDidChangeStatusBarOrientationNotification
                                               object:nil];
}

#pragma mark - Size and Orientation

- (CGSize)size {
    UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
    CGFloat width = 0;
    CGRect statusBarFrame = [[UIApplication sharedApplication] statusBarFrame];
    CGFloat statusBarHeight = (orientation == UIInterfaceOrientationPortrait ? statusBarFrame.size.height : 0);
    switch (orientation) {
        case UIDeviceOrientationLandscapeRight:
        case UIDeviceOrientationLandscapeLeft:
            width = self.window.bounds.size.width - (HORIZONTAL_MARGIN + statusBarHeight) * 2;
            break;
        case UIDeviceOrientationPortraitUpsideDown:
        case UIDeviceOrientationPortrait:
        default:
            width = self.window.bounds.size.width - HORIZONTAL_MARGIN * 2;
            break;
    }
    return CGSizeMake(MIN(width, MAX_WIDTH), HEIGHT);
}

- (void)handleOrientationChange:(id)sender {
    [self rotateWithAnimation:YES];
}

- (void)rotateWithAnimation:(BOOL)animate {
    CGSize inviteSize = [self size];
    CGRect newFrame = CGRectMake(self.superview.center.x - inviteSize.width / 2,
                                 self.superview.center.y - inviteSize.height / 2,
                                 inviteSize.width,
                                 inviteSize.height);
    if (animate) {
        [UIView animateWithDuration:0.4
                         animations:^{
                             self.frame = newFrame;
                         }
                         completion:^(BOOL finished) {
                             self.frame = CGRectIntegral(self.frame);
                         }
         ];
    }
    else {
        self.frame = newFrame;
        self.frame = CGRectIntegral(self.frame);
    }
}

@end
