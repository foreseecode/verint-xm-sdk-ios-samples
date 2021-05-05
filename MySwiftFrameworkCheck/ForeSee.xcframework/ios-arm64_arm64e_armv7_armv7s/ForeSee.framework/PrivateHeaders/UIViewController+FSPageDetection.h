//
//  UIViewController+FSPageDetection.h
//  Foresee
//
//  Created by Wayne Burkett on 1/25/17.
//  Copyright © 2017 Foresee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (FSPageDetection)

- (BOOL)isContainerController;
- (BOOL)shouldCountPageView;

@end
