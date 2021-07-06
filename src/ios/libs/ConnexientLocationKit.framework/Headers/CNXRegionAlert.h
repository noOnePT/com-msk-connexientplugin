//
//  CNXRegionAlert.h
//  Stanford
//
//  Created by Fabian Fermin Guerra Soto on 5/6/15.
//  Copyright (c) 2015 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  @brief Region alert model
 */
@interface CNXRegionAlert : NSObject

/**
 *  Unique alert ID
 */
@property (nonatomic) NSInteger alertID;

/**
 *  Region alert name
 */
@property (nonatomic, nullable) NSString *name;

/**
 *  Region alert message
 */
@property (nonatomic, nullable) NSString *message;


@end
