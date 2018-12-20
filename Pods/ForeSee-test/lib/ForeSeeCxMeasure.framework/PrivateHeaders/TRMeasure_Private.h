//
//  TRMeasure_Private.h
//  Foresee
//
//  Created by Wayne Burkett on 3/27/17.
//  Copyright © 2017 Foresee. All rights reserved.
//

#import <ForeSee/TRMeasure.h>
#import <Foundation/Foundation.h>

@class FSActiveTrackerState;

typedef NS_ENUM(NSInteger, FSSurveyStyle) {
  FSSurveyStyleLegacy,
  FSSurveyStyleModern
};

@interface TRMeasure ()

#pragma mark - Init

- (id)initWithName:(NSString *)name;

- (id)initWithJSONDictionary:(NSDictionary *)JSONDictionary;

/** @name Initializing a measure */

/** Convenience method to create a new measure.
 @param surveyID The name of the survey associated with this measure. Your SRA can provide this for you.
 */
+ (TRMeasure *)measureWithSurveyID:(NSString *)surveyID;

/** @name Getting and Setting Properties */

#pragma mark - Accessors for primary criteria

@property (nonatomic, readonly) NSDictionary *significantEvents;
@property (nonatomic, readonly) NSUInteger launchCount;
@property (nonatomic, readonly) NSUInteger daysSinceFirstLaunch;
@property (nonatomic, readonly) NSUInteger daysSinceLastLaunch;
@property (nonatomic, readonly) NSUInteger pageViews;

#pragma mark - Direct access to the underlying criteria

@property (nonatomic) FSTriggerCriteria *primaryCriteria;
@property (nonatomic) NSArray<FSTriggerCriteria *> *combinedCriteria;

#pragma mark - Style

@property (nonatomic, readonly) BOOL isModernSurvey;

#pragma mark - Threshold tests

- (BOOL)hasMetThreshold:(FSActiveTrackerState *)trackerState;

@end
