//
//  AppDelegate.m
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "AppDelegate.h"
#import <EXPPredictive/EXPPredictive.h>

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  // Enable debug logs (not typically used in production, but helpful
  // when testing)
  [EXPCore setDebugLogEnabled:YES];

  // Set a VerintDelegate (used to determine when the SDK has started (or if
  // it fails to start)
  [EXPCore setDelegate:self];

  // Set the configuration container. This defaults to "live" and only
  // needs to be supplied when testing with other containers (e.g. "draft").
  [EXPCore setConfigurationContainer:@"live"];

  // Start the SDK with this app's site key
  [EXPCore startWithSiteKey:@"mobsdk-basicsample"];

  return YES;
}

#pragma mark - VerintDelegate

- (void)didStartSDK {
  NSLog(@"Verint XM iOS SDK started");
}

- (void)didStartSDKWithError:(EXPErrorCode)error message:(NSString *)message {
  NSLog(@"Verint XM iOS SDK started with error: %@ (%tu)", message, error);
}

- (void)didFailToStartSDKWithError:(EXPErrorCode)error message:(NSString *)message {
  NSLog(@"Verint XM iOS SDK failed to start with error: %@ (%tu)", message, error);
}

@end
