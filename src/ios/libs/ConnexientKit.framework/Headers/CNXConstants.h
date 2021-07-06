//
//  CNXConstants.h
//  ConnexientSDK
//
//  Created by Fabian Fermin Guerra Soto on 1/22/14.
//  Copyright (c) 2014 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include <AvailabilityMacros.h>

typedef NS_ENUM(NSInteger, CNXMapViewType) {
    CNXMapViewTypeGlobal=0,
    CNXMapViewTypeBuilding=1,
    CNXMapViewTypeFloor=2
};

typedef enum {
    CNXMarkerTypeUserLocation,
    CNXMarkerTypeCustom,
} CNXMarkerType;


typedef enum{
    CNXRouteStyleColorRed,
    CNXRouteStyleColorBlue,
    CNXRouteStyleColorGreen,
    CNXRouteStyleColorPurple
} CNXRouteStlyeColor;


typedef enum{
    CNXRouteInstructionsStyleModern,
    CNXRouteInstructionsStyleSimple
} CNXRouteInstructionsStyle;

typedef enum{
    CNXSDKEnvironmentProduction,
    CNXSDKEnvironmentDevelopment,
    CNXSDKEnvironmentStaging,
    CNXSDKEnvironmentDevelopment2,
    CNXSDKEnvironmentRMC
} CNXSDKEnvironment;

typedef NS_ENUM(NSInteger, CNXFloorTransitionType){
    CNXFloorTransitionTypeUnknown = 0,
    CNXFloorTransitionTypeStairs,
    CNXFloorTransitionTypeElevator,
    CNXFloorTransitionTypeEscalator
};

typedef NS_ENUM(NSInteger, CNXManeuverType){
    /**
     * Unknown maneuver type.
     */
    CNXManeuverTypeUnknown = 0,
    /**
     * Go straight.
     */
    CNXManeuverTypeGoStraight,
    /**
     * Turn gentle right.
     */
    CNXManeuverTypeTurnGentleRight,
    /**
     * Turn gentle left.
     */
    CNXManeuverTypeTurnGentleLeft,
    /**
     * Turn right.
     */
    CNXManeuverTypeTurnRight,
    /**
     * Turn left.
     */
    CNXManeuverTypeTurnLeft,
    /**
     * Turn sharp right.
     */
    CNXManeuverTypeTurnSharpRight,
    /**
     * Turn sharp left.
     */
    CNXManeuverTypeTurnSharpLeft,
    /**
     * U-turn right.
     */
    CNXManeuverTypeUTurnRight,
    /**
     * U-turn left.
     */
    CNXManeuverTypeUTurnLeft,
    /**
     * Start of route.
     */
    CNXManeuverTypeStart,
    /**
     * End of route.
     */
    CNXManeuverTypeEnd, //11
    /**
     * Go up to next level.
     * Only possible if mMergeFloorChangeInstructions is false.
     */
    CNXManeuverTypeGoUp, //12
    /**
     * Go down to next level.
     * Only possible if mMergeFloorChangeInstructions is false.
     */
    CNXManeuverTypeGoDown, //13
    /**
     * The modality has changed.
     * Only possible if mMergeFloorChangeInstructions is false.
     */
    CNXManeuverTypeChangeModality, //14
    /**
     * The layer has changed, but it is at the same height and modality
     * (otherwise it would be a eVgManeuverTypeGoUp or eVgManeuverTypeGoDown)
     * usually means changing buildings.
     *
     * @version 2.1.2
     */
    CNXManeuverTypeChangeLayer,
    /**
     * Intermediate waypoint.
     *
     * @version 2.1.4
     */
    CNXManeuverTypeWaypoint,

    /**
     * This enum represents the maximum enum value possible (should always be last).
     */
    CNXManeuverTypeMax
};

typedef NS_ENUM(NSInteger, CNXSyncUpdateMethod) {
    
    CNXSyncUpdateMethodAuto=0, // automatically perform sync
    CNXSyncUpdateMethodAsk=1, // allow user to decide whether to perform sync
    CNXSyncUpdateMethodNone=2 // do not perform sync (i.e. use only embedded data)
};

static NSString * __nonnull const kLastInstructionNotification = @"kLastInstructionNotification";
static NSString * __nonnull const kMapDetailViewNotification = @"kMapDetailViewNotification";
static NSString * __nonnull const kBackToInstructionsNotification = @"kBackToInstructionsNotification";
static NSString * __nonnull const kFloorChangeNotification = @"kFloorChangeNotification";
static NSString * __nonnull const kNextInstructionNotification = @"kNextInstructionNotification";
static NSString * __nonnull const kInstructionChanged = @"kInstructionChanged";
static NSString * __nonnull const kPlaceTappedOnMap = @"kPlaceTappedOnMap";
static NSString * __nonnull const kMapStartedDownloading = @"kMapStartedDownloading";
static NSString * __nonnull const kMapFinishedDownloading = @"kMapFinishedDownloading";
static NSString * __nonnull const kMapNotFinishedDownloading = @"kMapNotFinishedDownloading";
static NSString * __nonnull const kMapsReadyForUse = @"kMapsReadyForUse";
static NSString * __nonnull const kMapsNotReadyForUse = @"kMapsNotReadyForUse";
static NSString * __nonnull const kMapCopyReadyForUse = @"kMapCopyReadyForUse";
static NSString * __nonnull const kMapUpdated = @"kMapUpdated";
static NSString * __nonnull const kDbUpdated = @"kDbUpdated";
static NSString * __nonnull const kLocationDataUpdated = @"kLocationDataUpdated";

// download has started for N files that should be downloaded/updated
// notification object will contain a NSArray <CNXSyncObject *> *syncObjectArray that will have sync objects that will be downloaded
static NSString * __nonnull const kSyncDownloadStarted = @"kSyncDownloadStarted";

// total progress (count of bytes downloaded / total size of files to download)
// notification object will contains a NSNumber (double) to show progess from 0-1 to best usage for progess bars
static NSString * __nonnull const kSyncDownloadProgress = @"kSyncDownloadProgress";

// download succeeded for all files
static NSString * __nonnull const kSyncDownloadFinished = @"kSyncDownloadFinished";

// download fail with Error
// notification object will contains a NSError object
static NSString * __nonnull const kSyncDownloadFail = @"kSyncDownloadFail";

// notify the user there are files ready for download
// notification object will contain a NSNumber (double) that is the total (in bytes) to be downloaded
static NSString * __nonnull const kSyncUpdateMethodAsk = @"kSyncUpdateMethodAsk";


/**
 * Default building name, used when there is no Venue Layout file
 */
static NSString * __nonnull const VgUnknownBuildingName = @"<Building>";


/**
 *  @brief General glubal list of constants
 */
@interface CNXConstants : NSObject


/**
 *  Helper method to initialize VC from device aware storyboard
 *
 *  @param controllerName name of the VC
 *  @param boardName      name of the storyboard
 *
 *  @return UIViewController instance
 */
+ (nullable id)instantiateViewController:(nonnull NSString*)controllerName fromStoryboard:(nonnull NSString*)boardName;

@end
