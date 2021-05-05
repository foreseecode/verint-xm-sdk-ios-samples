//
//  CxMeasure.h
//  CxMeasure
//
//  Created by Wayne Burkett on 8/16/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol FSInviteHandler;
@protocol FSInviteDelegate;

//! Project version number for ForeSeeCxMeasure.
FOUNDATION_EXPORT double ForeSeeCxMeasureVersionNumber;

//! Project version string for ForeSeeCxMeasure.
FOUNDATION_EXPORT const unsigned char ForeSeeCxMeasureVersionString[];

/** @notification ForeSee Posted when the invite was presented to the user.
 */
extern NSString *const FSInviteDidShowNotification;

/** @notification ForeSee Posted when the user declines the invite.
 */
extern NSString *const FSInviteWasDeclinedNotification;

/** @notification ForeSee Posted when the user accepts the invite.
 */
extern NSString *const FSInviteWasAcceptedNotification;

/** @notification ForeSee Posted when the user completes a survey.
 */
extern NSString *const FSSurveyWasCompletedNotification;

/** @notification ForeSee Posted if the user abandons the survey before submitting it.
 */
extern NSString *const FSSurveyWasAbandonedNotification;

/** @notification ForeSee Posted when the survey is presented to the user.
 The survey only presents to the user if you have configured
 your implementation with the IN_SESSION invitation mode in your
 `foresee_configuration.json` file.
 */
extern NSString *const FSSurveyDidShowNotification;
extern NSString *const FSTriggerSurveyIDKey;
extern NSString *const FSLocalNotificationMeasureKey;

/**
The ForeSeeCxMeasure class provides the main interface to the ForeSee CxMeasure module. You must add a
`foresee_configuration.json` file to your project that defines the behavior of the Trigger module (e.g. defines the
triggering criteria for inviting a user to participate in a survey).

#### Configuration
Most configuration is done through the `foresee_configuration.json` file. Behavior such as trigger criteria,
invitation modes, repeat days, are done through the configuration file. If you want to customize runtime behavior
e.g. displaying custom invitations, you can provide a delegate with the setInviteDelegate: method.

#### Debugging
When testing your configuration, it is recommended you enable debug log mode. Useful information regarding internal
state will be posted to the console for inspection.

#### Notifications
The CxMeasure module will post a number of notifications to the default `NSNotificationCenter`:

- `FSInviteDidShowNotification` ( Posted when the default invitation was displayed. )
- `FSInviteWasDeclinedNotification` ( Posted when the default invitation was declined. )
- `FSInviteWasAcceptedNotification` ( Posted when the default invitation was accepted. )
- `FSSurveyWasCompletedNotification` ( Posted when the survey was completed. )
- `FSSurveyWasAbandonedNotification` ( Posted when the survey was abandoned. )
- `FSSurveyDidShowNotification` ( Posted when the survey was presented. )
*/
@interface ForeSeeCxMeasure : NSObject

#pragma mark - Trigger delegate

/** Sets an invite lifecycle delegate
 
 Objects conforming to the <FSInviteDelegate> protocol and registered with the SDK using this method
 will be notified of events in the SDK's lifecycle
 
 @param delegate An object conforming to the <FSInviteDelegate> protocol
 */
+ (void)setInviteDelegate:(id<FSInviteDelegate>)delegate;

/** Sets a custom invite handler
 
 Use an object conforming to the <FSInviteHandler> protocol to display a custom invite. Objects will be
 told when to show and hide custom views, based on the user's state.
 
 @param inviteHandler An object conforming to the <FSInviteHandler> protocol
 */
+ (void)setInviteHandler:(id<FSInviteHandler>)inviteHandler;

#pragma mark - Significant events

/** Increments the event count for a given key
 
 Significant events are defined in the foresee_configuration.json file.
 
 @param key The key of the event
 */
+ (void)incrementSignificantEventCountWithKey:(NSString *)key;

/**
 *  Increments the event count for a given key and checks eligibity after
 *
 *  @param key The key of the event
 */
+ (void)incrementSignificantEventCountAndCheckEligibilityWithKey:(NSString *)key;

#pragma mark - Page views

/** Increments the view controller load count ("page views"). This is done automatically
 for most view controllers.
 */
+ (void)incrementPageViews;

#pragma mark - Manual control

/** Force a survey to display for a given surveyID
 
 Calling this method will display a survey regardless of the user's
 current eligibility.
 @param surveyID The ID of the survey you wish to display.
 */
+ (void)showSurveyForSurveyID:(NSString *)surveyID;

/** Force a invite to display for a given surveyID
 
 Calling this method will display an invite regardless of the user's
 current eligibility.
 @param surveyID The ID of the survey you wish to invite the user to take.
 */
+ (void)showInviteForSurveyID:(NSString *)surveyID;

/** Checks to see if the user is currently eligible to be invited to a survey.
 
 In order to be eligible, a number of conditions must be fulfilled:
 
 1. The library is in an enabled state. If the user has previously declined an invite
 or completed a survey, the library will be in a disabled state. Otherwise, the library is
 in an enabled state.
 2. The user has met the loyalty threshold defined in your foresee_configuration.json file.
 3. The user is in the sampling pool. If the previous two conditions have been met, the library
 makes an HTTP call to our servers to determine if the user is in the sampling pool. If s/he is,
 the invite will be presented. If not, the invite will not be shown. Disable this remote check with
 <setSkipPoolingCheck:>
 */
+ (void)checkIfEligibleForSurvey;

#pragma mark - Local notification

/** Returns the surveyId for the notification that triggered an invite.
 
 Also, cancels the pending notification.
 
 @param response The notification that was sent to the user.
 @return The surveyID of the measure that triggered the invitation.
 **/
+ (NSString *)surveyIdForNotificationResponse:(UNNotificationResponse *)response API_AVAILABLE(ios(10));

/** Shows the survey associated with a notification.
 
 Also, cancels the pending notification.
 
 @param response The notification that was presented to the user.
 */
+ (void)showSurveyForNotificationResponse:(UNNotificationResponse *)response API_AVAILABLE(ios(10));

#pragma mark - Contact details

/**
 * Valid contact types for CONTACT invites
 *
 * @since v5.1.0
 */
typedef NS_ENUM(NSUInteger, FSContactType) {
  kFSEmail,
  kFSPhoneNumber,
  kFSUnknown = 999
};

/** Retrieves a user's contact details for the given contact type.
 
 This method can be used to provide a user's contact information, so that they
 do not need to enter it manually. When provided, the default invite will
 auto-populate the contact input field for CONTACT surveys.
 
 @since v5.1.0
 @param type an FSContactType
 */
+ (NSString *)contactDetailsForType:(FSContactType)type;

/** Sets a user's contact details.
 
 This method can be used to provide a user's contact information, so that they
 do not need to enter it manually. When provided, the default CONTACT invite will
 auto-populate the provided details for the user. Only valid for CONTACT surveys.
 
 @since v5.1.0
 @param contactDetails The customer's contact information (e.g. a phone number or email address)
 @param type an FSContactType that specifies the type of information prodvided in contactDetails
 */
+ (void)setContactDetails:(NSString *)contactDetails forType:(FSContactType)type;

/** Sets a preferred contact details type.
 
 @param type the preferred FSContactType
 */
+ (void)setPreferredContactType:(FSContactType)type;

/** Gets the preferred contact details type.
 */
+ (FSContactType)preferredContactType;

/** Retrieves all user contact details for every type.
 
 @since v5.1.0
 @return an NSDictionary where the keys are NSNumbers containing the FSContactType and the values
 are the actual contact details for that type
 */
+ (NSDictionary<NSNumber *, NSString *> *)allContactDetails;

/** Clears any and all previously-set user data
 
 @since v5.1.0
 */
+ (void)clearUserData;

#pragma mark - Custom invites

/** Tells the SDK that a custom invite was accepted.
 
 You should call this method whenever a user accepts a custom invite that
 you've presented.
 
 */
+ (void)customInviteAccepted;

/** Tells the SDK that a custom invite was declined.
 
 You should call this method whenever a user declines a custom invite that
 you've presented.
 
 */
+ (void)customInviteDeclined;

#pragma mark - Pooling check

/** Disables the pooling check.
 
 When debugging your implementation of the ForeSee SDK, it may be useful to
 disable the pooling check. This ensures that the invite will always show if
 the loyalty criteria has been fulfilled.
 
 @param shouldSkip YES to skip the pooling check.
 */
+ (void)setSkipPoolingCheck:(BOOL)shouldSkip;

/** Get pooling check setting
 
 @return YES if pooling check is skipped, NO otherwise
 */
+ (BOOL)shouldSkipPoolingCheck;

@end
