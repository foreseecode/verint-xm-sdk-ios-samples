//
//  FSDelayedInvitationMode.h
//  TriggerTestApp
//
//  Created by Michael Han on 12-05-09.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ForeSeeCxMeasure/FSBaseInvitationMode.h>
#import "FSInviteViewDelegate.h"

@class FSContactInviteViewController;
@class FSHTTPClient;
@class FSParameters;

@interface FSDelayedInvitationMode : FSBaseInvitationMode <FSInviteViewDelegate> {
  FSHTTPClient *httpClient_;
  NSUInteger retries_;
}

@property (nonatomic, strong) FSHTTPClient *httpClient;
@property (nonatomic, assign) NSUInteger retries;

- (NSDictionary *)registrationParamsWithContactInfo:(NSString *)contactInfo
                                       respondentID:(NSString *)rid
                                           surveyID:(NSString *)sid
                                         customerID:(NSString *)cid
                                               cpps:(FSParameters *)cpps;
@end
