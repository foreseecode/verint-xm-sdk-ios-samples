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
}

#pragma mark - Size and Orientation

- (CGSize)size {
    CGFloat width = self.window.bounds.size.width - HORIZONTAL_MARGIN * 2;
    return CGSizeMake(MIN(width, MAX_WIDTH), HEIGHT);
}

@end
