//
//  FSAppDelegate.m
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSAppDelegate.h"
#import <ForeSee/ForeSee.h>
#import <ForeSeeCxMeasure/ForeSeeCxMeasure.h>

@implementation FSAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  [self initializeForeSeeTrigger];
  return YES;
}

- (void)initializeForeSeeTrigger {
  [ForeSee setDebugLogEnabled:YES];
  [ForeSee start];
  [ForeSeeCxMeasure setSkipPoolingCheck:YES];
  [ForeSee resetState];
}

@end
