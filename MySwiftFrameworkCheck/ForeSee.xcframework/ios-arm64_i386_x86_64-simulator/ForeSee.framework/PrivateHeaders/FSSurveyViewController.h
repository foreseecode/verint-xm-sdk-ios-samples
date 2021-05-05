//
//  ForeSee Results iOS Trigger Code Framework
//
//  Created by ForeSee Results.
//  Copyright 2011 ForeSee Results. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ForeSee/FSWKWebViewController.h>

@class FSSurvey;

@protocol Autoclosable <NSObject>

- (void)checkIfSurveyIsReadyToClose:(NSTimer *)timer;
- (BOOL)javascriptResponse:(id)response;
- (void)autoclose:(BOOL)success;
- (void)close;

@end

@interface FSSurveyViewController : FSWKWebViewController <Autoclosable>

- (instancetype)initWithSurvey:(FSSurvey *)survey;
- (instancetype)initWithSurveyURL:(NSURL *)surveyURL title:(NSString *)title;
- (BOOL)isThankYouPage;
- (BOOL)isErrorRedirect:(WKNavigationAction *)navigationAction;
- (NSError *)createErrorFromNavigationAction:(WKNavigationAction *)navigationAction;

@end
