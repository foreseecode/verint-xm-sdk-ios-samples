//
//  FSUIToolbarButtonItemsFactory.h
//  Foresee
//
//  Created by Wayne Burkett on 12/6/17.
//  Copyright © 2017 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

@class FSWKWebViewController;

@interface FSUIBarButtonItemsContainer : NSObject

@property (nonatomic, retain) UIBarButtonItem *backButton;
@property (nonatomic, retain) UIBarButtonItem *forwardButton;
@property (nonatomic, retain) UIActivityIndicatorView *activityIndicatorView;
@property (nonatomic, readonly) NSArray<UIBarButtonItem *> *toolbarItems;

- (instancetype)initWithWebViewController:(FSWKWebViewController *)webViewController;

@end
