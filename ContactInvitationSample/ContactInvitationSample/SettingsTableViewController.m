//
//  SettingsTableViewController.m
//  ContactInvitationSample
//
//  Created by Wayne Burkett on 8/30/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import "SettingsTableViewController.h"
#import "TextFieldTableViewCell.h"
#import <ForeSee/ForeSee.h>

typedef enum TextFieldRows : NSUInteger {
    kFSEmailRow = 0,
    kFSPhoneNumberRow,
    kFSTextFieldRowCount
} StyleTypes;

@interface SettingsTableViewController ()

@end

@implementation SettingsTableViewController

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return kFSTextFieldRowCount;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    switch (section) {
        case kFSEmailRow:
            return @"E-mail";
        case kFSPhoneNumberRow:
            return @"Phone Number";
    }
    return @"";
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 1;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    TextFieldTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"SettingsCell"];
    switch (indexPath.section) {
        case kFSEmailRow:
            cell.textField.tag = kFSEmailRow;
            cell.textField.placeholder = @"example@foresee.com";
            cell.textField.keyboardType = UIKeyboardTypeEmailAddress;
            cell.textField.text = [ForeSee contactDetailsForType:kFSEmail];
            break;
        case kFSPhoneNumberRow:
            cell.textField.tag = kFSPhoneNumberRow;
            cell.textField.placeholder = @"555-555-5555";
            cell.textField.keyboardType = UIKeyboardTypePhonePad;
            cell.textField.text = [ForeSee contactDetailsForType:kFSPhoneNumber];
            break;
        default:
            break;
    }
    cell.textField.delegate = self;
    return cell;
}

#pragma mark - UITextFieldDelegate

- (void)textFieldDidEndEditing:(UITextField *)textField {
    [ForeSee setContactDetails:[self trim:textField.text] forType:(textField.tag == kFSEmailRow) ? kFSEmail : kFSPhoneNumber];
    [self.tableView reloadData];
}

#pragma mark - Util

- (NSString *)trim:(NSString *)str {
    return [str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
}

@end
