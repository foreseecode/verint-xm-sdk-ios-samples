//
//  UIViewController+SRViewChangeLogging.h
//  Foresee
//
//  Created by Michael Han on 2013-06-18.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

/**
 This category provides methods you can use if you want a view controller to opt out
 of automatic view logging. We split a recorded session by view controller to allow the
 session webplayer to conveniently divide the playback and as well to properly construct
 heatmaps.

 To properly use these methods, your view controller should adopt the <SRViewChangeDefinition>
 protocol.
 */
@interface UIViewController (SRViewChangeLogging)

/** @name Logging Helpers */
/** You can call this method to log a view change.

 Most times automatic view logging will be sufficient. But in some cases it may be preferable
 to manually handle the logging.

 @warning You must balance this method by messaging <logViewDidDisappear>
 */
- (void)logViewDidAppear;

/** Call this method when your view controller disappears from view.

 @warning Should not be messaged without previously messaging <logViewDidAppear>
 */
- (void)logViewDidDisappear;

@end
