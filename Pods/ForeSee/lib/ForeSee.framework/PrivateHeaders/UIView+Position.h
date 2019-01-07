//
//  UIView+Position.h
//  Foresee
//
//  Created by Wayne Burkett on 1/22/18.
//  Copyright © 2018 Foresee. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (Position)

/**
 Positions the view below another view with the given vertical spacing
 
 @param view the view under which to place the current view
 @param y the amount of vertical padding between the two views
 */
- (void)placeUnder:(UIView *)view withSpacing:(CGFloat)y;

/**
 Sets the width of the view
 
 @param width the new width
 */
- (void)setWidth:(CGFloat)width;

/**
 Sets the height of the view
 
 @param height the new height
 */
- (void)setHeight:(CGFloat)height;

/**
 Moves the view to the given point
 
 @param point the point to which the view should be moved
 */
- (void)moveTo:(CGPoint)point;

/**
 Centers the view vertically within the given view
 
 @param view the view in which to center the view
 */
- (void)moveToCenterOfView:(UIView *)view;

@end
