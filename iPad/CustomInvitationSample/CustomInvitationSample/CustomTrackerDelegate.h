//
//  CustomTrackerDelegate.h
//  iPadExampleWithCustomInvitation
//
//  Created by Michael Han on 12-03-01.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import <ForeSee/ForeSee.h>
#import "CustomInvitation.h"
#import "CustomInvitationDelegate.h"

/**
 A custom delegate that is notified by the trigger API of tracking events.  Creating your
 own custom delegate is the best way to use a custom invite as well, as seen in this example
 app.
 */
@interface CustomTrackerDelegate : NSObject<FSInviteDelegate, CustomInvitationDelegate>

@property (nonatomic, retain) CustomInvitation *invite;
@property (nonatomic, retain) NSString *currentSurveyID;

@end
