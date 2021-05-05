//
//  ForeSee.h
//  Foresee
//
//  Created by Michael Han on 2013-02-21.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class FSUserProfile;
@class UNNotificationResponse;

/**
 * Error code for ForeSee SDK
 *
 * @since v6.0.0
 */
typedef NS_ENUM(NSUInteger, FSErrorCode) {
  kFSNetworkError,
  kFSClientError,
  kFSServerError,
  kFSConfigurationError,
  kFSUnknownError = -1009
};

/**
 Delegates registered with the ForeSee SDK may adopt the `ForeSeeDelegate` protocol to receive
 updates about SDK's lifecycle.
 
 */
@protocol ForeSeeDelegate <NSObject>

@optional

/** Tells the delegate when the SDK has been started. Implementation of this method is optional.
 */
- (void)didStartSDK;

/** Tells the delegate when the SDK has failed to start. Implementation of this method is optional.
 */
- (void)didFailToStartSDK:(FSErrorCode)error;

@end

/**
 The ForeSee class provides the main interface to the ForeSee SDK.
 
 To use the ForeSee framework, simply call `[ForeSee start];` in your `application:didFinishLaunchingWithOptions:`
 and it will automatically parse your configuration file and start the Trigger module. (Other start methods are available.
 See documentation.)
 
 #### Configuration
 Most configuration is done through the `foresee_configuration.json` file. See the documentation for all available
 configuration options.
 
 #### Debugging
 When testing your configuration, it is recommended you enable debug log mode. Useful information regarding internal
 state will be posted to the console for inspection.
 
 #### CPPs
 CPPs (Customer Passed Parameters) are key/value pairs that you can optionally attach to completed surveys.
 
 */
@interface ForeSee : NSObject

#pragma mark - Start-up

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

/** Starts the SDK using the given application identifier.
  
 @see start
 @param appId The application to start
 */
+ (void)startWithAppId:(NSString *)appId;

/** Starts the SDK using the given remote configuration details.
  
 @see start
 @param appId The application to start
 @param version The version of the application to start
 */
+ (void)startWithAppId:(NSString *)appId version:(NSString *)version;

/**
 * Registers an optional ForeSeeDelegate for the SDK
 */
+ (void)setDelegate:(id<ForeSeeDelegate>)delegate;

#pragma mark - A/B tests

/** Add an A/B test
  
 @param name a NSString represents the name of the test
 @param percentage a NSInteger value indicating the percentage for that test. The sum of all the test percentages must be 100.
 @since v6.0.0
 
 @return YES if the percentage value is between 0 and 100, NO otherwise
*/
+ (BOOL)addABTest:(NSString *)name percentage:(NSInteger)percentage;

#pragma mark - Debugging

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

/** Set remote configuration container
 
 When testing your remote configuration of the ForeSee SDK, it may be useful to
 try out your new configuration in a non-production container first. This method tells
 the SDK to look for the remote configuration in a specific container.
 By default the container name is "production"
 
 @param name a specific container name.
 */
+ (void)setConfigurationContainer:(NSString *)name;

/** Get remote configuration container
 
 @return a string indicating the current using configuration container name
 */
+ (NSString *)configurationContainer;

/** Set supported configuration locales and the default locale

 By default only "en" is supported

 @param locales a NSArray of supported configuration locales.
 @param defaultLocale the default locale.
*/
+ (void)setSupportedConfigurationLocales:(NSArray<NSString *> *)locales defaultLocale:(NSString *)defaultLocale;

/** Get the default supported configuration locale

 @return the default supported configuration locale.
*/
+ (NSString *)defaultConfigurationLocale;

/** Get the supported configuration locales

 @return a NSArray of supported configuration locales.
*/
+ (NSArray<NSString *> *)configurationLocales;

#pragma mark - Customer Passed Parameters

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

#pragma mark - User profile

/** Sets a user profile.
 
 The provided user profile is used to associate a specific user with events during logging.
 
 @param userProfile an FSUserProfile object
 */
+ (void)setUserProfile:(FSUserProfile *)userProfile;

@end

