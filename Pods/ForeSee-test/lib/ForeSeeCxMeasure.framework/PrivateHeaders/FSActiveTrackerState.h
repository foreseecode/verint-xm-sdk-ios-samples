//
//  FSActiveTrackerState.h
//  TriggerTestApp
//
//  Created by Michael Han on 12-05-15.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSAbstractTrackerState.h"

@class TRMeasure;
@class FSReachability;
@class FSHTTPClient;

@interface FSActiveTrackerState : FSAbstractTrackerState 

@property (nonatomic, strong) FSHTTPClient *httpClient;
@property (nonatomic, strong) NSOperationQueue *queue;
@property (nonatomic, assign) NSUInteger launchCount;
@property (nonatomic, assign) NSUInteger pageViews;
@property (nonatomic, strong) NSDate *firstLaunchDate;
@property (nonatomic, strong) NSDate *lastLaunchDate;
@property (nonatomic, strong) NSMutableDictionary *significantEvents;

- (BOOL)hasMeasureMetThreshold:(TRMeasure *)measure;
- (void)checkSamplingPool:(TRMeasure *)measure callback:(void (^)(BOOL isInSamplingPool))callback;
- (NSDictionary *)stateDictionary;

@end
