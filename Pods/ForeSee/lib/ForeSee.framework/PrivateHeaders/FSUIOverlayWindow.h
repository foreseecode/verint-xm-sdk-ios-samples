//
//  FSUIOverlayWindow.h
//  Foresee
//
//  Created by Wayne Burkett on 12/5/17.
//  Copyright © 2017 Foresee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FSUIOverlayWindow : UIWindow

- (instancetype)initWithRootViewController:(UIViewController *)rootViewController;
- (void)showAndOnComplete:(void (^)(void))callback;
- (void)hideAndOnComplete:(void (^)(void))callback;
  
@end
