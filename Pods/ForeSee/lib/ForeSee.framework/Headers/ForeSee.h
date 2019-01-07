//
//  ForeSee.h
//  Foresee
//
//  Created by Michael Han on 2013-02-21.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol FSInviteHandler;
@protocol FSInviteDelegate;

@class TRMeasure;
@class FSUserProfile;
@class UNNotificationResponse;

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
extern NSString *const kFSSDKVersion;
extern NSString *const FSLocalNotificationMeasureKey;

/**
 The ForeSee class provides the main interface to the ForeSee SDK. You must add a `foresee_configuration.json` file to your
 project that defines the behavior of the Trigger module (e.g. defines the triggering criteria for
 inviting a user to participate in a survey).
 
 To use the ForeSee framework, simply call `[ForeSee start];` in your `application:didFinishLaunchingWithOptions:`
 and it will automatically parse your configuration file and start the Trigger module.
 
 (Alternatively, use `+ (void)startWithConfigurationFile:(NSString *)configFileName` to specify a custom configuration
 file name (e.g. to include a configuration for both debug and release builds).)
 
 While integrating the ForeSee framework into your app, it is suggested you enable debug logging. This will output
 useful log messages to the console.
 
 #### Configuration
 Most configuration is done through the `foresee_configuration.json` file. Behavior such as trigger criteria,
 invitation modes, repeat days, are done through the configuration file. If you want to customize runtime behavior
 e.g. displaying custom invitations, you can provide a delegate with the setInviteDelegate: method.
 
 #### Debugging
 When testing your configuration, it is recommended you enable debug log mode. Useful information regarding internal
 state will be posted to the console for inspection.
 
 #### Notifications
 The ForeSee SDK will post a number of notifications to the default `NSNotificationCenter`:
 
 - `FSInviteDidShowNotification` ( Posted when the default invitation was displayed. )
 - `FSInviteWasDeclinedNotification` ( Posted when the default invitation was declined. )
 - `FSInviteWasAcceptedNotification` ( Posted when the default invitation was accepted. )
 - `FSSurveyWasCompletedNotification` ( Posted when the survey was completed. )
 - `FSSurveyWasAbandonedNotification` ( Posted when the survey was abandoned. )
 - `FSSurveyDidShowNotification` ( Posted when the survey was presented. )
 
 #### CPPs
 CPPs (Customer Passed Parameters) are key/value pairs that you can optionally attach to a completed
 survey.
 
 */
@interface ForeSee : NSObject

#pragma mark - Start-up

// ************************
/** @name Start-up */
// ************************

/** Starts the SDK.
 
 Behavior of the module is defined in the `foresee_configuration.json` file.
 
 */
+ (void)start;

/** Starts the SDK using a custom configuration file.
 
 Behavior of the module is defined in the named configuration file in your project.
 
 @see start
 @param configFileName The name of the configuration file to use when loading modules
 */
+ (void)startWithConfigurationFile:(NSString *)configFileName;

/** Starts the SDK using custom configuration JSON.
 
 Behavior of the module is defined by the string provided.
 
 @see start
 @param json The configuration JSON to use when loading modules
 */
+ (void)startWithConfigurationJson:(NSString *)json;

#pragma mark - Debug

// ##############################
/** @name Debug */
// ##############################

/** Gets the version of the SDK */
+ (NSString *)version;

/** Sets whether or not to enable debug logging
 
 Debug logging will print useful state information to the console for inspection.
 By default, debug logging is *disabled*
 @param enabled YES to enable debug logging, NO to disable.
 */
+ (void)setDebugLogEnabled:(BOOL)enabled;

/** Returns whether or not debug logging is enabled
 
 @return YES if enabled, NO otherwise
 */
+ (BOOL)isDebugLogEnabled;

/** Sets whether or not to enable remote event logging
 
 Event logging captures and transmits significant events that occur
 during the SDK life cycle. By default, event logging is *enabled* and
 it is highly recommended that this logging remain enabled in release
 builds.
 @param enabled YES to enable event logging, NO to disable.
 */
+ (void)setEventLogEnabled:(BOOL)enabled;

/** Returns whether or not event logging is enabled
 
 @return YES if enabled, NO otherwise
 */
+ (BOOL)isEventLogEnabled;

/** Erases all stored counts and state in the SDK; resets the SDK state to be active
 and recording. This should only be used for
 specific debugging or testing purposes; it should not be used in production code.
 */
+ (void)resetState;

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

#pragma mark - Trigger delegate

// ##############################
/** @name Trigger Delegate */
// ##############################

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

#pragma mark - Customer Passed Parameters

// ##############################
/** @name CPP (Customer Passed Parameters) */
// ##############################

/** Adds a CPP to be sent to the server along with a completed survey
 
 CPPs are unique to their provided key. If you add a value for an
 existing key, the old value will simply be overwritten.
 
 @deprecated v4.2.0
 @param value The value to transmit
 @param key The key identifying the value
 @see setCPPValue:forKey:
 @see removeCPPValueForKey:
 */
+ (void)addCPPValue:(NSString *)value forKey:(NSString *)key __attribute__((deprecated("first deprecated in ForeSee SDK 4.2.0 - Use -setCPPValue:forKey:")));

/** Adds a CPP to be sent to the server along with a completed survey
 
 CPPs are unique to their provided key. If you set a value for an
 existing key, the old value will simply be overwritten.
 
 @param value The value to transmit
 @param key The key identifying the value
 @see removeCPPValueForKey:
 */
+ (void)setCPPValue:(NSString *)value forKey:(NSString *)key;

/** Adds a list of CPP values to be sent to the server along with a completed 
 survey. The values will be sent as a comma-separated list.
 
 CPPs are unique to their provided key. If you set a value for an
 existing key, the old value will simply be overwritten.
 
 @param value The values to transmit
 @param key The key identifying the values
 @see setCPPValue:forKey:
 @see removeCPPValueForKey:
 */
+ (void)setCPPValueFromArray:(NSArray<NSString *> *)value forKey:(NSString *)key;

/** Adds a CPP value to the end of the list of values for the given key. If no such 
 list exists, then it will be created. If the key already contains a non-array value,
 then that value will be destroyed and a new list will be created.
 
 The values in the resulting array will be sent as a comma-separated list.
 
 @param value The value to add
 @param key The key identifying the values
 @see setCPPValue:forKey:
 @see removeCPPValueForKey:
 */
+ (void)appendCPPValue:(NSString *)value forKey:(NSString *)key;

/** Retrieves the CPP value associated with the given key (or nil, if no
 such key exists)
 
 @param key The key to look for
 @return the CPP's value, if one exists; nil, if it doesn't
 */
+ (NSString *)CPPValueForKey:(NSString *)key;

/** Retrieves a dictionary containing all existing CPPs, where the keys
 are each CPP's key and the values are each CPP's value as a string. If the
 key is assoicated with a list of values, then the value for that key will
 be a comma-separated list (exactly as they're stored on the backend).
 
 @return a dictionary containing all existing CPPs
 */
+ (NSDictionary *)allCPPs;

/** Remove a CPP
 @param key The key of the value to remove.
 @see setCPPValue:forKey:
 */
+ (void)removeCPPValueForKey:(NSString *)key;

#pragma mark - Significant events

// ##############################
/** @name Significant Events */
// ##############################

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

// ##############################
/** @name Page Views */
// ##############################

/** Increments the view controller load count ("page views"). This is done automatically
 for most view controllers.
 */
+ (void)incrementPageViews;

#pragma mark - Manual control

// ##############################
/** @name Manual Control */
// ##############################

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

// ##############################
/** @name Local Notification */
// ##############################

/** If using the local notification invite mode, you can use this method
 to obtain the surveyID of the measure that triggered the invite.
 
 As well as returning the surveyID, this method will also cancel the
 notification and remove it from Notification Center.
 
 @deprecated v5.1.0
 @param note The local notification that was presented to the user.
 @return The surveyID of the measure that triggered the invitation. You can use
 the surveyID to display the survey by calling <showSurveyForSurveyID:>
 */
+ (NSString *)surveyIDForLocalNotification:(UILocalNotification *)note __attribute__((deprecated("first deprecated in ForeSee SDK 5.1.0 - Use the UNUserNotificationCenter and -surveyIdForNotificationResponse:")));

/** Shows the survey associated with a local notification.
 
 This method will also cancel the notification and remove it from Notification Center.
 
 @deprecated v5.1.0
 @param note The local notification that was presented to the user.
 */
+ (void)showSurveyForLocalNotification:(UILocalNotification *)note __attribute__((deprecated("first deprecated in ForeSee SDK 5.1.0 - Use the UNUserNotificationCenter and -showSurveyForNotificationResponse:")));

/** Returns the surveyId for the notification that triggered an invite.
 
 Also, cancels the pending notification.
 
 @param response The notification that was sent to the user.
 @return The surveyID of the measure that triggered the invitation.
 **/
+ (NSString *)surveyIdForNotificationResponse:(UNNotificationResponse *)response;

/** Shows the survey associated with a notification.
 
 Also, cancels the pending notification.
 
 @param response The notification that was presented to the user.
 */
+ (void)showSurveyForNotificationResponse:(UNNotificationResponse *)response;

#pragma mark - Contact details

// ##############################
/** @name Contact Details */
// ##############################

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

/** Sets a user's contact details.
 
 This method can be used to provide a user's contact information, so that they
 do not need to enter it manually. When provided, the default invite will skip
 the user input screen. Only applies to CONTACT surveys.
 
 Warning: this method clears any previously-set values for any contact type. Use
 the typed contact details methods to support contact details with associated
 types.
 
 @deprecated v5.1.0
 @param contactDetails The customer's phone number or email address.
 */
+ (void)setContactDetails:(NSString *)contactDetails __attribute__((deprecated("first deprecated in ForeSee SDK 5.1.0 - Use -setContactDetails:forType:")));

/** Retrieves a user's contact details.
 *
 * @deprecated v5.1.0
 */
+ (NSString *)contactDetails __attribute__((deprecated("first deprecated in ForeSee SDK 5.1.0 - Use -contactDetailsforType:")));

#pragma mark - Custom invites

// ##############################
/** @name Custom invites */
// ##############################

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

/** Tells the SDK that a custom invite was accepted and provides a user's contact details
 
 You should call this method whenever a user accepts a custom invite that
 you've presented and you want to provide information the SDK can use to contact
 the user later.
 
 @param contactDetails The customer's phone number or email address.
 */
+ (void)customInviteAcceptedWithContactDetails:(NSString *)contactDetails;

#pragma mark - User profile

// ##############################
/** @name User profile */
// ##############################

/** Sets a user profile.
 
 The provided user profile is used to associate a specific user with events during logging.
 
 @param userProfile an FSUserProfile object
 */
+ (void)setUserProfile:(FSUserProfile *)userProfile;

@end

