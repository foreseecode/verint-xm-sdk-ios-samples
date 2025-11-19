//
//  AppDelegate.m
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "AppDelegate.h"
#import <EXPPredictive/EXPPredictive.h>
#import "BasicSample-Swift.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  // Enable debug logs (not typically used in production, but helpful
  // when testing)
  [EXPCore setDebugLogEnabled:YES];

  // Set a VerintDelegate (used to determine when the SDK has started
  // (or if it fails to start)
  [EXPCore setDelegate:self];         // This is essential to allow the invite delegate
                                      // to be enabled in didStartSDK, below
  
  // Set the configuration container. This defaults to "live" and only
  // needs to be supplied when testing with other containers (e.g. "draft").
  [EXPCore setConfigurationContainer:@"live"];

  // Start the SDK with this app's site key
  [EXPCore startWithSiteKey:@"mobsdk-basicsample"];

  return YES;
}

- (void)didShowInviteForMeasure:(EXPMeasure *)measure {
  NSLog(@"Shown invite");
}

#pragma mark - VerintDelegate

- (void)didStartSDK {
  NSLog(@"Verint XM iOS SDK started");
  
  // Set an invite delegate to capture invite lifecycle events
  // This must be done after the SDK has started,
  // which is why it needs to be triggered in the VerintDelegate method
  self.inviteDelegate = [[SurveyInviteManager alloc] init];
  [EXPPredictive setInviteDelegate:self.inviteDelegate];
}

- (void)didStartSDKWithError:(EXPErrorCode)error message:(NSString *)message {
  NSLog(@"Verint XM iOS SDK started with error: %@ (%tu)", message, error);
}

- (void)didFailToStartSDKWithError:(EXPErrorCode)error message:(NSString *)message {
  NSLog(@"Verint XM iOS SDK failed to start with error: %@ (%tu)", message, error);
}

@end
