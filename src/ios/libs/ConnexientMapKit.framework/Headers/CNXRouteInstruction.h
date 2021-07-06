//
//  CNXRouteInstruction.h
//  ConnexientDemo
//
//  Created by Mladjan Antic on 6/3/16.
//  Copyright © 2016 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientKit/CNXConstants.h>
#import <ConnexientKit/CNXLocationCoordinate.h>

/**
 *  Describes one instruction in the route
 */
@interface CNXRouteInstruction : NSObject

/**
 *  Type of the maneuver (like turn right, go up, etc)
 */
@property (nonatomic) CNXManeuverType maneuverType;

/**
 *  On floor transition, it will mark which type of transition this is
 */
@property (nonatomic) CNXFloorTransitionType floorTransitionType;

/**
 *  Floor mapID
 */
@property ( nonatomic) NSString * _Nullable floor;
/**
 *  Current step number
 */
@property (nonatomic, nonnull) NSNumber *stepNumber;

/**
 *  Number of all steps
 */
@property (nonatomic, nonnull) NSNumber *numberOfSteps;

/**
 *  Location of the instruction
 */
@property (nonatomic, nonnull) CNXLocationCoordinate *location;

/**
 *  Place name where you are
 */
@property (nonatomic, nonnull) NSString *placeName;

/**
 *  Text of the instruction
 */
@property (nonatomic, nonnull) NSString *instruction;

/**
 *  Text of the instruction in feet
 */
@property (nonatomic, nonnull) NSString *ftInstruction;

/**
 *  Notice
 */
@property (nonatomic, nullable) NSString *notice;

/**
 *  Distance as string
 */
@property (nonatomic, nullable) NSString *distanceString;

/**
 *  Distance as number
 */
@property (nonatomic, nullable) NSNumber *distance;

@end

