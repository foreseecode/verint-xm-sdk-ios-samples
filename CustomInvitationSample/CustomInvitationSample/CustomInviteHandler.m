//
//  CustomInviteHandler.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "CustomInviteHandler.h"

@interface CustomInviteHandler ()

@property (nonatomic, assign) UIViewController *viewController;

@end

@implementation CustomInviteHandler

#pragma mark - init
- (id)initWithViewController:(UIViewController *)viewController {
    _viewController = viewController;
    return [super init];
}

#pragma mark - FSInviteHandler

- (void)show {
    UIAlertController* inviteAlert = [UIAlertController alertControllerWithTitle:@"Survey invitation"
                                                                         message:@"Would you like to take a survey?"
                                                                  preferredStyle:(UIAlertControllerStyle)UIAlertControllerStyleActionSheet];
    
    UIAlertAction* yayAction = [UIAlertAction actionWithTitle:@"Yay!"
                                                        style:UIAlertActionStyleDefault
                                                      handler:^(UIAlertAction * action) {
                                                          [ForeSee customInviteAccepted];
                                                      }];
    UIAlertAction* nayAction = [UIAlertAction actionWithTitle:@"Nay"
                                                        style:UIAlertActionStyleCancel
                                                      handler:^(UIAlertAction * action) {
                                                          [ForeSee customInviteDeclined];
                                                      }];
    
    [inviteAlert addAction:yayAction];
    [inviteAlert addAction:nayAction];
    [self.viewController presentViewController:inviteAlert animated:YES completion:nil];
}

- (void)hideWithAnimation:(BOOL)animate {
    // No-op
}


- (void)dealloc {
    [ForeSee customInviteDeclined];
}

@end
