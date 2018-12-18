//
//  FSHTTPClient.h
//  SessionReplayApp
//
//  Created by Michael Han on 2012-08-21.
//  Copyright (c) 2012 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FSHTTPRequest;
@class FSHTTPResponse;
@class FSMultipartData;

NSString * FSPercentEscapedQueryStringPairMemberFromStringWithEncoding(NSString *string, NSStringEncoding encoding);
NSString * FSQueryStringFromDictionary(NSDictionary *params);

@interface FSHTTPClient : NSObject

@property (nonatomic, retain) NSURL *baseURL;

- (id)initWithBaseURL:(NSURL *)url;

- (FSHTTPRequest *)requestWithMethod:(NSString *)method path:(NSString *)path parameters:(id)parameters completion:(void(^)(FSHTTPResponse *response))callback;
- (FSHTTPRequest *)multipartFormRequestWithMethod:(NSString *)method path:(NSString *)path parameters:(id)parameters constructBodyWithBlock:(void(^)(FSMultipartData *multipartData))block completion:(void(^)(FSHTTPResponse *response))callback;

- (void)enqueueRequest:(NSMutableURLRequest *)request completion:(void(^)(FSHTTPResponse *response))callback;
- (void)batchEnqueueRequests:(NSArray *)requests completion:(void(^)(void))callback;

// Async
- (void)postPath:(NSString *)path parameters:(id)parameters completion:(void(^)(FSHTTPResponse *response))callback;
- (void)getPath:(NSString *)path parameters:(id)parameters completion:(void(^)(FSHTTPResponse *response))callback;
- (void)getPath:(NSString *)path parameters:(id)parameters ignoreCache:(BOOL)ignoreCache completion:(void(^)(FSHTTPResponse *response))callback;

- (void)addValue:(NSString *)value forHTTPHeader:(NSString *)header;

@end
