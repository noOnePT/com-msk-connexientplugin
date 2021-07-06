//
//  CNXRoute.h
//  ConnexientSDK
//
//  Created by Fabian Fermin Guerra Soto on 11/29/13.
//  Copyright (c) 2013 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNXRouteStep.h"

typedef NS_ENUM(NSInteger, CNXRouteAlgorithm) {
    CNXRouteAlgorithmAuto=1,
    CNXRouteAlgorithmOriginal=2,
    CNXRouteAlgorithmIntersection=3
};


typedef NS_ENUM(NSInteger, CNXRouteType) {
    Indoor=1,
    Outdoor=2
};

typedef NS_ENUM(NSInteger, CNXRouteModality) {
    Driving=1,
    Transit=2,
    Walking=3
};

@class SDKAPPExtendedMarker;
@class CNXRouteSegment;

/**
 *  @brief Route model
 */
@interface CNXRoute : NSObject <NSCopying>

/**
 *  Distance of the route
 */
@property (nonatomic) double distance;

/**
 *  You can change number of steps if you change that parameter to ignore short turns or not. Default is YES.
 */
@property (nonatomic) BOOL ignoreShortTurns;


/**
 *  Starting position of the route
 */
@property (nonatomic, nonnull) SDKAPPExtendedMarker* source;


/**
 *  Final position of the route
 */
@property (nonatomic, nonnull) SDKAPPExtendedMarker* destination;


/**
 *  Waypoint of the route
 */
@property (nonatomic, nonnull) CNXPlace* waypoint;


/**
 *  Array of route steps
 */
@property (nonatomic, nullable) NSArray <CNXRouteStep*> *steps;

/**
 *  Current route step
 */
@property (nonatomic, nonnull) CNXRouteStep *currentRouteStep;

/**
 *  Current route step
 */
@property (nonatomic, nonnull) CNXRouteSegment *currentRouteSegment;

/**
 *  Array of route segments
 */
@property (nonatomic, nullable) NSArray <CNXRouteSegment*> *segments;


/**
 *  Array of route instructions
 */
@property (nonatomic, nullable) NSArray *instructions;

/**
 *  Type of the route
 */
@property (nonatomic) CNXRouteType routeType;

/**
 *  Modality of the route
 */
@property (nonatomic) CNXRouteModality routeModality;

/**
 *  If this is YES it will remove "near something" text in route instructions. By default it will be shown.
 */
@property (nonatomic) BOOL shouldHideNearInInstruction;

/**
 *  If this is YES, route will avoid stairs and will guide you throug elevators even this is not shortes path. Default is NO
 */
@property (nonatomic) BOOL avoidStairs;

/**
 *  Threshold - Distance (in meters) from elevator to trigger "Go up/down"
 *  Note : 6.0 is used for auto change if no value is set here
 */
@property (nonatomic) double elevatorThreshold;

/**
 *  Threshold - Distance (in meters) from the end of the route to trigger "You have arrived"
 *  Note : 6.0 is used for auto change if no value is set here
 */
@property (nonatomic) double youHaveArrivedThreshold;

/**
 *  Threshold - Distance (in meters) from the inside route to trigger "Off route" delegate
 *  Note : 12.0 is used for triggering offRoute if no value is set here
 */
@property (nonatomic) double insideOffRouteThreshold;

/**
 *  Threshold - Distance (in meters) from the outside route to trigger "Off route" delegate
 *  Note : 40.0 is used for triggering offRoute if no value is set here
 *  Important: this will ONLY trigger if SDK CAMPUS map is used for OUTSIDE ROUTE. It does not work for third part maps (Google, apple, etc)
 */
@property (nonatomic) double outsideOffRouteThreshold;

/**
 *  Algorithm which will be used to draw a route. Default is CNXRouteAlgorithmIntersection
 */
@property (nonatomic) CNXRouteAlgorithm routeAlgorithm;


@end
