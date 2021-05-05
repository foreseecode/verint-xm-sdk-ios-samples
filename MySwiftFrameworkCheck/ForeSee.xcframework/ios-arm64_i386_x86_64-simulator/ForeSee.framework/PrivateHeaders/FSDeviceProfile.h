//
//  FSDeviceProfile.h
//  Foresee
//
//  Created by Wayne Burkett on 2/14/17.
//  Copyright © 2017 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ForeSeeUtilities/FSDictionary.h>

@class FSParameters;

@interface FSDeviceProfile : NSObject <FSDictionary>

- (instancetype)initWithDefaultParameters:(FSParameters *)cpps;

@end
