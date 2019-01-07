//
//  FSSettingsParser.h
//  ForeSee
//
//  Created by Wayne Burkett on 3/22/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const kFSPlaceholderValueWarningTemplate;
extern NSString * const kFSPlaceholderKeyWarningTemplate;
extern NSString * const kFSPlaceholderKeyWarningTemplate;
extern NSString * const kFSMissingKeyWarningTemplate;

@interface FSSettingsParser : NSObject

@property (nonatomic, retain) NSDictionary *JSONObject;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
- (void)setValueForKey:(NSString *)key;
- (void)setValueForKey:(NSString *)key configKey:(NSString *)configKey;
- (void)setValueForKey:(NSString *)key configKey:(NSString *)configKey fallback:(NSString *)fallback;
- (void)rejectValueForKey:(NSString *)key;
- (NSDictionary<NSString *, NSString *> *)placeholderDictionary;
- (NSArray<NSString *> *)requiredTopLevelKeys;
- (BOOL)hasPlaceholderValueForKey:(NSString *)key value:(NSString *)value;
- (BOOL)hasPlaceholderValueForKey:(NSString *)key value:(NSString *)value placeholderValue:(NSString *)placeholderValue;
- (BOOL)hasPlaceholderKey:(NSString *)key placeholderValue:(NSString *)placeholderValue;
- (BOOL)validate;

@end
