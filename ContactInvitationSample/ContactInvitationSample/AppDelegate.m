//
//  AppDelegate.m
//  ContactInvitationSample
//
//  Created by Wayne Burkett on 6/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "AppDelegate.h"
#import <EXPCore/EXPCore.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [EXPCore setDebugLogEnabled:YES];
    [EXPCore setEventLogEnabled:YES];
    [EXPCore start];
    return YES;
}

@end
