//
//  CustomInvitationDelegate.h
//  iPadExampleWithCustomInvitation
//
//  Created by Michael Han on 12-03-02.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CustomInvitationDelegate <NSObject>

- (void)inviteViewClickedOKButton:(CustomInvitation *)inviteView;
- (void)inviteViewClickedCancelButton:(CustomInvitation *)inviteView;

@end
