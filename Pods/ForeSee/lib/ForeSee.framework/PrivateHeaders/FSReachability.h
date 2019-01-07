//
//  ForeSee Results iOS Trigger Code Framework
//
//  Created by ForeSee Results.
//  Copyright 2011 ForeSee Results. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

@class FSReachability;

#define kFSReachabilityChangedNotification @"kFSReachabilityChangedNotification"

typedef void(^FSReachabilityCallback)(FSReachability *reachability);

@interface FSReachability : NSObject

@property (nonatomic, retain) NSString *hostName;
@property (nonatomic, assign) SCNetworkReachabilityRef reachabilityRef;
@property (nonatomic, assign) SCNetworkReachabilityFlags reachabilityFlags;
@property (nonatomic, copy) FSReachabilityCallback onReachabilityChanged;
@property (nonatomic, copy) FSReachabilityCallback onInitialized;
@property (nonatomic, assign, getter = isInitialized) BOOL initialized;
@property (nonatomic, assign, getter = isReachable) BOOL reachable;
@property (nonatomic, assign, getter = isWWANOnly) BOOL WWANOnly;

+ (FSReachability *)reachabilityWithHostName:(NSString *)hostName;
- (id)initWithReachabilityRef:(SCNetworkReachabilityRef)reachabilityRef hostName:(NSString *)hostName;
- (void)updateStatus;

@end


