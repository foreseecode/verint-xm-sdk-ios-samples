//
//  ViewController.m
//  ContactInvitationSample
//
//  Created by Wayne Burkett on 6/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "ViewController.h"
#import <QuartzCore/QuartzCore.h>
#import <ForeSee/ForeSee.h>

@interface ViewController ()

@property (strong, nonatomic) IBOutlet UITextField *contactTextField;
@property (strong, nonatomic) IBOutlet UIButton *resetButton;

@end

@implementation ViewController

#pragma mark - UIViewController

- (void)viewDidLoad {
    NSString *contactDetails = [ForeSee contactDetails];
    if (contactDetails != nil && ![@"" isEqualToString:[self trim:contactDetails]]) {
        self.contactTextField.text = contactDetails;
    }
    self.resetButton.layer.borderWidth = 1.0f;
    self.resetButton.layer.borderColor = [UIColor blackColor].CGColor;
}

#pragma mark - IBActions

- (IBAction)handleShowInviteTouchUpInside:(id)sender {
    [ForeSee setContactDetails:[self trim:self.contactTextField.text]];
    [ForeSee checkIfEligibleForSurvey];
}

- (IBAction)handleResetButtonTouchUpInside:(id)sender {
    [ForeSee resetState];
}

#pragma mark - Util

- (NSString *)trim:(NSString *)str {
    return [str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
}

@end
