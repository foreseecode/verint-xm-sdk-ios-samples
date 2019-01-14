//
//  FSWKWebViewController.h
//  Foresee
//
//  Created by Wayne Burkett on 12/5/17.
//  Copyright © 2017 Foresee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@protocol FSWebViewControllerDelegate;

@interface FSWKWebViewController : UIViewController <WKUIDelegate, WKNavigationDelegate>

@property (nonatomic, copy) NSURL *url;
@property (nonatomic, retain) WKWebView *webView;
@property (nonatomic, readonly) UIActivityIndicatorView *activityIndicator;
@property (nonatomic, assign) BOOL didPageFailToLoad;
@property (nonatomic, assign) id<FSWebViewControllerDelegate> delegate;
@property (nonatomic, retain) UINavigationBar *navigationBar;
@property (nonatomic, retain) NSError *lastError;

- (id)initWithURL:(NSURL *)url title:(NSString *)title;
- (void)showError:(NSError *)error autoclose:(bool)autoclose;
- (void)adjustScrollViewInsetsForNavigationBar:(UINavigationBar *)navigationBar;

@end
