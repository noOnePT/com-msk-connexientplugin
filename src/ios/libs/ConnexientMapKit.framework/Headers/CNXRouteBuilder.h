//
//  CNXRouteBuilder.h
//  ConnexientSDK
//
//  Created by Mladjan Antic on 9/4/17.
//  Copyright © 2017 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientMapKit/CNXGeneralRoute.h>
#import <ConnexientKit/CNXLocationCoordinate.h>

@protocol CNXRouteBuilderDelegate<NSObject>

@optional
/**
 *  Implementing this delegate method you are able to override internal entrance for campus logic.
 */
-(nullable CNXLocationCoordinate *)getCampusInternalEntranceFromCampusId:(int)campusId startLocation:(nonnull CNXLocationCoordinate *)start andDestinationLocation:(nonnull CNXLocationCoordinate *)destination;

/**
 *  Implementing this delegate method you are able to override external entrance for campus logic.
 */
-(nullable CNXLocationCoordinate *)getCampusExternalEntranceFromCampusId:(int)campusId startLocation:(nonnull CNXLocationCoordinate *)start andDestinationLocation:(nonnull CNXLocationCoordinate *)destination;

@end

@interface CNXRouteBuilder : NSObject


/**
 *  Map delegate. See protocol for more details.
 */
@property (nonatomic, weak, nullable) id<CNXRouteBuilderDelegate> routebuilderDelegate;


/**
 * Start of the route. Where user is starting from. This is the start of the first route leg.
 */

@property (nonatomic, nonnull) CNXLocationCoordinate *startLocation;

/**
 * End of the route. Where user is going to. This is the end of the last route leg.
 */
@property (nonatomic, nonnull) CNXLocationCoordinate *destinationLocation;

/**
 * This method takes all available data, and builds RouteGeneral object, containing different legs of the multi-campus, multi-building route.
 */
-(nullable CNXGeneralRoute *)build;

/**
 * Checks in database whether a location belongs to a campus, using the geo-fence.
 */
-(int)getCampusIDForLocation:(nonnull CNXLocationCoordinate *)location;


-(void)addWaypointsToList:(nonnull NSArray *)waypoints;

#pragma mark -- Test Methods

-(nullable CNXGeneralRoute *)buildInsideOutsideRoute:(nonnull CNXGeneralRoute *)route startingWithCampusId:(int)startCampusId;

-(nullable CNXGeneralRoute *)buildOutsideInsideRoute:(nonnull CNXGeneralRoute *)route startingWithCampusId:(int)campusId;

-(nullable CNXGeneralRoute *)buildOutsideOutsideRouteFromRoute:(nonnull CNXGeneralRoute*)routeEx start:(nonnull CNXLocationCoordinate *)startLocation destination:(nonnull CNXLocationCoordinate *)destinationLocation andWayPoints:(nonnull NSArray<CNXLocationCoordinate*> *)waypoints;


-(nullable CNXGeneralRoute *)buildSingleCampusRoute:(nonnull CNXGeneralRoute *)route campusId:(int)campusId start:(nonnull CNXLocationCoordinate *)start andDestination:(nonnull CNXLocationCoordinate *)destination withWaypoints:(nonnull NSArray *)waypoints;



@end
