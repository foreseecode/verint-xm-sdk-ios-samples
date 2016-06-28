//
//  CustomInviteTracker.h
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ForeSee/ForeSee.h>
#import "CustomInviteView.h"
#import <ForeSee/FSInviteHandler.h>
#import <ForeSee/FSInviteDelegate.h>

@interface CustomInviteTracker : NSObject <FSInviteHandler, CustomInviteViewDelegate>

@end
