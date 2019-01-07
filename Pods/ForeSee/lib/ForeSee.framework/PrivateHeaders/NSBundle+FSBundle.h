//
//  NSBundle+FSBundle.h
//  Foresee
//
//  Created by Wayne Burkett on 1/28/15.
//  Copyright (c) 2015 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSBundle (FSBundle)

- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)tableName fallbackKey:(NSString *)fallbackKey;
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value fallbackKey:(NSString *)fallbackKey;
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value fallbackKeys:(NSArray<NSString *> *)fallbackKeys;

@end
