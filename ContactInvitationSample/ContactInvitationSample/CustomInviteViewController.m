//
//  CustomInviteViewController.m
//  ContactInvitationSample
//
//  Created by Wayne Burkett on 8/30/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import "CustomInviteViewController.h"
#import "SettingsTableViewController.h"

@interface CustomInviteViewController ()

@property (weak, nonatomic) IBOutlet UIButton *inviteAcceptButton;
@property (weak, nonatomic) IBOutlet UIButton *inviteDeclineButton;
@property (nonatomic, getter=isShowing) BOOL showing;

@end

/** This class acts as the custom invitation handler. Any class that conforms to <FSInviteHandler> can manage
 this task. The invite's lifecycle is numerically documented below.
 
 **/
@implementation CustomInviteViewController

#pragma mark - UIViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // #0 The invite's buttons are hidden to start. They'll be displayed once we determine eligibility.
    self.inviteAcceptButton.alpha = 0;
    self.inviteDeclineButton.alpha = 0;

    // #1 We'll start by resetting the SDK's state, so that we can be sure we're eligible to see an invitation. (We'll copy and restore
    // any saved contact details, so that we still have those, even after a reset.)
    [self resetAndRestoreContactDetails];
    
    // #2 Set this class as the custom invite handler
    [ForeSee setInviteHandler:self];
    
    // #3 Check eligibility. If eligible (and we should be), the ForeSee SDK will call the invite handler's `show` method
    [ForeSee checkIfEligibleForSurvey];
}

- (void)dealloc {
    if (self.isShowing) {
        [ForeSee customInviteDeclined];
    }
}

#pragma mark - FSInviteHandler

// #4 The `show` method is triggered by the eligibility check. We'll show the invite's accept/decline buttons at this point.
- (void)show {
    NSLog(@"showing");
    [UIView animateWithDuration:0.5
                          delay:0
                        options:UIViewAnimationOptionCurveEaseIn
                     animations:^{
                         self.inviteAcceptButton.alpha = 1;
                         self.inviteDeclineButton.alpha = 1;
                     }
                     completion:^(BOOL finished) {
                         self.showing = YES;
                     }];
}

// #6b The SDK will call this method when the invitation's lifecycle is complete, because the invite was
// successfully accepted or declined. Either way, we're done!
- (void)hideWithAnimation:(BOOL)animate {
    NSLog(@"hiding");
    self.showing = NO;
    [self.navigationController popViewControllerAnimated:YES];
}

// #6a The SDK couldn't find contact details for the preferred contact type. The invite is neither accepted or declined.
- (void)setInvalidInput:(BOOL)isInvalid {
    NSLog(@"Invalid input");
    NSLog(@"Current stored email = %@", [ForeSee contactDetailsForType:kFSEmail]);
    NSLog(@"Current stored phone number = %@", [ForeSee contactDetailsForType:kFSPhoneNumber]);
}

#pragma mark - Invite actions

- (IBAction)handleAcceptButtonTouchUpInside:(id)sender {
    // #5a When the accept button is tapped we'll notify the ForeSee SDK that the invite was accepted. If the
    // input is good (i.e. if there is a value stored for the preferred contact type), then the invite's lifecycle is
    // complete and the SDK will invoke `hideWithAnimation:`. If the input is bad (i.e. there are no valid contact
    // details stored), then the SDK will notify us by calling `setInvalidInput:`.
    [ForeSee customInviteAccepted];
}

- (IBAction)handleDeclineButtonTouchUpInside:(id)sender {
    // #5b If the decline button is tapped, then we'll notify the ForeSee SDK that the invite was declined.
    [ForeSee customInviteDeclined];
}

#pragma mark - Reset

- (void)resetAndRestoreContactDetails {
    // A full state-reset also removes the stored contact details. We want to reset the tracker state
    // while keeping those details. This workaround achieves that. (None if this is necessary in real
    // implementations. You usually want to maintain state.)
    NSString *email = [ForeSee contactDetailsForType:kFSEmail];
    NSString *phoneNumber = [ForeSee contactDetailsForType:kFSPhoneNumber];
    if (self.isShowing) {
        // already showing from a previous load; let's reset and start over
        [ForeSee customInviteDeclined];
    }
    [ForeSee resetState];
    [ForeSee setPreferredContactType:[self preferredContactType]];
    [ForeSee setContactDetails:email forType:kFSEmail];
    [ForeSee setContactDetails:phoneNumber forType:kFSPhoneNumber];
}

- (FSContactType)preferredContactType {
    NSNumber *preferredType = [[NSUserDefaults standardUserDefaults] objectForKey:FSPreferredContactTypeKey];
    if (preferredType) {
        return [preferredType unsignedIntegerValue];
    }
    return kFSPhoneNumber;
}

@end
