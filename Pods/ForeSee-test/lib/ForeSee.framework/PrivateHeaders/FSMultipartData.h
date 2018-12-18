//
//  FSMultipartData.h
//  SessionReplay
//
//  Created by Michael Han on 2013-01-22.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FSMultipartData : NSObject

@property (nonatomic, retain) NSOutputStream *outputStream;
@property (nonatomic, retain) NSMutableURLRequest *request;
@property (nonatomic, copy) NSString *boundary;
@property (nonatomic, copy) NSString *temporaryFile;

- (id)initWithRequest:(NSMutableURLRequest *)request;
- (void)appendPartWithFileData:(NSData *)data name:(NSString *)name fileName:(NSString *)fileName mimeType:(NSString *)mimeType;
- (void)appendPartWithValue:(NSString *)value name:(NSString *)name;
- (void)closeBody;
- (NSMutableURLRequest *)requestByClosingBody;

@end
