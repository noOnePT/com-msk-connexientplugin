//
//  CNXRouteStep.h
//  ConnexientMapKit
//
//  Created by Fabian Fermin Guerra Soto on 11/29/13.
//  Copyright (c) 2013 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientKit/CNXConstants.h>
#import <ConnexientKit/CNXLocationCoordinate.h>

typedef NS_ENUM(NSInteger, CNXTransportType){
    CNXTransportTypeAutomobile,
    CNXTransportTypeWalking
};


/**
 *  @brief Model for route step
 */
@interface CNXRouteStep : NSObject

/**
 *  Step number
 */
@property (nonatomic) unsigned int stepNumber;

/**
 *  Text of the instruction
 */
@property (nonatomic, nullable) NSString *instructions;

/**
*  Text of the instruction in feet
*/
@property (nonatomic, nullable) NSString *ftInstructions;

/**
 *  Array of instruction positions
 */
@property (nonatomic, nullable) NSArray *positions;

/**
 *  Notice of the instruction
 */
@property (nonatomic, nullable) NSString *notice;

/**
 *  Distance of the step (wording)
 */
@property (nonatomic, nullable) NSString *distance;

/**
 *  Distance of the step (number in meters)
 */
@property (nonatomic, nullable) NSNumber *distanceInMeters;

/**
 *  Name of the maneuver
 */
@property (nonatomic, nullable) NSString *maneuver;

/**
 *  Transport type
 */
@property (nonatomic) CNXTransportType transporType;

/**
 *  Maneuver type
 */
@property (nonatomic) CNXManeuverType maneuverType;

/**
 *  Layer number (floor)
 */
@property (nonatomic, nonnull) NSString  *floor;

/**
 *  Location of the step
 */
@property (nonatomic, nullable) CNXLocationCoordinate *locationCoordinate;

@end
