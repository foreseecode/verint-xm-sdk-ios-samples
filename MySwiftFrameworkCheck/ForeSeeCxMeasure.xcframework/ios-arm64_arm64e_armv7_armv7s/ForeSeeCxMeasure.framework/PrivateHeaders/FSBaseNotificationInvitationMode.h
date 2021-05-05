//
//  FSBaseNotificationInvitationMode.h
//  Foresee
//
//  Created by Alcides Zelaya on 7/1/15.
//  Copyright (c) 2015 Foresee. All rights reserved.
//

#import <ForeSee/ForeSee.h>
#import <UserNotifications/UserNotifications.h>
#import "FSBaseInvitationMode.h"

API_AVAILABLE(ios(10))
@interface FSBaseNotificationInvitationMode : FSBaseInvitationMode

@property (nonatomic, strong) NSDate *nextTriggerDate; // iOS 10+

- (void)handleApplicationDidResign:(id)sender;
- (void)handleApplicationDidBecomeActive:(id)sender;

- (void)scheduleLocalNotificationWithIdentifier:(NSString *)identifier
                                        content:(UNMutableNotificationContent *)content
                                 secondsFromNow:(int)seconds;
- (void)cancelLocalNotificationWithIdentifier:(NSString *)identifier;
- (void)rescheduleLocalNotificationWithIdentifier:(NSString *)identifier;
- (void)registerUserToReceiveNotifications;

@end
