//
//  AppDelegate.m
//  ContactInvitationSample
//
//  Created by Wayne Burkett on 6/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "AppDelegate.h"
#import <ForeSee/ForeSee.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [ForeSee setDebugLogEnabled:YES];
    [ForeSee setEventLogEnabled:YES];
    [ForeSee start];
    return YES;
}

@end
