//
//  FSConfiguration.h
//  TriggerTestApp
//
//  Created by Selwyn Leeke on 2012-11-27.
//
//

#import <Foundation/Foundation.h>
#import "FSSettingsParser.h"
#import "FSParametersHandler.h"

@class FSParameters;

extern NSUInteger const FSIgnoreCriteria;

typedef NS_ENUM(NSInteger, FSConfigurationError) {
  FSConfigurationErrorNone,
  FSConfigurationErrorMalformedJSON,
  FSConfigurationErrorFileNotFound,
  FSConfigurationErrorFileReadError,
  FSConfigurationErrorNoClientID  
};

@interface FSConfiguration : FSSettingsParser <FSParametersHandler>

@property (nonatomic, strong) NSString *customerID;
@property (nonatomic, assign) NSUInteger repeatDaysAfterDecline;
@property (nonatomic, assign) NSUInteger repeatDaysAfterAccept;
@property (nonatomic, assign) NSUInteger repeatDaysAfterComplete;
@property (nonatomic, strong) FSParameters *cppParameters;
@property (nonatomic, assign) NSString *loadSource;
@property (nonatomic, strong) NSString *clientAppId;
@property (nonatomic, strong) NSString *sha256Hash;
@property (nonatomic, assign, getter = shouldSupportLandscape) BOOL supportLandscape;
@property (nonatomic, assign, getter = isSessionReplayEnabled) BOOL sessionReplayEnabled;

- (BOOL)load:(NSError **)error;
- (BOOL)loadFromFile:(NSString *)path error:(NSError **)error;
- (BOOL)loadFromString:(NSString *)json error:(NSError **)error;
- (void)saveState;
- (void)resetState;

@end
