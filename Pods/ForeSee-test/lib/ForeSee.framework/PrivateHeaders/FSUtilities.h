//
//  FSUtilities.h
//  Utilities
//
//  Created by Michael Han on 2013-02-13.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

IMP _Nonnull MethodSwizzle(Class _Nonnull  c, SEL _Nonnull  origSEL, IMP _Nonnull _replacement_Method);
IMP _Nonnull MethodSwizzleWithBlock(Class _Nonnull c, SEL _Nonnull origSEL, id _Nonnull block);

@interface FSUtilities : NSObject

+ (NSString *)pathForResource:(NSString *)name;
+ (NSString *)pathForResource:(NSString *)name inBundle:(NSBundle *)bundle;
+ (UIImage *)clientImageNamed:(NSString *)name;
+ (UIImage *)imageNamed:(NSString *)name;
+ (UIImage *)imageNamed:(NSString *)name inBundleForClass:(Class)aClass;
+ (UIImage *)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle;
+ (void)loadFontWithName:(NSString *)fontName;
+ (void)loadFontWithName:(NSString *)fontName inBundle:(NSBundle *)bundle;

@end

NS_ASSUME_NONNULL_END
