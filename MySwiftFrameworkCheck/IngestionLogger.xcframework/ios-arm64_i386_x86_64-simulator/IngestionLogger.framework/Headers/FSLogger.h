//
//  ForeSee Results iOS Trigger Code Framework
//
//  Created by ForeSee Results.
//  Copyright 2011 ForeSee Results. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FSHTTPClient;
@class FSIngestionEvent;
@class FSUserProfile;

typedef NS_ENUM(NSInteger, FSStatusMsg) {
  FSSDKStartedMsg = 1,
  FSSDKNotStartedMsg = 2,
  FSInviteShownMsg = 100,
  FSInviteAcceptedMsg = 101,
  FSInviteDeclinedMsg = 102,
  FSInviteDestroyed,
  FSEligibilityCheckRequested = 304,
  FSEligibilityMetCriteria = 305,
  FSEligibilityFailedCriteria = 306,
  FSEligibilityUserInSamplingPool = 307,
  FSEligibilityUserNotInSamplingPool = 308,
  FSEligibilityUserDoesNotHaveLocalNotificationPermission = 309,
  FSEligibilityUserRegisteredForLocalNotifications,
  FSEligibilityFailedNetworkError,
  FSInviteRequested = 110,
  FSInviteRequestedMeasureNotFound = 111,
  FSTrackerOpenedMsg = 200,
  FSTrackerClosedMsg = 201,
  FSTrackerError,
  FSTrackerReset,
  FSSurveyShownMsg = 400,
  FSSurveyRequestedMsg = 401,
  FSSurveyFailedToShow = 402,
  FSSurveyFailedToSubmit = 403,
  FSSurveyAbandonedMsg = 404,
  FSSurveyCompletedMsg = 405,
  FSSurveyNetworkRequestSubmittedMsg = 406,
  FSSurveyDestroyed,

  // feature logging
  FSSetInviteHandler,
  FSSetInviteDelegate,
  FSSetContactDetails,
  FSSetSkipPoolingCheck,
  FSForceShowInviteForSurveyID,
  FSForceShowSurveyForSurveyID,
  FSCustomInviteAccepted,
  FSCustomInviteDeclined,
  FSShowSurveyForLocalNotification,
  FSConfigUpdated,
  FSSetCustomNavigationBar,
  FSCustomCppSet,
  FSCustomCppSetFromArray,
  FSCustomCppAppended,
  FSInviteStyle,
  FSSurveyCustomStyle,
  FSContactTypeSelected,
  FSInvalidContactEntered,
  FSFeatures,
  FSExternalLinkClicked,
  
  // the numbers above are there for historical reasons, but we no longer
  // care what number is assigned to these
  FSUnhandledException,
  SRSessionStarted,
  SRSessionNotStarted,
  SRSessionDeleted,
  SRSessionEventsDeleted,
  SRSessionMovieDeleted,
  SRTempMovieDeleted,
  SRSessionSaved,
  SRSessionCompleted,
  SRSessionGroupCompleted,
  SRSessionTransmissionStarted,
  SRSessionTransmissionSuccess,
  SRSessionMovieTransmissionStarted,
  SRSessionMovieTransmissionSuccess,
  SRSessionMovieTransmissionFailed,
  SRSessionEventsTransmissionStarted,
  SRSessionEventsTransmissionSuccess,
  SRSessionEventsTransmissionFailed,
  SRSessionCrash,
  SRSessionIncomplete,
  SRRecordingStarted,
  SRRecordingEnded,
  SRBlacklistError,
  SRBlacklistedSDK,
  SRBlacklistedOS,
  SRStateTransition,
  
  // feature logging
  SRSetMaskingDebugEnabled,
  
  // FCP related
  FSStartWithCachedConfig,
  FSStartWithRemoteConfig,
  FSStartWithRemoteConfigFailure,
  
  // Debugging
  FSEventOverflow,
  
  // dummy event
  FSDummyEvent
};

// public events and event properties
extern NSString *const fs_reason;
extern NSString *const fs_networkErrorReason;
extern NSString *const fs_stackTrace;
extern NSString *const fs_sessionSize;
extern NSString *const fs_reclaimableSpace;
extern NSString *const fs_bytesTransmitted;
extern NSString *const fs_recordingUrl;
extern NSString *const fs_error;
extern NSString *const fs_currentSessionMaxLength;
extern NSString *const fs_currentSessionSize;
extern NSString *const fs_totalDiskSpaceBytes;
extern NSString *const fs_totalDiskSpaceBytesAvailable;
extern NSString *const fs_totalDiskSpaceBytesRequired;
extern NSString *const fs_totalDiskSpacePercentageAvailable;
extern NSString *const fs_totalDiskSpacePercentageRequired;
extern NSString *const fs_newState;
extern NSString *const fs_previousState;
extern NSString *const fs_customerId;
extern NSString *const fs_notificationType;
extern NSString *const fs_fileName;
extern NSString *const fs_configurationSource;
extern NSString *const fs_surveyId;
extern NSString *const fs_respondentId;
extern NSString *const fs_session_id;
extern NSString *const fs_cellTransmissionAllowance;
extern NSString *const fs_usedSpaceAllowance;
extern NSString *const fs_freeSpacePercentageMinimumAllowance;
extern NSString *const fs_customLogoPresent;
extern NSString *const fs_customColorPresent;
extern NSString *const fs_customBannerPresent;
extern NSString *const fs_mode;
extern NSString *const fs_contactTypeSelected;
extern NSString *const fs_invalidContactEntered;
extern NSString *const fs_sessionId;
extern NSString *const fs_duration;
extern NSString *const fs_privacyPolicyClicked;
extern NSString *const fs_smsDisclosureClicked;
extern NSString *const fs_hyperlinkClicked;
extern NSString *const fs_invalidJson;
extern NSString *const fs_unknownReason;
extern NSString *const fs_customSurveyHeaderColorPresent;
extern NSString *const fs_customSurveyButtonColorPresent;
extern NSString *const fs_customSurveyButtonBackgroundColorPresent;
extern NSString *const fs_measureCount;
extern NSString *const fs_eventOverflow;
extern NSString *const fs_eventCount;

extern const int kFSSecondsInADay;
extern const int kFSMaxEventRetryCount;

@interface FSLogger : NSObject

@property (nonatomic, strong) NSString *customerId;
@property (nonatomic, readonly) NSString *sessionId;
@property (nonatomic, strong) NSDictionary *userProfile;
@property (nonatomic, strong) NSDictionary *deviceProfile;

+ (instancetype)sharedInstance;
+ (void)setLoggingEnabled:(BOOL)isEnabled;
+ (BOOL)isLoggingEnabled;

- (FSIngestionEvent *)addEvent:(FSIngestionEvent *)event;
- (void)flush;
- (void)flush:(BOOL)immediate;
- (BOOL)hasEventWaitingOfSameTypeAs:(FSIngestionEvent *)event;

@end
