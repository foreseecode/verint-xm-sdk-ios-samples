//
//  FSParametersHandler.h
//  ForeSee
//
//  Created by Wayne Burkett on 12/6/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FSParameters;

NS_ASSUME_NONNULL_BEGIN

@protocol FSParametersHandler <NSObject>

- (void)addCPPValue:(NSString *)value forKey:(NSString *)key;
- (void)setCPPValue:(NSString *)value forKey:(NSString *)key;
- (void)setCPPValueFromArray:(NSArray<NSString *> *)value forKey:(NSString *)key;
- (void)appendCPPValue:(NSString *)value forKey:(NSString *)key;
- (NSString *)CPPValueForKey:(NSString *)key;
- (NSDictionary *)allCPPs;
- (void)removeAllValues;
- (void)removeCPPValueForKey:(NSString *)key;
- (void)setCPPValuesFromDictionary:(NSDictionary *)dict;
- (void)setCPPValuesFromParameters:(FSParameters *)parameters;

@end

NS_ASSUME_NONNULL_END
