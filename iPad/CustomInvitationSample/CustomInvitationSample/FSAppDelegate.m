//
//  FSAppDelegate.m
//  CustomInvitationSample
//
//  Created by Michael Han on 12-03-05.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSAppDelegate.h"
#import "FSFirstViewController.h"
#import "FSSecondViewController.h"
#import "CustomTrackerDelegate.h"
#import <ForeSee/ForeSee.h>

@implementation FSAppDelegate

@synthesize window = _window;
@synthesize tabBarController = _tabBarController;
@synthesize trackerDelegate = trackerDelegate_;

- (void)dealloc {
  [_window release];
  [_tabBarController release];
  [super dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];
    // Override point for customization after application launch.
  UIViewController *viewController1 = [[[FSFirstViewController alloc] initWithNibName:@"FSFirstViewController" bundle:nil] autorelease];
  UIViewController *viewController2 = [[[FSSecondViewController alloc] initWithNibName:@"FSSecondViewController" bundle:nil] autorelease];
  self.tabBarController = [[[UITabBarController alloc] init] autorelease];
  self.tabBarController.viewControllers = [NSArray arrayWithObjects:viewController1, viewController2, nil];
  
  // Use our custom implemented CustomTrackerDelegate class to display our custom invite view
  self.trackerDelegate = [[[CustomTrackerDelegate alloc] init] autorelease];

  self.window.rootViewController = self.tabBarController;
  [self.window makeKeyAndVisible];
  
  [ForeSee setDebugLogEnabled:YES];
  [ForeSee setSkipPoolingCheck:YES];
  [ForeSee start];
  [ForeSee setTriggerDelegate:self.trackerDelegate];
  [ForeSee checkIfEligibleForSurvey];

  return YES;
}

@end
