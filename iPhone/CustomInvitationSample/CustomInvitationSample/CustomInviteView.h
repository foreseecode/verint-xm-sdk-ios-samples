//
//  CustomInviteView.h
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CustomInviteViewBox.h"

@class CustomInviteView;

@protocol CustomInviteViewDelegate <NSObject>

- (void)didAcceptInviteView:(CustomInviteView *)inviteView;
- (void)didCancelInviteView:(CustomInviteView *)inviteView;

@end

@interface CustomInviteView : UIView

@property (nonatomic) CustomInviteViewBox *inviteView;
@property (nonatomic) UIImageView *headerImageView;
@property (nonatomic) UIImageView *logoImageView;
@property (nonatomic) UILabel *headerLabel;
@property (nonatomic) UILabel *bodyLabel;
@property (nonatomic) UIButton *submitButton;
@property (nonatomic) UIButton *cancelButton;

@property (nonatomic, weak) id<CustomInviteViewDelegate> delegate;

- (void)showAndOnComplete:(void (^)())completion;
- (void)hideWithAnimation:(BOOL)animate completion:(void (^)())completion;

@end

