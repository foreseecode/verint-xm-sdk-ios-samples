//
//  FSHTTPResponse.h
//  SessionReplay
//
//  Created by Michael Han on 2013-01-22.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FSHTTPResponse : NSObject

@property (nonatomic, retain) NSHTTPURLResponse *response;
@property (nonatomic, retain) NSData *data;
@property (nonatomic, retain) NSError *error;
@property (nonatomic, assign) NSUInteger statusCode;
@property (nonatomic, readonly) BOOL isOK;
@property (nonatomic, readonly) BOOL isAccepted;
@property (nonatomic, readonly) BOOL isBadRequest;
@property (nonatomic, readonly) BOOL isNotFound;
@property (nonatomic, readonly) BOOL isError;
@property (nonatomic, readonly) BOOL isClientError;
@property (nonatomic, readonly) BOOL isServerError;
@property (nonatomic, readonly) BOOL isNetworkError;
@property (nonatomic, readonly) BOOL didFail;
@property (nonatomic, readonly) NSDictionary *jsonData;

- (id)initWithResponse:(NSURLResponse *)response data:(NSData *)data error:(NSError *)error;

@end
