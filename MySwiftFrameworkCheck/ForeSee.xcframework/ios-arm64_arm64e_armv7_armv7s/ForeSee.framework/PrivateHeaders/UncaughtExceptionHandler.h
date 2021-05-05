//
//  UncaughtExceptionHandler.h
//  Foresee
//
//  Created by Wayne Burkett on 5/24/17.
//  Copyright © 2017 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IngestionLogger/FSLogger.h>

extern NSString *const UncaughtExceptionHandlerSignalExceptionName;
extern NSString *const UncaughtExceptionHandlerSignalKey;

@interface UncaughtExceptionHandler : NSObject

+ (void)installExceptionHandlers;
- (void)handleException:(NSException *)exception;
- (void)handleException:(NSException *)exception eventType:(FSStatusMsg)type;

@end
