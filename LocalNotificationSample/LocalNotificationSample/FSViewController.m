//
//  FSViewController.m
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSViewController.h"
#import <ForeSee/ForeSee.h>
#import <ForeSeeCxMeasure/ForeSeeCxMeasure.h>
#import <UserNotifications/UserNotifications.h>


@implementation FSViewController

# pragma mark - Actions

- (IBAction)checkEligibility:(id)sender {
    [self registerNotificationService];
    [ForeSeeCxMeasure checkIfEligibleForSurvey];
}

- (IBAction)resetState:(id)sender {
    [ForeSee resetState];

}

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
