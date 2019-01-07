//
//  FSEnvironment.h
//  ForeSee
//
//  Created by Wayne Burkett on 5/29/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FSEnvironment : NSObject

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *ingestionEndpoint;
@property (nonatomic, readonly) NSString *ingestionPath;
@property (nonatomic, readonly) NSString *surveyEndpoint; // modern survey
@property (nonatomic, readonly) NSString *legacySurveyEndpoint;
@property (nonatomic, readonly) NSString *contactRegistrationEndpoint;
@property (nonatomic, readonly) NSString *surveyCheckEndpoint;

+ (instancetype)newEnvironment;
+ (instancetype)newEnvironmentForName:(NSString *)name;

@end
