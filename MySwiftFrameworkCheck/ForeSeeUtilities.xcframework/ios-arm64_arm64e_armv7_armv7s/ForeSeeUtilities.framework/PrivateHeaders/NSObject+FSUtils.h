//
//  NSObject+FSObject.h
//  Utilities
//
//  Created by Michael Han on 2013-04-09.
//  Copyright (c) 2013 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (FSUtils)

- (void)fs_setValue:(id)value forKey:(id)key;
- (id)fs_getValueForKey:(id)key;
- (void)fs_removeValueForKey:(id)key;

@end
