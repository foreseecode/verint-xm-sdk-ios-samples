//
//  SubmissionViewController.m
//  ReplaySample
//
//  Created by Selwyn Leeke on 2014-01-14.
//  Copyright (c) 2014 ForeSee. All rights reserved.
//

#import "SubmissionViewController.h"
#import <ForeSee/ForeSee.h>

@interface SubmissionViewController ()

@end

@implementation SubmissionViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
  self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
  return self;
}

- (void)viewDidLoad
{
  [super viewDidLoad];
}

- (void)didReceiveMemoryWarning
{
  [super didReceiveMemoryWarning];
}

- (IBAction)displayInvite:(id)sender {
  // Check if the user is eligible for a survey. Because the counters are reset on each launch,
  // and the launch count is set to 0 in the configuration, this will always launch an invitation
  [ForeSee checkIfEligibleForSurvey];
}

@end
