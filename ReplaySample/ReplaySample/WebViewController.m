//
//  WebViewController.m
//  ReplaySample
//
//  Created by Selwyn Leeke on 2014-01-14.
//  Copyright (c) 2014 ForeSee. All rights reserved.
//

#import "WebViewController.h"

@import ForeSeeReplay;

@interface WebViewController ()

@end

@implementation WebViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
  self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
  return self;
}

- (void)viewDidLoad
{
  [super viewDidLoad];

  // WebViews are completely masked by default. To show the content, they must be unmasked.
  // This will leave all inpout fields masked - any further masking must be handled in masking_configuration.json
  [ForeSeeReplay unmaskView:self.webView];
  
  NSURL *url = [NSURL URLWithString:@"http://www.google.com"];
  [self.webView loadRequest:[NSURLRequest requestWithURL:url]];
}

- (void)didReceiveMemoryWarning
{
  [super didReceiveMemoryWarning];
}

@end
