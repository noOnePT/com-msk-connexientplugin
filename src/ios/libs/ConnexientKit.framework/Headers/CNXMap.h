//
//  CNXMap.h
//  Connexient
//
//  Created by Mladjan Antic on 9/20/16.
//  Copyright © 2016 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNXLocationCoordinate.h"

@interface CNXMap : NSObject


@property (nonatomic, nonnull) NSNumber *mapID;
@property (nonatomic, nonnull) NSString *mapName;
@property (nonatomic, nonnull) NSString *mapDescription;
@property (nonatomic, nonnull) NSString *mapNameID;
@property (nonatomic, nonnull) NSNumber *venueID;
@property (nonatomic, nonnull) NSNumber *versionTimestamp;
@property (nonatomic, nonnull) NSString *sqliteDbFilename;
@property (nonatomic, nullable) NSString *backgroundColor1;
@property (nonatomic, nullable) NSString *backgroundColor2;
@property (nonatomic, nullable) NSString *analyticsId;

@property (nonatomic, nonnull) NSString *configHash;

@property (nonatomic) BOOL isAvailableOffline;
@property (nonatomic) BOOL isUpdateAvailable;

/**
 *  Initializes CNXMap object from db
 *
 *  @return Returns map with specific MapID if exists. If not, returns Nil
 */
+(nullable CNXMap * )mapWithID:(nonnull NSNumber * )mapID;

/**
 *  List of all available maps in that license
 *
 *  @return Returns NSArray of CNXMap objects
 */
+(nonnull NSArray<CNXMap*> * )allMaps;

/**
 *  Checks is coordiante inside ANY map
 *
 *  @return Returns NSDictionary with id, name and vg_map_id param (which can be used to initialize CNXMap instance)
 */
+(nullable NSDictionary * ) isCoordinateInsideOfAnyMap:(nonnull CNXLocationCoordinate * )coordinate;

/**
 *  Checks is location inside THAT CNXMap instance
 *
 *  @return YES or NO
 */
-(BOOL)isCoordinateInsideThisMap:(nonnull CNXLocationCoordinate * )coordinate;

@end
