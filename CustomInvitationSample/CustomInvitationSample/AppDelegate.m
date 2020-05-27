//
//  AppDelegate.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "AppDelegate.h"
#import "CustomInviteDelegate.h"

@interface AppDelegate ()

@property (nonatomic) CustomInviteDelegate *triggerDelegate;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [ForeSee setDebugLogEnabled:YES];
    [ForeSee setEventLogEnabled:NO];
    [ForeSee start];
    
    // capture and log ForeSee lifecycle events;
    // active for all examples
    self.triggerDelegate = [[CustomInviteDelegate alloc] init];
    [ForeSeeCxMeasure setInviteDelegate:self.triggerDelegate];
    
    return YES;
}

@end
