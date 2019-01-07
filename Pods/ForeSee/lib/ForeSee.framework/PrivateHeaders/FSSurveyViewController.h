//
//  ForeSee Results iOS Trigger Code Framework
//
//  Created by ForeSee Results.
//  Copyright 2011 ForeSee Results. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ForeSee/FSWKWebViewController.h>
#import "FSSurvey.h"

@protocol Autoclosable <NSObject>

- (void)checkIfSurveyIsReadyToClose:(NSTimer *)timer;
- (BOOL)javascriptResponse:(id)response indicatesCompletedSurveyForTimer:(NSTimer *)timer;
- (void)autoclose:(BOOL)success;
- (void)close;

@end

@interface FSSurveyViewController : FSWKWebViewController <Autoclosable>

- (instancetype)initWithSurvey:(FSSurvey *)survey;
- (instancetype)initWithSurveyURL:(NSURL *)surveyURL title:(NSString *)title;
- (BOOL)isThankYouPage;

@end
