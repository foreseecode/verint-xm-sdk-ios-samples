//
//  FSAppDelegate.h
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>

@class FSViewController;

@interface FSAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) FSViewController *viewController;

- (void)initializeForeSeeTrigger;

@end
