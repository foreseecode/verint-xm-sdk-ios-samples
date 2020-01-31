//
//  FSViewController.m
//  BasicSample
//
//  Created by Michael Han on 12-03-06.
//  Copyright (c) 2012 ForeSee. All rights reserved.
//

#import "FSViewController.h"
#import <ForeSee/ForeSee.h>
#import "ACPCore.h"


@implementation FSViewController

# pragma mark - Actions

- (void)viewDidAppear:(BOOL)animated{
    NSLog(@"viewDidAppear loaded successfully");

}

- (void)checkEligibility:(id)sender {
    [ACPCore trackState:@"Home Screen" data:nil];

}

- (void)resetState:(id)sender {
    [ForeSee resetState];
}

@end
