//
//  InviteExampleViewController.h
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 6/1/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ForeSee/ForeSee.h>
#import <ForeSee/FSInviteHandler.h>

@interface InviteExampleViewController : UIViewController

@property (strong, nonatomic) IBOutlet UITextView *textView;
@property (nonatomic) id<FSInviteHandler> inviteHandler;

@end
