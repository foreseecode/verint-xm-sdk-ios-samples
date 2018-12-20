//
//  FSFileManager.h
//  SessionReplayApp
//
//  Created by Michael Han on 2012-08-22.
//  Copyright (c) 2012 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FSDiskInfo;

// tmp/com.foresee
NSString * FSTemporaryDirectory(void);

@interface FSFileManager : NSObject

+ (FSFileManager *)sharedManager;

- (void)setFileManager:(NSFileManager *)fileManager;
- (void)clearTemporaryData;
- (NSURL *)temporaryFile;
- (NSNumber *)percentageDiskspaceRemainingWithError:(NSError **)error;
- (NSNumber *)diskspaceRemainingWithError:(NSError **)error;
- (FSDiskInfo *)diskspaceInfoWithError:(NSError **)error;

@end
