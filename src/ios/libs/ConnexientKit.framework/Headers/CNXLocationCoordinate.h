//
//  CNXLocationCoordinate.h
//  Stanford
//
//  Created by Fabian Fermin Guerra Soto on 11/29/13.
//  Copyright (c) 2013 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

typedef NS_ENUM(NSInteger, CNXLocationCoordinateType) {
    IndoorLocationCoordinate,
    OutdoorLocationCoordinate
};

typedef NS_ENUM(NSInteger, CNXLocationCoordinateSource) {
    CNXLocationCoordinateSourceGPS,
    CNXLocationCoordinateSourceBLE
};


/**
 *  @brief Location model (Indoor or Outdoor)
 */
@interface CNXLocationCoordinate : NSObject<NSCopying>


/**
 *  Type of location (indoor / outdoor)
 */
@property (nonatomic) CNXLocationCoordinateType locationCoordinateType;


/**
 *  Source of the location (GPS or BLE)
 */
@property (nonatomic) CNXLocationCoordinateSource locationCoordinateSource;


/**
 *  Latitude value, required
 */
@property (nonatomic) float latitude;

/**
 *  Longitude value, required
 */
@property (nonatomic) float longitude;


/**
 *  Altitude value, required
 */
@property (nonatomic) float altitude;


/**
 *  Bearing or heading, value between 0 and 360, in degrees.
 */
@property (nonatomic) double bearing;

/**
 *  Precision of the location, defined by location provider
 */
@property (nonatomic) double accuracy;

/**
 *  Vertical precision of the location, defined by location provider
 */
@property (nonatomic) double verticalAccuracy;



/**
 *  Location created time/date
 */
@property (nonatomic, strong) NSDate *locationTimestamp;

/**
 *  Coordinates can be described as Geo coordinates and Scene coordinates. Scene coordinates are local, just on that map. Geo coordinates are coordinates used by all other maps, including our LocationKit. It's really important to set this flag properly when you create your CNXLocationCoordinate instance
 */
@property (nonatomic) BOOL usingGeoCoordinates;


/**
 * Original location from CoreLocation
 */
@property  CLLocation *originalCLLocation;


/**
 *  Helper method which generates random coordinates between some longitude and latitdude, for testing purposes.
 *
 *  @param longitude double value
 *  @param latitude  double value
 *  @param trashold  double value
 */
-(void)generateRandomCoordinatesFromLongitude:(double)longitude andLatitude:(double)latitude withTreshold:(double)trashold;

- (BOOL)isEqualToLocationCoordinate:(CNXLocationCoordinate *)location;

-(id)initWithLongitude:(float)longitude latitude:(float)latitude altitude:(float)altitude geocoordiante:(BOOL)geocoordinate;

@end
