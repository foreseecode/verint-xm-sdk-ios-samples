//
//  ViewController.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "ViewController.h"
#import <ForeSee/ForeSee.h>
#import "CustomInviteTracker.h"
#import "CustomInviteTrackerSnackbar.h"
#import "CustomInviteTrackerContact.h"

@interface ViewController ()

@property (strong, nonatomic) IBOutlet NSLayoutConstraint *showInviteButton;
@property (nonatomic) id<FSInviteHandler> inviteHandler;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
