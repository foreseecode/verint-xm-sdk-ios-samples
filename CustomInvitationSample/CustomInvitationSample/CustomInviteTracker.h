//
//  CustomInviteTracker.h
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CustomInviteView.h"
#import <EXPPredictive/EXPInviteHandler.h>

@interface CustomInviteTracker : NSObject <EXPInviteHandler, CustomInviteViewDelegate>

@end
