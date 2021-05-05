//
//  FSDelayedInvitationMode.h
//  TriggerTestApp
//
//  Created by Michael Han on 12-05-09.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ForeSeeCxMeasure/FSBaseInvitationMode.h>

@class FSContactInviteViewController;
@class FSHTTPClient;
@class FSParameters;
@class FSRegistrationClient;

@interface FSDelayedInvitationMode : FSBaseInvitationMode

- (NSDictionary *)registrationParamsWithContactInfo:(NSString *)contactInfo
                                       respondentID:(NSString *)rid
                                           surveyID:(NSString *)sid
                                         customerID:(NSString *)cid
                                               cpps:(FSParameters *)cpps;
@end
