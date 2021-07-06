//
//  CNXGeoHelper.h
//  ConnexientSDK
//
//  Created by Mladjan Antic on 8/1/16.
//  Copyright © 2016 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientKit/CNXLocationCoordinate.h>

@interface CNXGeoHelper : NSObject

/**
 *  Calcualtes distance between two GEO locations
 *
 *  @param pointA GEO location A
 *  @param pointB GEO location B
 *
 *  @return double distance in Miles
 */
+ (double)calcGeoDistanceFromPointA:(nonnull CNXLocationCoordinate *)pointA toPointB:(nonnull CNXLocationCoordinate *)pointB;

/**
 *  Calcualtes distance between two SCENE locations
 *
 *  @param pointA location A
 *  @param pointB location B
 *
 *  @return double distance in Miles
 */
+ (double)calcLocalDistanceFromPointA:(nonnull CNXLocationCoordinate *)pointA toPointB:(nonnull CNXLocationCoordinate *)pointB;

/**
 *  Checks is some coordinate inside of polygon described as array of CNXLocationCoordinate objects
 *
 *  @param coordinate       CNXLocationCoordinate instance - point to check
 *  @param arrayCoordinates Array of CNXLocationCoordiante instances which describe polygon
 *
 *  @return YES if coordinate is inside polygon, NO if it's not
 */
+(BOOL) isCoordinate:(nonnull CNXLocationCoordinate *)coordinate insideArrayOfCoordinates:(nonnull NSArray *)arrayCoordinates;


/**
 *  Checks is some coordinate inside of any building
 *
 *  @param coordinate CNXLocationCoordinate instance - point to check
 *
 *  @return id if coordinate is inside building, 0 if it's not
 */
+(int)isCoordinateInsideOfAnyBuilding:(nonnull CNXLocationCoordinate *)coordinate;


/**
 *  Checks is some coordinate inside of any building
 *
 *  @param coordinate CNXLocationCoordinate instance - point to check
 *
 *  @return NSDictionary if coordinate is inside venue, nil if it's not
 */
+(nullable NSDictionary * ) isCoordinateInsideOfAnyVenue:(nonnull CNXLocationCoordinate *)coordinate;

/**
 *  Checks is some coordinate inside of specific venue
 *
 *  @param coordinate CNXLocationCoordinate instance - point to check
 *
 *  @return NSDictionary if coordinate is inside venue, nil if it's not
 */
+(nullable NSDictionary *)isCoordinateInsideOfVenueWithMapId:(nonnull NSNumber *)vgMapId fromCoordinate:(nonnull CNXLocationCoordinate *)coordinate;

/**
 *  Coordiantes string parser
 *
 *  @param coordiantesString string in JSON format
 *
 *  @return Array of coordinate pairs
 */
+(nonnull NSArray *)getArrayOfCoordinatesFromCoordinatesString:(nonnull NSString*)coordiantesString;


/**
 *  Returns MapIf from VenueId
 *
 *  @param venueId - Id of the venue
 *
 *  @return Map ID integer
 */
+(int)getMapIdForVenueWithId:(int)venueId;

+ (BOOL) isToUseMeterForRouteSteps;

@end
