//
//  AppDelegate.m
//  LocalNotificationSample
//
//  Created by Michael Han on 12-06-08.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <EXPCore/EXPCore.h>
#import <EXPPredictive/EXPPredictive.h>

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  [UNUserNotificationCenter currentNotificationCenter].delegate = self;
  [self registerNotificationService];
  [self initializeSDK];
  return YES;
}

- (void)initializeSDK {
  [EXPCore setDebugLogEnabled:YES];
  [EXPPredictive setSkipPoolingCheck:YES];
  [EXPCore resetState];

  [EXPCore start];
  [EXPPredictive checkIfEligibleForSurvey];
}

#pragma mark - UNUserNotificationCenterDelegate

// Called when a notification is delivered to the foregrounded app
- (void)userNotificationCenter:(UNUserNotificationCenter *)center
       willPresentNotification:(UNNotification *)notification
         withCompletionHandler:(nonnull void (^)(UNNotificationPresentationOptions))completionHandler
{
    NSLog(@"User Info : %@",notification.request.content.userInfo);
    completionHandler(UNAuthorizationOptionSound | UNAuthorizationOptionAlert | UNAuthorizationOptionBadge);
}

// Called to let your app know which action was selected by the user for a given notification
- (void)userNotificationCenter:(UNUserNotificationCenter *)center
didReceiveNotificationResponse:(UNNotificationResponse *)response
         withCompletionHandler:(nonnull void (^)(void))completionHandler
{
    [EXPPredictive showSurveyForNotificationResponse:response];
    NSLog(@"User Info : %@",response.notification.request.content.userInfo);
    completionHandler();
}

#pragma mark - Notification Service
- (void)registerNotificationService {
  UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
  [center requestAuthorizationWithOptions:(UNAuthorizationOptionBadge | UNAuthorizationOptionSound | UNAuthorizationOptionAlert)
                        completionHandler:^(BOOL granted, NSError * _Nullable error) {
    if (!error) {
      NSLog(@"request authorization succeeded!");
    }
  }];
}

@end
