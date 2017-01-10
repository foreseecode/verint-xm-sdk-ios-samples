//
//  CustomInviteContactView.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/31/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "CustomInviteContactView.h"

@interface CustomInviteContactView ()

@property (nonatomic) UITextField *textField;

@end

@implementation CustomInviteContactView

- (instancetype)init {
    self = [super init];
    if (self) {
        [self createTextInput];
        self.bodyLabel.text = @"This example shows how to provide a user's contact information so they may be contacted later. This information may be provided even when showing the default ForeSee invite.";
    }
    return self;
}

- (void)createTextInput {
    self.textField = [[UITextField alloc] initWithFrame:CGRectMake(0,
                                                                    0,
                                                                    self.inviteView.frame.size.width,
                                                                    31)];
    self.textField.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    self.textField.borderStyle = UITextBorderStyleRoundedRect;
    self.textField.textColor = [UIColor colorWithWhite:0.65 alpha:1];
    self.textField.placeholder = @"email or mobile number";
    self.textField.keyboardType = UIKeyboardTypeEmailAddress;
    self.textField.returnKeyType = UIReturnKeyDone;
    self.textField.autocapitalizationType = UITextAutocapitalizationTypeNone;
    self.textField.autocorrectionType = UITextAutocorrectionTypeNo;
    self.textField.delegate = self;
    [self.inviteView addSubview:self.textField];
}

// override the parent's button layout to make room for the text input
- (void)layoutButtons {
    self.textField.frame = CGRectMake(0,
                                      self.bodyLabel.frame.origin.y + self.bodyLabel.frame.size.height + 10,
                                      self.headerImageView.frame.size.width - 20,
                                      30);
    self.textField.center = CGPointMake(self.headerImageView.center.x, self.textField.center.y);
    
    self.submitButton.frame = CGRectMake(0,
                                         self.textField.frame.origin.y + self.textField.frame.size.height + 10,
                                         self.headerImageView.frame.size.width / 2.0,
                                         30);
    self.submitButton.center = CGPointMake(self.headerImageView.center.x, self.submitButton.center.y);
    
    self.cancelButton.frame = CGRectMake(0,
                                         self.submitButton.frame.origin.y + self.submitButton.frame.size.height + 5,
                                         self.headerImageView.frame.size.width / 2.0,
                                         10);
    self.cancelButton.center = CGPointMake(self.headerImageView.center.x, self.cancelButton.center.y);
}

#pragma mark - UIView

- (void)layoutSubviews {
    [super layoutSubviews];
}

#pragma mark - UITextFieldDelegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return YES;
}

- (void)handleTextFieldTextDidChangeNotification:(NSNotification *)note {
}

@end
