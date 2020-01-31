//
//  FSAppDelegate.m
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSAppDelegate.h"
#import <ForeSee/ForeSee.h>
#import "ACPCore.h"
#import "ForeSeeAdobeExtension/ForeSeeAdobeExtension.h"
#import "ACPIdentity.h"
#import "ACPLifecycle.h"
#import "ACPSignal.h"
#import "ACPUserProfile.h"

@implementation FSAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  [self initializeForeSeeAdobeExtension];
  return YES;
}

- (void)initializeForeSeeAdobeExtension {
  [ACPCore setLogLevel:ACPMobileLogLevelDebug];
  [ACPCore configureWithAppId:@"launch-your-appID"];
  
  [ForeSeeAdobeExtension registerExtension];
  [ACPIdentity registerExtension];
  [ACPLifecycle registerExtension];
  [ACPSignal registerExtension];
  [ACPUserProfile registerExtension];
  [ACPCore start:^{
      [ACPCore lifecycleStart:nil];
  }];
}

@end
