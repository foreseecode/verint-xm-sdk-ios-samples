//
//  FSHTTPRequest.h
//
//  Created by Michael Han on 2013-01-25.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FSHTTPResponse;

@interface FSHTTPRequest : NSObject {
  void (^_completeCallback)(FSHTTPResponse *response);
}

@property (nonatomic, strong) NSMutableURLRequest *urlRequest;

- (id)initWithRequest:(NSMutableURLRequest *)request callback:(void(^)(FSHTTPResponse *response))callback;

- (void)setCompleteCallback:(void(^)(FSHTTPResponse *response))callback;
- (void (^)(FSHTTPResponse *response))completeCallback;

@end
