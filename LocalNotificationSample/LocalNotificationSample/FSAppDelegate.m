//
//  FSAppDelegate.m
//  LocalNotificationSample
//
//  Created by Michael Han on 12-06-08.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSAppDelegate.h"
#import "FSViewController.h"
#import <ForeSee/ForeSee.h>

@implementation FSAppDelegate

@synthesize window = _window;
@synthesize viewController = _viewController;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
  // Override point for customization after application launch.
  self.viewController = [[FSViewController alloc] initWithNibName:@"FSViewController" bundle:nil];
  self.window.rootViewController = self.viewController;
  
  [self initializeForeSeeTrigger];
  [self.window makeKeyAndVisible];
  return YES;
}

- (void)initializeForeSeeTrigger {
  [ForeSee setDebugLogEnabled:YES];
  [ForeSee setSkipPoolingCheck:YES];
  [ForeSee resetState];

  [ForeSee start];
  [ForeSee checkIfEligibleForSurvey];
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {
  // Allow the API to handle the notification
  NSString *surveyID = [notification.userInfo objectForKey:FSLocalNotificationMeasureKey];
  [ForeSee showSurveyForSurveyID:surveyID];
}
@end
