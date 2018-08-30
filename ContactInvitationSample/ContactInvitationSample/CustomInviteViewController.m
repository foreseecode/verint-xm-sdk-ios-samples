//
//  CustomInviteViewController.m
//  ContactInvitationSample
//
//  Created by Wayne Burkett on 8/30/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import "CustomInviteViewController.h"

@interface CustomInviteViewController ()

@property (weak, nonatomic) IBOutlet UIButton *inviteAcceptButton;
@property (weak, nonatomic) IBOutlet UIButton *inviteDeclineButton;

@end

@implementation CustomInviteViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.inviteAcceptButton.hidden = YES;
    self.inviteDeclineButton.hidden = YES;

    [ForeSee setInviteHandler:self];
    [ForeSee checkIfEligibleForSurvey];
}

- (IBAction)handleAcceptButtonTouchUpInside:(id)sender {
    [ForeSee customInviteAccepted];
}

- (IBAction)handleDeclineButtonTouchUpInside:(id)sender {
    [ForeSee customInviteDeclined];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

#pragma mark - FSInviteHandler

- (void)show {
    NSLog(@"showing");
    
    self.inviteAcceptButton.hidden = NO;
    self.inviteDeclineButton.hidden = NO;
}

- (void)hideWithAnimation:(BOOL)animate {
    NSLog(@"hiding");
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)setInvalidInput:(BOOL)isInvalid {
    NSLog(@"Invalid input");
}

@end
