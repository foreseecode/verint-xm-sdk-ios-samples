//
//  FSTriggerCriteria_Private.h
//  Foresee
//
//  Created by Wayne Burkett on 3/28/17.
//  Copyright © 2017 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ForeSee/FSTriggerCriteria.h>

@interface FSTriggerCriteria ()

- (instancetype)initWithDictionary:(NSDictionary *)dict;
- (BOOL)hasMetAny:(FSActiveTrackerState *)trackerState;
- (BOOL)hasMetAll:(FSActiveTrackerState *)trackerState;

@end
