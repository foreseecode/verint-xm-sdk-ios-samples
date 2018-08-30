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

typedef enum TableSections : NSUInteger {
    kFSEmailSection = 0,
    kFSPhoneNumberSection,
    kFSSectionCount
} TableSections;

@interface SettingsTableViewController ()

@end

@implementation SettingsTableViewController

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return kFSSectionCount;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    switch (section) {
        case kFSEmailSection:
            return @"E-mail";
        case kFSPhoneNumberSection:
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
        case kFSEmailSection:
            cell.textField.tag = kFSEmailSection;
            cell.textField.placeholder = @"example@foresee.com";
            cell.textField.keyboardType = UIKeyboardTypeEmailAddress;
            cell.textField.text = [ForeSee contactDetailsForType:kFSEmail];
            break;
        case kFSPhoneNumberSection:
            cell.textField.tag = kFSPhoneNumberSection;
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
    [ForeSee setContactDetails:[self trim:textField.text] forType:(textField.tag == kFSEmailSection) ? kFSEmail : kFSPhoneNumber];
    [self.tableView reloadData];
}

#pragma mark - Util

- (NSString *)trim:(NSString *)str {
    return [str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
}

@end
