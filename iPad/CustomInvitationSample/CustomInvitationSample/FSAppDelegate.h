//
//  FSAppDelegate.h
//  CustomInvitationSample
//
//  Created by Michael Han on 12-03-05.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CustomTrackerDelegate.h"

@interface FSAppDelegate : UIResponder <UIApplicationDelegate, UITabBarControllerDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) UITabBarController *tabBarController;
@property (nonatomic, retain) CustomTrackerDelegate *trackerDelegate;

@end
