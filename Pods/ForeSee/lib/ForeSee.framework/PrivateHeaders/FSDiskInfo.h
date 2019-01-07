//
//  FSDiskInfo.h
//  Foresee
//
//  Created by Wayne Burkett on 4/10/15.
//  Copyright (c) 2015 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FSDiskInfo : NSObject

/**
 * @property bytesAvailable
 * @brief The number of bytes available on disk
 */
@property (nonatomic, strong) NSNumber *bytesAvailable;

/**
 * @property totalBytes
 * @brief The total disk size in bytes
 */
@property (nonatomic, strong) NSNumber *totalBytes;

/** 
 * @property percentageOfDiskRemaining
 * @brief The percentage of disk space remaining (a number between 0 and 1)
 */
@property (nonatomic, readonly) NSNumber *percentageOfDiskRemaining;

- (instancetype)initWithBytesAvailable:(NSNumber *)byteAvailable totalBytes:(NSNumber *)totalBytes;
- (BOOL)hasEnoughSpaceForThisManyBytes:(NSNumber *)bytes;

/**
Returns YES if the device has at least the specified percentage of disk space remaining; NO, otherwise
 
 @param percent a number between 0 and 1
 */
- (BOOL)hasThisPercentageOfDiskAvailable:(NSNumber *)percent;

@end
