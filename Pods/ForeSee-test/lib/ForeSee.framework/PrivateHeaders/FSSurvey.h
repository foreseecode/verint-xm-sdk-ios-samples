//
//  FSSurvey.h
//  ForeSee
//
//  Created by Wayne Burkett on 8/31/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FSSurvey : NSObject

@property (nonatomic, readonly) NSString *surveyId;
@property (nonatomic, readonly) NSString *respondentId;
@property (nonatomic, readonly) NSURL *url;

- (instancetype)initWithSurveyId:(NSString *)surveyId url:(NSURL *)url respondentId:(NSString *)respondentId;

@end
