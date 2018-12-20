//
//  FSInviteViewDelegate.h
//  PadTest
//
//  Created by Alexei White on 11-03-07.
//  Copyright 2011 ForeSee Results. All rights reserved.
//

@class FSInviteView;

@protocol FSInviteViewDelegate <NSObject>

/**
 Sent to the delegate when the user clicks on the OK button.  Should take this opportunity to show
 the survey.
 */
- (void)inviteViewClickedOKButton:(FSInviteView *)inviteView;

/**
 Sent to the delegate when the user clicks on the Cancel button.  Should take this opportunity to
 cancel survey tracking.
 */
- (void)inviteViewClickedCancelButton:(FSInviteView *)inviteView;

@optional

/**
 Sent to the delegate when the user performs some action after the invite is complete (or has been
 declined), but before it has been dismissed).
 
 For example, CONTACT invites display a "Thank You" page after they're complete. The invite is
 complete at that time.
 */
- (void)inviteCompletedPostInviteAction:(FSInviteView *)inviteView;


@optional

/**
 Sent to the delegate when the user clicks on a link on the survey.
 
 @param url the URL to load as an NSString
 @param keyForNavBarText optional strings key for the text to display in the navbar (note: does not apply for links opened in Safari)
 @param defaultNavBarText optional default text to display in the navbar if keyForNavBarText doesn't map to a valid string (note: does not apply for links opened in Safari)
 @param reason the string to use when logging the click event
 */
- (void)inviteViewClickedLink:(NSString *)url
             keyForNavBarText:(NSString *)keyForNavBarText
            defaultNavBarText:(NSString *)defaultNavBarText
                    logReason:(NSString *)reason;

@end
