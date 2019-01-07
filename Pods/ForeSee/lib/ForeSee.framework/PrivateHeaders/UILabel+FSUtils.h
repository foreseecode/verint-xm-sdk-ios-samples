//
//  UILabel+FSUtils.h
//  ForeSee
//
//  Created by Wayne Burkett on 4/27/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (FSUtils)

/**
 Resizes the label to fit its text using the given frame as a boundary rect
 
 @param frame A frame controlling the size of the rectangle to draw in
 */
- (void)setSizeForContentinFrame:(CGRect)frame;

@end
