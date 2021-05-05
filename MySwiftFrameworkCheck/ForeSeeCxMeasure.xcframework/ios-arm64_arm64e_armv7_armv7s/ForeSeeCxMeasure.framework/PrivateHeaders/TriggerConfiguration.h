//
//  TriggerConfiguration.h
//  CxMeasure
//
//  Created by Wayne Burkett on 8/17/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ForeSee/FSSettingsParser.h>

@class TRMeasure;
@class FSInviteConfiguration;
@class FSSurveyConfiguration;
@protocol FSInvitationMode;
@protocol FSInviteViewDelegate;

typedef NS_ENUM(NSInteger, FSTriggerInvitationMode) {
  FSTriggerInvitationModeInSession,
  FSTriggerInvitationModeContact,
  FSTriggerInvitationModeExitSurvey,
  FSTriggerInvitationModeExitInvite
};

@interface TriggerConfiguration : FSSettingsParser

@property (nonatomic, strong) NSMutableArray *measures;
@property (nonatomic, assign) FSTriggerInvitationMode invitationMode;
@property (nonatomic, strong) id<FSInvitationMode, FSInviteViewDelegate> invitationHandler;
@property (strong, nonatomic, readonly) FSInviteConfiguration *inviteConfig;
@property (strong, nonatomic, readonly) FSSurveyConfiguration *surveyConfig;
@property (strong, nonatomic, readonly) NSString *invitationModeName;
@property (nonatomic, assign, getter = isEmailOnlyContactNotification) BOOL emailOnlyContactNotification;

- (TRMeasure *)measureForSurveyID:(NSString *)surveyID;

@end
