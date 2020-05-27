//
//  CustomInviteHandler.h
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ForeSee/ForeSee.h>
#import <ForeSeeCxMeasure/FSInviteHandler.h>

@interface CustomInviteHandler : NSObject <FSInviteHandler>

- (id)initWithViewController:(UIViewController *)viewController;

@end
