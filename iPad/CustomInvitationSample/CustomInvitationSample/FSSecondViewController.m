//
//  FSSecondViewController.m
//  CustomInvitationSample
//
//  Created by Michael Han on 12-03-05.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSSecondViewController.h"

@implementation FSSecondViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
    self.title = NSLocalizedString(@"Second", @"Second");
    self.tabBarItem.image = [UIImage imageNamed:@"second"];
    }
    return self;
}

@end
