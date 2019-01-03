//
//  FSAppDelegate.m
//  InternationalizationSample
//
//  Created by Michael Han on 12-03-05.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSAppDelegate.h"
#import <ForeSee/ForeSee.h>

@implementation FSAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  [self initializeForeSeeTrigger];
  return YES;
}

- (void)initializeForeSeeTrigger {
  [ForeSee setDebugLogEnabled:YES];
  [ForeSee setSkipPoolingCheck:YES];
  [ForeSee start];
  [ForeSee checkIfEligibleForSurvey];
}

@end
