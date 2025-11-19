//
//  AppDelegate.h
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <EXPCore/EXPCore.h>
#import "BasicSample-Swift.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate, VerintDelegate, EXPInviteDelegate>

@property (strong, nonatomic) UIWindow *window;
@property(strong, nonatomic) SurveyInviteManager* inviteDelegate;

@end
