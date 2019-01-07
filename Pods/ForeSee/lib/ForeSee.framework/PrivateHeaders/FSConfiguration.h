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

@property (nonatomic, retain) NSString *customerID;
@property (nonatomic, assign) NSUInteger repeatDaysAfterDecline;
@property (nonatomic, assign) NSUInteger repeatDaysAfterAccept;
@property (nonatomic, assign) NSUInteger repeatDaysAfterComplete;
@property (nonatomic, retain) FSParameters *cppParameters;
@property (nonatomic, assign, getter = isSessionReplayEnabled) BOOL sessionReplayEnabled;
@property (nonatomic, assign) NSString *loadSource;
@property (nonatomic, retain) NSString *clientAppId;
@property (nonatomic, retain) NSString *sha256Hash;

- (BOOL)load:(NSError **)error;
- (BOOL)loadFromFile:(NSString *)path error:(NSError **)error;
- (BOOL)loadFromString:(NSString *)json error:(NSError **)error;
- (void)saveState;
- (void)resetState;

@end
