//
//  SRViewChangeDefinition.h
//  Foresee
//
//  Created by Michael Han on 2013-06-18.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Your UIViewController subclass can adopt this protocol to disable automatic view logging.

 When SessionReplay is enabled, it logs when view controllers appear in order to
 logically divide a recording. If you want to disable this behaviour for a given view controller,
 you must adopt this protocol.
 @see UIViewController(SRViewChangeLogging)
 */
@protocol SRViewChangeDefinition <NSObject>

@optional
/** @name View Change Behaviour */

/** Implement this method to control whether or not Session Replay records when this view
 controller appears.

 Implementation of this method is optional.

 @return YES if you want the default behaviour, NO if you want to disable.
 */
- (BOOL)isAutoViewChangeEnabled;


/** @name Custom Log Properties */

/** You can optionally provide a custom name when Session Replay logs view changes.

 The default name will be the class name.

 Implementation of this method is optional.

 @return The custom view name
 */
- (NSString *)sessionReplayViewName;

@end
