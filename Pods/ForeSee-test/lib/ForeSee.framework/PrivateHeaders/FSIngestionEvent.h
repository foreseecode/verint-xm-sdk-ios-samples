//
//  FSEvent.h
//  Foresee
//
//  Created by Wayne Burkett on 2/14/17.
//  Copyright © 2017 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ForeSee/FSLogger.h>
#import <ForeSee/FSDictionary.h>

@interface FSIngestionEvent : NSObject <FSDictionary, NSCoding>

@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, readonly, getter=isOlderThanADay) BOOL expired;
@property (nonatomic, readonly, getter=hasExceededRetryLimit) BOOL maxedOut;

#pragma mark - Helpers

- (void)recordRetryAttempt;

#pragma mark - Event creation

+ (FSIngestionEvent *)createEvent:(FSStatusMsg)status;
+ (FSIngestionEvent *)createEvent:(FSStatusMsg)status withSurveyId:(NSString *)surveyId;
+ (FSIngestionEvent *)createEvent:(FSStatusMsg)status withSurveyId:(NSString *)surveyId respondentId:(NSString *)respondentId;

#pragma mark - Properties

- (FSIngestionEvent *)addPropertyForKey:(NSString *)key numberValue:(NSNumber *)value;
- (FSIngestionEvent *)addPropertyForKey:(NSString *)key stringValue:(NSString *)value;
- (FSIngestionEvent *)addPropertyForKey:(NSString *)key booleanValue:(bool)value;

#pragma mark - Data

- (FSIngestionEvent *)addDataForKey:(NSString *)key numberValue:(NSNumber *)value;
- (FSIngestionEvent *)addDataForKey:(NSString *)key stringValue:(NSString *)value;
- (FSIngestionEvent *)addDataForKey:(NSString *)key booleanValue:(bool)value;
- (FSIngestionEvent *)addDataFromDictionary:(NSDictionary *)dictionary;

#pragma mark - Metrics

- (FSIngestionEvent *)addMetricForKey:(NSString *)key numericValue:(NSNumber *)numericValue;
- (FSIngestionEvent *)addMetricsFromDictionary:(NSDictionary *)dictionary;

#pragma mark - Submit

- (void)send;

@end
