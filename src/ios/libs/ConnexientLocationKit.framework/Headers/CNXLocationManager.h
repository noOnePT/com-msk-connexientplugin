//
//  CNXLocationManager.h
//  ConnexientKit
//
//  Created by Mladjan Antic on 10/19/15.
//  Copyright © 2015 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientLocationKit/CNXRegionAlert.h>
#import "CNXRegionZone.h"
#import <ConnexientKit/ConnexientKit.h>
#import <CoreLocation/CoreLocation.h>

typedef enum cnxLocationStatus
{
    CNX_STATUS_UNDEFINED,
    CNX_STATUS_OUT_OF_SERVICE,
    CNX_STATUS_TEMPORARILY_UNAVAILABLE,
    CNX_STATUS_AVAILABLE,
} CNXLocationStatus;


typedef enum cnxServiceStatus
{
    CNX_SERVICE_STARTED,
    CNX_SERVICE_STOPPED,
    CNX_SERVICE_FAILED,
} CNXServiceStatus;

@protocol CNXStatusDelegate<NSObject>

@optional

/**
 *  Triggers when location status is changed
 *
 *  @param status CNXLocationStatus
 */
-(void)updateStatus:(CNXLocationStatus)status;

/**
 *  Triggers when servis status is changed
 *
 *  @param status CNXServiceStatus
 */
-(void)serviceStatusChange:(CNXServiceStatus)status;

/**
 *  Triggers when sync of pdb files is finished
 */
- (void)didSynchronizationSuccess;

/**
 *  Triggers when sync of pdb files is failed, with error message
 */
-(void)syncFailedWithMessage:(nonnull NSString *)message;

@end


@protocol CNXRegionDelegate<NSObject>

@optional

/**
 *  Triggers when region is changed
 *
 *  @param alert CNXRegionAlert instance
 */
-(void)regionAlert:(nonnull CNXRegionAlert *)alert;

/**
 *  Triggers when zone proximity is changed
 *
 *  @param zone CNXRegionZone instance
 */
-(void)regionZoneProximityChange:(nonnull CNXRegionZone *)zone;

/**
 *  Triggers when you go inside or outside
 *
 *  @param state CNXLocationCoordinateType (inside or outside)
 */
-(void)insideOutsideStateChangedTo:(CNXLocationCoordinateType)state;

@end

@protocol CNXPositionDelegate<NSObject>

@optional

/**
 *  Triggers when location is changed
 *
 *  @param location CNXLocationCoordinate instance
 */
-(void)updateLocation:(nonnull CNXLocationCoordinate *)location;


/**
 *  Triggers when outside location is changed
 *
 *  @param location CLLocation instance
 */
-(void)updateOutsideLocation:(nonnull CLLocation *)location;

@end

@interface CNXLocationManager : NSObject


/**
 *  Singleton instance
 *
 *  @return CNXLocationManager instance
 */
+ (nonnull instancetype)sharedManager;

/**
 *  Version of the locationKit framework
 *
 *  @return version as NSString object
 */
+ (nonnull NSString *)getLocationKitVersion;


-(nullable NSString *)apiKey;

-(nonnull NSString*)NAOVersion;

/**
 *  Start tracking position
 */
-(void)startTrackingForMap:(nonnull CNXMap *)map;

/**
 *  Start tracking position without map
 *  Use this one only if not using the one above.
 */
-(void)startTrackingForDefaultMap;

/**
 *   Stop tracking position
 */
-(void)stopTracking;


/**
 *  Start test provider for demo app
 */
-(void)startTestProviderWithStringOfCoordinates:(nonnull NSString * )stringOfcoordinates;

/**
 *  Upload debug data to our servers
 */
-(void)uploadLocationDebugInfo;

/**
*  Returns status sting
*/
-(NSString *)getStatusStringFromIndoor;
/**
 *  Last location registered
 */
@property (nonatomic, nullable) CNXLocationCoordinate *lastLocation;

/**
 *  Set to YES if you want to disable outdoor updated from CoreLocation
 */
@property (nonatomic) BOOL outdoorLocationProviderDisabled;

/**
 *  Set to YES sync of location data will be disabled and SDK will use only preloaded data from zip
 */
@property (nonatomic) BOOL syncDisabled;


/**
 *  Time when location manager is started
 */
@property (nonatomic, nullable) NSDate *locationManagerStartedAt;

/**
 *  Last outside location registered
 */
@property (nonatomic, nullable) CLLocation *lastOutsideLocation;


/**
 *  Last inside location registered
 */
@property (nonatomic, nullable) CNXLocationCoordinate *lastInsideLocation;


/**
 *  Last location status registered
 */
@property (nonatomic) CNXLocationStatus lastStatus;

/**
 *  Array of status delegates
 */
@property (nonatomic, nonnull) NSMutableSet *statusDelegates;

/**
 *  Array of position delegates
 */
@property (nonatomic, nonnull) NSMutableSet *positionDelegates;


/**
 *  Array of region delegates
 */
@property (nonatomic, nonnull) NSMutableSet *regionDelegates;

/**
 *  Desired outdoor location accuracy
 */
@property (nonatomic) CLLocationAccuracy desiredOutdoorAccuracy;



@end
