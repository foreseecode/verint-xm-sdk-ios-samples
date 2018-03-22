//
//  ForeSeeReplay.h
//  Foresee
//
//  Created by Wayne Burkett on 2/12/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ForeSee/ForeSee.h>

@class FSSession;

@interface ForeSee ()

@property (nonatomic, readonly) FSSession *session;

@end

/**
 The ForeSeeReplay class provides the main interface to the ForeSee Replay module. This module requires the
 primary ForeSee.framework.
*/
@interface ForeSeeReplay : ForeSee

#pragma mark -    

/** Checks whether Replay is running.
 
 @return YES if Replay is running, NO otherwise
 */
+ (BOOL)isRecording;

/** Manually adds a page break to the Replay session
 
 Calling this method will add a custom page change into the replay.
 This is not necessary in most cases as changes between UIViewControllers are detected automatically.
 
 @param pageName The name that will be displayed in the player when this page is displayed.
 */
+ (void)logReplayPageChange:(NSString *)pageName;

#pragma mark - Masking

// ##############################
/** @name Masking */
// ##############################

/**
#### Masking
When Replay is enabled, you can register views to mask using the <maskView:> method. Masked
views will be replaced by a black box in the recorded movie. By default, `UITextFields` that are marked
as secure fields will automatically be masked.
 */

/** Masks a view in a Replay recording
 
 You can use this method to mark a view as needing masking. Typically, this would
 be called from a view controller's `viewDidLoad` method
 @param view The view to mask
 @see unmaskView:
 */
+ (void)maskView:(UIView *)view;

/** Un-masks a view in a recording
 
 @param view The view to unmask
 @see maskView:
 */
+ (void)unmaskView:(UIView *)view;

/** Finds and masks all auto-maskable views contained within a view
 
 Auto-masking is carried out in the ViewWillAppear method of all UIViewControllers.
 This method is useful to fill any gaps where the views aren't available when the
 ViewWillAppear method is called, eg for cells in UITableViews.
 
 @param view The view to search within
 */
+ (void)autoMaskViewsWithinView:(UIView *)view;

/** Masks JavaScript alerts spawned from a web view in a recording
 
 You can use this method to mark a view as needing masking. Typically, this would
 be called from a view controller's `viewDidLoad` method
 
 @param webView The view to mask
 @see unmaskAlertsForWebView:
 */
+ (void)maskAlertsForWebView:(UIWebView *)webView;

/** Un-masks JavaScript alerts spawned from a web view in a recording
 
 @param webView The view to unmask
 @see maskAlertsForWebView:
 */
+ (void)unmaskAlertsForWebView:(UIWebView *)webView;

/** Retrieves all masked views
 */
+ (NSArray *)maskedViews;

#pragma mark - Debug

// ##############################
/** @name Debug */
// ##############################

/** Sets whether or not to enable masking debug for Replay
 
 Masking debug will draw translucent red areas on screen to indicate which views are masked and which are not.
 This must be called *after* the ForeSee SDK is started.
 By default, masking debug is *disabled*
 @param enabled YES to enable masking debug, NO to disable.
 */
+ (void)setMaskingDebugEnabled:(BOOL)enabled;

/** Returns whether or not masking debug is enabled
 
 @return YES if enabled, NO otherwise
 */
+ (BOOL)isMaskingDebugEnabled;


@end
