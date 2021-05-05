//
//  FSFcpManager.h
//  ForeSee
//
//  Created by Alan Wang on 2020-03-25.
//  Copyright © 2020 ForeSee. All rights reserved.
//

#ifndef FSFcpManager_h
#define FSFcpManager_h

#import <Foundation/Foundation.h>
#import "FSABTests.h"

@class FSHTTPResponse;
@class FSABTests;

@interface FSFcpManager : NSObject

@property (nonatomic, assign, setter = setABTest:) FSABTests *abTests;

- (instancetype)initWithAppId:(NSString *)clientId version:(NSString *)version;

- (void)fetchConfigInContainer:(NSString *)container languageId:(NSString *)languageId completion:(void (^)(NSString *jsonString, FSHTTPResponse *response))completion;

- (NSString *)languageIdForLanguage:(NSString *)language region:(NSString *)region;

@end

#endif /* FSFcpManager_h */
