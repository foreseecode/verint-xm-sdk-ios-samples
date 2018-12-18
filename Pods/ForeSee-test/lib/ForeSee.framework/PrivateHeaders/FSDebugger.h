//
//  FSDebug.h
//  SessionReplay
//
//  Created by Michael Han on 2013-01-22.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const FSDebugLogNotification;
extern NSString *const FSDebugLogEntryKey;

// FSLog only prints if isLoggingEnabled returns YES
void FSLog(NSString *s, ...);
// FSDebug only prints if the DEBUG macro is defined. For internal use only.
void FSDebug(NSString *s, ...);
// FSWarn will always print to the console. Useful to notify implementor of
// unrecoverable failures
void FSWarn(NSString *s, ...);
// exposed only as a bridge to Swift (should not be used directly by client code)
void __FSLog(NSString *prefix, NSString *message, BOOL shouldNotify);

@interface FSDebugger : NSObject

+ (void)setLoggingEnabled:(BOOL)isEnabled;
+ (BOOL)isLoggingEnabled;

@end
