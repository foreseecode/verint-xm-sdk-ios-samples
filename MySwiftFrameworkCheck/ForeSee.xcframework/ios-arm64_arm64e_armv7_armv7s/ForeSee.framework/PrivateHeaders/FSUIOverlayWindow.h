//
//  FSUIOverlayWindow.h
//  Foresee
//
//  Created by Wayne Burkett on 12/5/17.
//  Copyright © 2017 Foresee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FSUIOverlayWindow : UIWindow

@property (nonatomic, getter=isModal) bool modal;

+ (UIWindowScene *)keyScene API_AVAILABLE(ios(13.0));

- (instancetype)initWithRootViewController:(UIViewController *)rootViewController;
- (instancetype)initWithRootViewController:(UIViewController *)rootViewController wrapWithNavigationController:(bool)wrap;

#pragma mark - Show/hide

- (void)showAndOnComplete:(void (^)(void))callback;
- (void)showAndOnComplete:(void (^)(void))callback animated:(BOOL)animated;
- (void)hideAndOnComplete:(void (^)(void))callback;
- (void)hideAndOnComplete:(void (^)(void))callback animated:(BOOL)animated;
  
@end
