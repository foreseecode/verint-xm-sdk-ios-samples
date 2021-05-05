//
//  ForeSee Results iOS Trigger Code Framework
//
//  Created by ForeSee Results.
//  Copyright 2011 ForeSee Results. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSParametersHandler.h"

@interface FSParameters : NSObject <NSSecureCoding, FSParametersHandler>

+ (NSString *)userAgentString;

- (void)removeAllValues;
- (NSString *)toQueryString;
- (NSDictionary<NSString *, NSString *> *)toDictionary;
- (void)loadDefaultCPPs;

@end
