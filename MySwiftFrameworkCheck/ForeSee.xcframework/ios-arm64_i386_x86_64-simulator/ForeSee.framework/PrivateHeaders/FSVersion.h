//
//  FSVersion.h
//  Foresee
//
//  Created by Michael Han on 2013-05-08.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FSVersion : NSObject

@property (nonatomic, retain) NSNumber *major;
@property (nonatomic, retain) NSNumber *minor;
@property (nonatomic, retain) NSNumber *revision;

- (id)initWithVersionString:(NSString *)version;
- (BOOL)isEqualToVersion:(FSVersion *)version;
- (BOOL)isEarlierThanVersion:(FSVersion *)version;
- (BOOL)isLaterThanVersion:(FSVersion *)version;

@end
