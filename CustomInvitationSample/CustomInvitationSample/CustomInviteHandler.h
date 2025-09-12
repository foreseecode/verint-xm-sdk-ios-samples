//
//  CustomInviteHandler.h
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <EXPCore/EXPCore.h>
#import <EXPPredictive/EXPInviteHandler.h>
#import <EXPSurveyManagement/EXPSurveyManagement.h>

@interface CustomInviteHandler : NSObject <EXPInviteHandler>

- (id)initWithViewController:(UIViewController *)viewController;

@end
