//
//  FSCompletedTrackerState.h
//  TriggerTestApp
//
//  Created by Michael Han on 12-05-15.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSAbstractTrackerState.h"

@interface FSCompletedTrackerState : FSAbstractTrackerState {
  NSDate *completedDate_;
}

@property (nonatomic, strong) NSDate *completedDate;

@end
