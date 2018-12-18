//
//  FSStringFinder.h
//  ForeSee
//
//  Created by Wayne Burkett on 6/25/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FSStringFinder : NSObject

+ (instancetype)sharedInstance;
- (NSString *)stringForKey:(NSString *)key defaultValue:(NSString *)defaultValue;

@end
