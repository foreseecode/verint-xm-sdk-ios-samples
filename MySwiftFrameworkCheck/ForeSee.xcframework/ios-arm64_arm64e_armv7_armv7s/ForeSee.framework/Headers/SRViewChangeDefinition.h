//
//  SRViewChangeDefinition.h
//  Foresee
//
//  Created by Michael Han on 2013-06-18.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Your UIViewController subclass can adopt this protocol to disable automatic view logging and counting.

 Most of time, the appearance of a UIViewController on screen is counted as a "page view" by the SDK. Some container
 controllers, however, are not counted (e.g. UINavigationController). You may have your own custom controllers
 that you don't wish to be counted (or containers that you think should be). This protocol enables an override 
 of the default behavior.
 */
@protocol SRViewChangeDefinition <NSObject>

@optional

/** @name Page View Behaviour */

/** Returns whether the SDK should count the appearance of this controller as a "page view"
 
 @return YES if you want to count the current controller, otherwise NO
 */
@property (NS_NONATOMIC_IOSONLY, readonly) BOOL shouldCountPageViews;


// TODO: these two were removed when Replay was retired. I'm adding them back so that Replay builds, but ultimately
// this class should be split in two, so that Replay-only stuff is separate from non-Replay stuff
@property (NS_NONATOMIC_IOSONLY, readonly) BOOL isAutoViewChangeEnabled;
@property (NS_NONATOMIC_IOSONLY, readonly) NSString *sessionReplayViewName;

@end
