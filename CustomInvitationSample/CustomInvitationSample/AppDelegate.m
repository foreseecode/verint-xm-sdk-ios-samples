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

@property (nonatomic) CustomInviteDelegate *inviteDelegate;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [EXPCore setDebugLogEnabled:YES];
    [EXPCore setEventLogEnabled:NO];
    
    // capture and log SDK lifecycle events;
    // active for all examples
    self.inviteDelegate = [[CustomInviteDelegate alloc] init];
    [EXPPredictive setInviteDelegate:self.inviteDelegate];
    
    return YES;
}

@end
