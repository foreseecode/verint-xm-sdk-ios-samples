//
//  FSAcceptedTrackerState.h
//  TriggerTestApp
//
//  Created by Michael Han on 12-06-07.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSAbstractTrackerState.h"

/** The tracker will enter this state only for FSNotificationInvitationMode when
 the user accepts the invite.  We need a mode where by we can circumvent the invite from showing
 again when the user responds to the local notification.
 */
@interface FSAcceptedTrackerState : FSAbstractTrackerState {
  NSDate *acceptedDate_;
}

@property (nonatomic, strong) NSDate *acceptedDate;

@end
