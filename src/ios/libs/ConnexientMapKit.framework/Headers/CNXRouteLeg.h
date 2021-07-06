//
//  CNXRouteLeg.h
//  ConnexientSDK
//
//  Created by Mladjan Antic on 9/4/17.
//  Copyright © 2017 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientKit/CNXLocationCoordinate.h>
#import <ConnexientMapKit/CNXRouteSegment.h>
#import <ConnexientKit/CNXRoutingWaypoint.h>


@interface CNXRouteLeg : NSObject


/**
 * Leg CNXRoutingTypeInternal is using inside mapping service for routing (VG maps). Usually used for campus routes.
 * Leg CNXRoutingTypeExternal is using outside service for routing (Google Maps, Apple Maps, ...). Usually used for outside routes.
 */
typedef NS_ENUM(NSInteger, CNXRoutingType) {
    CNXRoutingTypeInternal=1,
    CNXRoutingTypeExternal=2
};


/**
 * Leg CNXPositioningTypeInside is using indoor positioning service (bluetooth beacons).
 * Leg CNXPositioningTypeGPS is using outdoor positioning service (GPS). This service may have no altitude
 * Leg CNXPositioningTypeNetwork is using outdoor positioning service (mobile network). This service may have no altitude.
 * CNXPositioningTypeAny - Any positioning service will be used. Use with care, as it may not give proper results
 */
typedef NS_ENUM(NSInteger, CNXPositioningType) {
    CNXPositioningTypeInside=1,
    CNXPositioningTypeGPS=2,
    CNXPositioningTypeNetwork=3,
    CNXPositioningTypeAny=0xFF
};


/**
 * Start of the leg in Geocoordinate system WGS84
 */
 @property (nonatomic) CNXLocationCoordinate *startLocation;

/**
 * End of the leg in Geocoordinate system WGS84
 */
 @property (nonatomic) CNXLocationCoordinate *destinationLocation;


/**
 * End of the leg as MapID
 */
@property (nonatomic) CNXLocationCoordinate *destinationMapId;

/**
 * ID of the campus for this leg. If invalid (-1) then it's outside route.
 */
@property (nonatomic) int campusID;

/**
 * If destination of this leg is waypoint, it will be true.
 */
@property (nonatomic) BOOL isDestinationWaypoint;

/**
 * Routing service type used for this leg.
 */
@property (nonatomic) CNXRoutingType routingType;

/**
 * Positioning service used for this leg.
 */
@property (nonatomic) CNXPositioningType positioningType;

/**
 * Array of waypoints for that leg.
 */
@property (nonatomic) NSMutableArray<CNXRoutingWaypoint *> *waypoints;

/**
 * ID of the inside map
 */
@property (nonatomic) int cnxmap_id;

@property NSArray<CNXRouteSegment *> *segments;

@property (nonatomic) int legNumber;

/**
 * Check is leg valid?
 */
-(BOOL)isValid;

@end
