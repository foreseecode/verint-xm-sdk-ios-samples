//
//  FSFirstViewController.m
//  CustomInvitationSample
//
//  Created by Michael Han on 12-03-05.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSFirstViewController.h"

@implementation FSFirstViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
  self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
  if (self) {
    self.title = NSLocalizedString(@"First", @"First");
    self.tabBarItem.image = [UIImage imageNamed:@"first"];
  }
  return self;
}

@end
