//
//  CNXSQLite.h
//  ConnexientSDK
//
//  Created by Fabian Fermin Guerra Soto on 1/14/14.
//  Copyright (c) 2014 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientKit/CNXMap.h>
#import <ConnexientKit/CNXConstants.h>
#import <ConnexientKit/CNXBaseSQLiteStore.h>
#import <ConnexientKit/CNXPlace.h>
#import <ConnexientKit/CNXLocationCoordinate.h>

/**
 *  @brief Represents sqlite database wrapper
 */
@interface CNXSQLite : NSObject




/**
 *  Singleton instance
 *
 *  @return CNXSQLite instance
 */
+ (nonnull CNXSQLite *)sharedInstance;

/**
 *  Opens SQLite database
 */
- (void)openDatabaseForMap:(nonnull CNXMap *)map;

/**
 *  Opens SQLite database for appKey in current language
 */
- (BOOL)openDatabaseForAppKey:(nonnull NSString *)appKey;
/**
 *  Closes SQLite database
 */
- (void)closeDatabase;



/**
 *  Get title for place with map id
 *
 *  @param mapID String which represents some place/marker on the map
 *
 *  @return Title string
 */
- (nullable NSString *) getTitleForMapID:(nonnull NSString *)mapID;

/**
 *  Get list of all CNXPlace objects from all campuses
 *
 *  @return Array of CNXPlace objects
 */
- (nonnull NSArray *)getPlaces;


/**
 *  Get list of all CNXPlace objects from specific campus
 *
 *  @return Array of CNXPlace objects
 */
- (nonnull NSArray *)getPlacesForCampusWithMapId:(nonnull NSNumber *)mapId;

/**
 *  Get CNXPlace object from map id string
 *
 *  @param mapId String which represents some place/marker on the map
 *
 *  @return CNXPlace object
 */
- (nullable CNXPlace *)getPlaceWithMapId:(nonnull NSString *)mapId;

/**
 *  Get CNXPlace object from map id string
 *
 *  @param mapId String which represents some place/marker on the map
 *  @param venueId Number Integer which represents venue/campus ID
 *
 *  @return CNXPlace object
 */
- (nullable CNXPlace *)getPlaceWithMapId:(nonnull NSString *)mapId fromVenueWithId:(nonnull NSNumber *)venueId;

/**
*  Get CNXPlace object from map id string
*
*  @param externalmapId String which represents some place/marker on the map
*  @param venueId Number Integer which represents venue/campus ID
*
*  @return CNXPlace object
*/

- (nullable CNXPlace *)getPlaceWithExternalMapId:(nonnull NSString *)mapId fromVenueWithId:(NSNumber *)venueId;

/**
 *  Get mod building id from building mapid
 *
 *  @param mapID String which represents mapid
 *
 *  @return int object
 */
-(int)getBuildingIdFromBuildingMapID:(nonnull NSString *)mapID;

/**
 *  Get venue id from mapid
 *
 *  @param mapID String which represents mapid
 *
 *  @return int object
 */
-(int)getVenueIdFromVenueMapID:(nonnull NSNumber *)mapID;

/**
 *  Get venue config from mapid
 *
 *  @param mapID String which represents mapid
 *
 *  @return NSString object with JSON String
 */
-(nonnull NSString *)getVenueConfigFromVenueMapID:(nonnull NSNumber *)mapID;

/**
 *  Get venue config from mapid
 *
 *  @param mapID String which represents mapid
 *
 *  @return NSDictionary object config pairs
 */
-(nullable NSDictionary *)getVenueConfigDictionaryFromVenueMapId:(NSNumber *_Nullable)mapID;

/**
 *  Returns all places of type 'Car garage'
 *
 *  @return Array of CNXPlace objects
 */
- (nonnull NSArray *)getAllParkingPlaces;


/**
 *  Get all places of specific type
 *
 *  @param placeType Type of place
 *
 *  @return Array of CNXPlace objects
 */
- (nonnull NSArray *)getAllPlacesOfType:(CNXPlaceType)placeType;


/**
 *  Get all places of specific location type
 *
 *  @param placeType Type of place
 *
 *  @return Array of CNXPlace objects
 */
- (nonnull NSArray *)getAllPlacesOfLocationType:(CNXPlaceLocationType)placeType;

/**
 *  Get all places of specific location type
 *
 *  @param placeType Type of place
 *  @param venueId filter
 *
 *  @return Array of CNXPlace objects
 */
- (nonnull NSArray *)getAllPlacesOfLocationType:(CNXPlaceLocationType)placeType fromVenueWithId:(nonnull NSNumber *)venueId;

/**
 *  Get all location place types
 * *
 *  @return Array of NSDictionary objects
 */
- (nonnull NSArray *)getAllLocationTypes;

/**
 *  Returns JSON string configuration for building in single building map
 *
 *  @return raw JSON String
 */
- (nonnull NSString*)getJSONConfigForSingleBuilding;

/**
 *  Returns JSON string configuration for building with mapID in multi building map
 *
 *  @param mapId building map id
 *
 *  @return raw JSON String
 */
- (nonnull NSString*)getJSONConfigForBuildingWithMapId:(nonnull NSString *)mapId;


/**
 *  Returns array of NSDictionary objects which describe all buildings on the map
 *
 *  @return NSArray of NSDictionary objects.
 */
- (nonnull NSArray *)getAllBuildings;

/**
 *  Returns array of NSDictionary objects which describe all buildings on the map
 *
 *  @return NSArray of NSDictionary objects.
 */
- (nonnull NSArray *)getAllBuildingsInVenueWithMapId:(nonnull NSNumber *)mapID;

/**
 *  Returns array of NSDictionary objects which describe all floors on all map
 *
 *  @return NSArray of NSDictionary objects.
 */
- (nonnull NSArray *)getAllFloors;


/**
 *  Returns array of NSDictionary objects which describe all floors on the map
 *
 *  @return NSArray of NSDictionary objects.
 */
- (nonnull NSArray *)getAllFloorsInVenueWithMapId:(nonnull NSNumber *)mapID;

/**
 *  Returns array of NSDictionary objects which describe all floors on the map
 *
 *  @return NSArray of NSDictionary objects.
 */
- (nonnull NSArray *)getAllFloorsInBuildingWithId:(nonnull NSNumber *)modBuildingId;
/**
 *  Returns array of NSDictionary objects which describe all buildings on the map
 *
 *  @return NSArray of NSDictionary objects.
 */
- (nonnull NSArray *)getAllVenues;


/**
 *  Returns array of NSDictionary objects which describe all buildings on the map
 *
 *  @return NSArray of NSDictionary objects.
 */
- (nonnull NSArray *)getAllVenuesAdvanced;

/**
 *  Returns NSString name of the floor from floor ID (1,2,3,...)
 *
 *  @return NSString floor name.
 */
- (nullable NSString *)getFloorNameFromFloorId:(nonnull NSString *)floorId;

/**
 *  Returns NSArray of floors (name and mod_building_id)
 *
 */
- (nullable NSArray *)getFloorsWithFloorMapId:(nonnull NSString *)floorMapId;

/**
 *  Returns NSString name of the floor from floor Map ID (B1-UL2)
 *
 *  @return NSString floor name.
 */
- (nullable NSString *)getFloorNameFromFloorMapId:(nonnull NSString *)floorMapId;

/**
*  Returns NSString name of the floor from place Map ID (B1-UL2)
*
*  @return NSString floor name.
*/
- (nullable NSString *)getFloorNameFromPlaceMapId:(nonnull NSString *)placeMapId;
/**
 *  Returns NSString name of the floor from floor Map ID (B1-UL2) in Active building
 *
 *  @return NSString floor name.
 */
- (nullable NSString *)getFloorNameInActiveVenueFromFloorMapId:(nonnull NSString *)floorMapId;

/**
 *  Returns NSString name of the floor from floor Map ID (B1-UL2) in Active building
 *
 *  @return NSDictionary floor dic.
 */
- (nullable NSDictionary *)getFloorInActiveVenueFromFloorMapId:(nonnull NSString *)floorMapId;

/**
 *  Returns NSString name of the building for that floor
 *
 *  @return NSString building map id.
 */
- (nullable NSString *)getBuildingMapIdFromFloorName:(nonnull NSString *)floor;

/**
 *  Returns NSString mapID of the building for that floor on specific venue
 *
 *  @return NSString building map id.
 */
- (nullable NSString *)getBuildingMapIdFromFloorName:(nonnull NSString *)floor inVenueId:(nonnull NSNumber *)venueID;

/**
 *  Returns NSString name of the building for that floor on specific venue
 *
 *  @return NSString building map id.
 */
- (nullable NSString *)getBuildingNameFromFloorName:(nonnull NSString *)floor inVenueId:(nonnull NSNumber *)venueID;

- (nonnull NSArray *)getAllUnfilteredLocationTypes;
- (nonnull NSArray *)getAllUnfilteredPlacesOfType:(CNXPlaceLocationType)placeType;
- (nonnull NSArray *)getAllUnfilteredPlacesOfLocationType:(CNXPlaceLocationType)placeType fromVenueWithId:(nonnull NSNumber *)venueId;

- (float)getFloorAltitudeFromFloorMapId:(NSString *_Nullable)floorMapId;
-(nonnull NSString *)locationDBUrlForMap:(CNXMap *_Nonnull)map;
- (NSString *_Nullable)healthCheckTest;
-(NSMutableArray *)getVenuesFromVenueMapID:(NSNumber *)mapID;
@end
