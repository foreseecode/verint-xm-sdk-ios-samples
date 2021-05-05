//
//  FSProfileKeys.h
//  IngestionLogger
//
//  Created by Burkett, Wayne on 9/15/20.
//  Copyright © 2020 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const fs_timezone;
extern NSString *const fs_type;
extern NSString *const fs_os;
extern NSString *const fs_osVersion;
extern NSString *const fs_browserName;
extern NSString *const fs_browserVersion;
extern NSString *const fs_fingerprint;
extern NSString *const fs_productType;
extern NSString *const fs_sdkVersion;
extern NSString *const fs_clientVersion;
extern NSString *const fs_clientBuildNumber;
extern NSString *const fs_screenWidth;
extern NSString *const fs_screenHeight;
extern NSString *const fs_brandName;
extern NSString *const fs_dualOrientation;
extern NSString *const fs_isTablet;
extern NSString *const fs_language;
extern NSString *const fs_locale;
extern NSString *const fs_pointingMethod;
extern NSString *const fs_resolutionWidth;
extern NSString *const fs_resolutionHeight;
extern NSString *const fs_modelName;
extern NSString *const fs_modelVersion;

extern NSString *const fs_email;
extern NSString *const fs_phone;
extern NSString *const fs_facebook;
extern NSString *const fs_twitter;
extern NSString *const fs_identity;

@interface FSProfileKeys : NSObject

- (void)setUserProfile:(NSDictionary *)values;
- (void)setDeviceProfile:(NSDictionary *)values;

@end

NS_ASSUME_NONNULL_END
