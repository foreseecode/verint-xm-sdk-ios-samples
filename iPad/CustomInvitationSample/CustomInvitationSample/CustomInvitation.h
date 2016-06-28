//
//  CustomInvitation.h
//  iPadExampleWithCustomInvitation
//
//  Copyright 2011 ForeSee Results. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CustomInvitationDelegate;

/**
 A custom invitation view that displays as a banner at the top of the screen.
 */
@interface CustomInvitation : UIView {
  id<CustomInvitationDelegate> delegate_;
}

@property (nonatomic, assign) id<CustomInvitationDelegate> delegate;

- (void)handleOkClick:(id)sender;
- (void)handleCancelClick:(id)sender;
- (void)handleRotation:(id)sender;
- (void)rotateWithAnimation:(BOOL)animate;

- (void)show;
- (void) hideWithAnimation:(BOOL)animate completion:(void (^)())completion;

@end

