//
//  FSMeasureSurveyViewController.h
//  ForeSeeCxMeasure
//
//  Created by Wayne Burkett on 8/31/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <ForeSee/ForeSee.h>
#import <ForeSee/FSSurveyViewController.h>

@class TRMeasure;

@interface FSMeasureSurveyViewController : FSSurveyViewController

@property (nonatomic, strong) TRMeasure *measure;

- (id)initWithSurveyURL:(NSURL *)surveyURL measure:(TRMeasure *)measure;

@end
