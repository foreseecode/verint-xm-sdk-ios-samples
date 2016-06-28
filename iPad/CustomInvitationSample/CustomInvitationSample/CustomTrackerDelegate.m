//
//  CustomTrackerDelegate.m
//  iPadExampleWithCustomInvitation
//
//  Created by Michael Han on 12-03-01.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "CustomTrackerDelegate.h"
#import <ForeSee/FSInviteResultDelegate.h>

@interface CustomTrackerDelegate ()

@property (nonatomic, assign) id<FSInviteResultDelegate> tracker;

@end

@implementation CustomTrackerDelegate

- (void)dealloc {
  self.invite.delegate = nil;
  self.invite = nil;
  [super dealloc];
}

#pragma mark - FSInviteDelegate

- (BOOL)tracker:(id<FSInviteResultDelegate>)tracker willShowInviteForSurvey:(NSString *)surveyId {

  UIWindow *window = [[[UIApplication sharedApplication] windows] objectAtIndex:0];
  CGRect windowRect = window.frame;
  
  if (!self.invite) {
    self.invite = [[[CustomInvitation alloc] initWithFrame:CGRectMake(0, 63, windowRect.size.width, 80)] autorelease];
    self.invite.delegate = self;
    [self.invite show];
    self.currentSurveyID = surveyId;
    self.tracker = tracker;
  }
  return NO;
}

#pragma mark - CustomInvitationDelegate

- (void)inviteViewClickedCancelButton:(CustomInvitation *)inviteView {
  [inviteView hideWithAnimation:YES completion:^{
    self.invite = nil;
    [self.tracker didDeclineInviteForSurvey:self.currentSurveyID];
  }];
}

- (void)inviteViewClickedOKButton:(CustomInvitation *)inviteView {
  [inviteView hideWithAnimation:YES completion:^{
    self.invite = nil;
    [self.tracker didAcceptInviteForSurvey:self.currentSurveyID];
  }];
  [ForeSee showSurveyForSurveyID:self.currentSurveyID];
}

@end
