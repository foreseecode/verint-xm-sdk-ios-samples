//
//  UIDevice+FSUtilities.h
//  Utilities
//
//  Created by Michael Han on 2013-04-08.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIDevice (FSUtilities)

- (BOOL)fs_isTablet;
- (BOOL)fs_isTabletUI;
- (CGSize)fs_physicalScreenSize;
- (NSString *)fs_modelName;
+ (BOOL)fs_isSystemVersionLessThan:(float)versionNumber;

+ (float)systemVersion;
+ (BOOL)isUsingiOS8CoordinateSystem;

@end
