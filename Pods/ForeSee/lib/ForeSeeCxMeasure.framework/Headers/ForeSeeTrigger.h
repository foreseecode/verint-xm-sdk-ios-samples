//
//  ForeSeeTrigger.h
//  CxMeasure
//
//  Created by Wayne Burkett on 8/16/18.
//  Copyright © 2018 ForeSee. All rights reserved.
//

#import <ForeSee/ForeSee.h>
#import <ForeSee/FSTriggerDelegate.h>
#import <ForeSee/ForeSeeComponent.h>
#import <ForeSeeCxMeasure/FSTrackerDelegate.h>

@interface ForeSeeTrigger : NSObject <FSTriggerDelegate, FSTrackerDelegate, ForeSeeComponent>

@end
