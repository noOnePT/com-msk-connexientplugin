//
//  CNXRegion.h
//  Stanford
//
//  Created by Fabian Fermin Guerra Soto on 4/24/14.
//  Copyright (c) 2014 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  @brief Region model
 */
@interface CNXRegionZone : NSObject

/**
 *  Unique region ID
 */
@property (nonatomic, nonnull) NSNumber *regionID;

/**
 *  Name of the region zone
 */
@property (nonatomic, nonnull) NSString *name;


/**
 *  Proximity of the zone
 */
@property (nonatomic) int proximity;

/**
 *  Region type
 */
@property (nonatomic) int regionTypeID;

@end
