//
//  FSContactDetails.h
//  ForeSee
//
//  Created by Wayne Burkett on 5/30/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ForeSee_Private.h"

@interface FSContactDetails : NSObject

@property (nonatomic, assign) FSContactType preferredContactType;

#pragma mark - Init

/** Creates an FSContactDetails instance from a single set of contact details and type.
 
 This should really only be needed when deserializing old contactDetails strings from disk, so
 that they can be placed inside this new structure.
 
 @since v5.1.0
 @param contactDetails a string containing contact details
 */
- (instancetype)initWithContactDetails:(NSString *)contactDetails;

#pragma mark - Typeless accessors

- (NSString *)contactDetails;
- (void)setContactDetails:(NSString *)contactDetails;

#pragma mark - Accessors

- (NSString *)contactDetailsForType:(FSContactType)type;
- (NSString *)contactDetailsForPreferredType;
- (void)setContactDetails:(NSString *)contactDetails forType:(FSContactType)type;
- (NSDictionary<NSNumber *, NSString *> *)allContactDetails;

@end
