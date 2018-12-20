//
//  ForeSee Results iOS Trigger Code Framework
//
//  Created by ForeSee Results.
//  Copyright 2011 ForeSee Results. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ForeSee/FSContactDetails.h>

@protocol FSTrackerState;

@interface FSTrackerStorage : NSObject

@property (nonatomic, readonly) NSUserDefaults *storage;
@property (nonatomic, strong) FSContactDetails *contactDetails;

- (id<FSTrackerState>)state;
- (void)setState:(id<FSTrackerState>)state;
- (void)clear;
- (void)clearState;
- (void)clearUserData;
- (void)saveState:(BOOL)commit;
- (void)saveContactDetails:(BOOL)commit;
- (void)commit;

@end
