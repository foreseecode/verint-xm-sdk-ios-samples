//
//  InviteExampleViewController.h
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 6/1/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <EXPCore/EXPCore.h>
#import <EXPPredictive/EXPInviteHandler.h>

@interface InviteExampleViewController : UIViewController

@property (strong, nonatomic) IBOutlet UITextView *textView;
@property (nonatomic) id<EXPInviteHandler> inviteHandler;

@end
