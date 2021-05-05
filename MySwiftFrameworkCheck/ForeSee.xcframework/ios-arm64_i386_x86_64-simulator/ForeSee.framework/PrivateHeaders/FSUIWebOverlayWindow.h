//
//  FSUIWebOverlayWindow.h
//  Foresee
//
//  Created by Wayne Burkett on 12/6/17.
//  Copyright © 2017 Foresee. All rights reserved.
//

#import <ForeSee/FSUIOverlayWindow.h>
#import "FSWebViewControllerDelegate.h"

@class FSWKWebViewController;

@interface FSUIWebOverlayWindow : FSUIOverlayWindow <FSWebViewControllerDelegate>

@property (nonatomic, assign) id<FSWebViewControllerDelegate> webViewControllerDelegate;

- (instancetype)initWithWebViewController:(FSWKWebViewController *)webViewController;
- (instancetype)initWithWebViewController:(FSWKWebViewController *)webViewController wrapWithNavigationController:(bool)wrap;

@end
