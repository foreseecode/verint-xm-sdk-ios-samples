//
//  TextFieldTableViewCell.m
//  ContactInvitationSample
//
//  Created by Wayne Burkett on 8/30/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import "TextFieldTableViewCell.h"

@interface TextFieldTableViewCell ()

@end

@implementation TextFieldTableViewCell

- (void)awakeFromNib {
    [super awakeFromNib];
    
    self.textField = [self createTextField];
    [self addSubview:self.textField];
}

- (UITextField *)createTextField {
    UITextField *textField = [[UITextField alloc] initWithFrame:[self textFieldFrame]];
    textField.autocorrectionType = UITextAutocorrectionTypeNo;
    textField.autocapitalizationType = UITextAutocapitalizationTypeNone;
    textField.adjustsFontSizeToFitWidth = YES;
    textField.textColor = [UIColor blackColor];
    textField.returnKeyType = UIReturnKeyNext;
    return textField;
}

- (CGRect)textFieldFrame {
    CGRect newFrame = self.contentView.frame;
    newFrame.origin.x += 20;
    newFrame.size.width -= 20;
    return newFrame;
}

@end
