//
//  NSObject+FSAlert.h
//  Foresee
//
//  Created by Wayne Burkett on 3/15/17.
//  Copyright © 2017 Foresee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (FSAlert)

- (void)fs_showAlertWithController:(UIAlertController *)controller
                       actionTitle:(NSString *)title
                       actionStyle:(UIAlertActionStyle)style
                     actionHandler:(void (^)(UIAlertAction * action))handler;

@end
