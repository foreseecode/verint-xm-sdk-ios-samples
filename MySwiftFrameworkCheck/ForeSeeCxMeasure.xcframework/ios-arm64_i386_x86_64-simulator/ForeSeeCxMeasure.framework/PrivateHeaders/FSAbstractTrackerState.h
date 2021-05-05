//
//  FSAbstractTrackerState.h
//  TriggerTestApp
//
//  Created by Michael Han on 12-05-15.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FSTrackerState.h"
#import <ForeSee/FSConfiguration.h>
#import <ForeSeeUtilities/FSDebugger.h>

@class FSTracker;
@class FSParameters;

@interface FSAbstractTrackerState : NSObject <FSTrackerState, NSSecureCoding>

@property (nonatomic) FSTracker *trackerContext;
@property (nonatomic) FSParameters *cppParameters;
@property (nonatomic, copy) NSString *contactDetails;

- (id)initWithTrackerContext:(FSTracker *)tracker;

@end
