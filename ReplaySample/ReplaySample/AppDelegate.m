//
//  AppDelegate.m
//  ReplaySample
//
//  Created by Selwyn Leeke on 2014-01-14.
//  Copyright (c) 2014 ForeSee. All rights reserved.
//

#import "AppDelegate.h"
#import "NativeViewController.h"
#import "WebViewController.h"
#import "SubmissionViewController.h"

@import ForeSeeReplay;

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
  // Override point for customization after application launch.
  self.window.backgroundColor = [UIColor whiteColor];
  
  // Set up view controllers
  NativeViewController *nativeViewController = [[NativeViewController alloc] initWithNibName:@"NativeViewController" bundle:nil];
  nativeViewController.title = @"Native";
  WebViewController *webViewController = [[WebViewController alloc] initWithNibName:@"WebViewController" bundle:nil];
  webViewController.title = @"Web View";
  SubmissionViewController *submissionViewController = [[SubmissionViewController alloc] initWithNibName:@"SubmissionViewController" bundle:nil];
  submissionViewController.title = @"Submission";
  
  // Set up tab bar controller
  UITabBarController *tabBarController = [[UITabBarController alloc] init];
  [tabBarController addChildViewController:nativeViewController];
  [tabBarController addChildViewController:webViewController];
  [tabBarController addChildViewController:submissionViewController];
  
  [self.window setRootViewController:tabBarController];
  
  // Start ForeSee SDK
  [ForeSeeReplay setDebugLogEnabled:YES];
  [ForeSeeReplay start];
  [ForeSeeReplay setMaskingDebugEnabled:YES];
  
  [self.window makeKeyAndVisible];
  return YES;
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
  // This call resets the state of the SDK so that the app will always load in a recording state. You should not normally use this in a production app
  [ForeSee resetState];  
}

@end
