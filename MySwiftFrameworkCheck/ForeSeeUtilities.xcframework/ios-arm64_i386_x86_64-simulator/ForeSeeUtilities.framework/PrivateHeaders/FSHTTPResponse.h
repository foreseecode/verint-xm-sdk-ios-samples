//
//  FSHTTPResponse.h
//
//  Created by Michael Han on 2013-01-22.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FSHTTPResponse : NSObject

@property (nonatomic, strong) NSHTTPURLResponse *response;
@property (nonatomic, strong) NSData *data;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, assign) NSUInteger statusCode;
@property (nonatomic, readonly) BOOL isOK;
@property (nonatomic, readonly) BOOL isAccepted;
@property (nonatomic, readonly) BOOL isBadRequest;
@property (nonatomic, readonly) BOOL isNotFound;
@property (nonatomic, readonly) BOOL isError;
@property (nonatomic, readonly) BOOL isClientError;
@property (nonatomic, readonly) BOOL isServerError;
@property (nonatomic, readonly) BOOL isNetworkError;
@property (nonatomic, readonly) BOOL isNotModified;
@property (nonatomic, readonly) BOOL didFail;
@property (nonatomic, readonly) NSDictionary *jsonData;

- (id)initWithResponse:(NSURLResponse *)response data:(NSData *)data error:(NSError *)error;

@end
