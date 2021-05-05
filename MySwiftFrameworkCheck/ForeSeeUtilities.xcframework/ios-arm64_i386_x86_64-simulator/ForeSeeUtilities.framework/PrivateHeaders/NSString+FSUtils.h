//
//  NSString+FSUtils.h
//  Foresee
//
//  Created by Wayne Burkett on 5/25/16.
//  Copyright © 2016 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSString (FSUtils)

+ (NSString *)string:(NSString *)str orDefaultString:(NSString *)str2;
+ (NSString *)defaultString:(NSString *)str;
- (BOOL)isEmpty;
- (BOOL)isNotEmpty;
- (CGSize)sizeWithFont:(UIFont *)font inFrame:(CGRect)frame;
- (CGSize)sizeWithFont:(UIFont *)font andSize:(CGSize)size;
- (BOOL)isEmail;
- (BOOL)isPhoneNumber;
- (NSString *)percentEscapedQueryStringPairMemberFromStringWithEncoding;
- (NSString *)firstGroup:(NSString *)pattern;
+ (NSString *)webkitVersion:(NSString *)userAgent;

@end
