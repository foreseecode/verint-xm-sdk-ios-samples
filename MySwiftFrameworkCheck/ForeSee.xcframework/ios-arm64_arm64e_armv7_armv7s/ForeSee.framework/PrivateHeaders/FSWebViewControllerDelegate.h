//
//  ForeSee Results iOS Trigger Code Framework
//
//  Created by ForeSee Results.
//  Copyright 2011 ForeSee Results. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FSWKWebViewController;

@protocol FSWebViewControllerDelegate <NSObject>

- (void)didAbandonViewController:(FSWKWebViewController *)viewController;
- (void)didCompleteViewController:(FSWKWebViewController *)viewController;
- (void)didFailToLoad:(FSWKWebViewController *)viewController;
- (void)didLoad:(FSWKWebViewController *)viewController;
- (void)didFailToCompleteTask:(FSWKWebViewController *)viewController;
- (void)didCompleteTask:(FSWKWebViewController *)viewController;

@end
