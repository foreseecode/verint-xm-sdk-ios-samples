//
//  FSCloseButton.h
//  ForeSee
//
//  Created by Wayne Burkett on 5/17/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>

extern const UIButtonType UIButtonTypeCloseInvite;
extern const UIButtonType UIButtonTypeCloseInviteInside;

@interface FSCloseButton : UIButton

- (void)layoutRelativeToView:(UIView *)inviteView;

@end
