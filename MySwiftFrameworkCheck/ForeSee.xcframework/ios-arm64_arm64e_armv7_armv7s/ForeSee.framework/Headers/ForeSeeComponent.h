//
//  ForeSeeComponent.h
//  ForeSee
//
//  Created by Wayne Burkett on 8/22/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ForeSeeComponent <NSObject>

- (void)setup;
- (void)resetState;
- (void)endSession;

@end
