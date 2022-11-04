//
//  FSAppDelegate.m
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSAppDelegate.h"
#import <EXPCore/EXPCore.h>
#import <EXPPredictive/EXPPredictive.h>

@implementation FSAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  [self initializeForeSeeTrigger];
  return YES;
}

- (void)initializeForeSeeTrigger {
  [EXPCore setDebugLogEnabled:YES];
  [EXPCore start];
  [EXPPredictive setSkipPoolingCheck:YES];
  [EXPCore resetState];
}

@end
