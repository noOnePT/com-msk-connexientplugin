//
//  CNXMapManager.h
//  ConnexientSDK
//
//  Created by Fabian Fermin Guerra Soto on 11/29/13.
//  Copyright (c) 2013 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientKit/CNXConstants.h>
#import "CNXMapMarker.h"

@class CNXMapConfig;
@class CNXRoute;
@class CNXRouteStep;
@class CNXRouteSegment;
@class CNXMapMarker;
@class CNXLocationCoordinate;
@class CNXPlace;
@class CNXRouteInstruction;
@class CNXMapBuilding;
@class CNXMap;
@class CNXGeneralRoute;
@class CNXRouteLeg;
@class CNXMapView;

/**
 *  @brief MapView delegate which has few delegate methods about map loading and floor changes
 */
@protocol CNXMapDelegate<NSObject>

@optional
/**
 *  Map is setup, but not yet loaded
 *
 *  @param mapView map view object
 */
-(void)mapViewDidSetup:(nonnull CNXMapView *)mapView;

/**
 *  Map is loaded, you can do any customization after that
 *
 *  @param mapView map view object
 */
-(void)mapViewDidLoaded:(nonnull CNXMapView *)mapView;

/**
 *  Floor is changed
 *
 *  @param fromFloorId from floor
 *  @param toFloorId   to floor
 */
-(void)floorHasChangedFrom:(nonnull NSString*)fromFloorId to:(nonnull NSString*)toFloorId;

/**
 *  Map View was moved(panned/tapped)
 *
 */
-(void) didMoveTheMap;

@end

/**
 *  @brief Map navigation delegate which has few delegate methods about calculating and displaying routes on the map
 */
@protocol CNXNavigationDelegate<NSObject>

@optional

/**
 *  Route is calculated successfuly
 */
-(void)routeCalculated;

/**
 *  Route is not calculated, probably non-existing map ids provided
 */
-(void)routeNotCalculated;

/**
 *  Route instruction with specific index is showing
 *
 *  @param routeInstruction index of instruction
 */
-(void)routeInstructionDisplay:(nonnull CNXRouteInstruction *)routeInstruction;

/**
 *  Last instruction is done
 */
-(void)routeLastInstructionDone;

/**
 *  Providing xib name of interface for routing view
 *
 *  @return name of xib file
 */
-(nullable NSString*)routeDisplayViewXibName;


/**
 *  Providing a UIVIew object for routing interface
 *
 *  @return UIView object
 */
- (nonnull UIView *)routeDisplayViewFromSender:(nonnull id)sender;


/**
 *  Action on CNXPlace on map
 *
 *  @param place CNXPlace object
 */
-(void)didPressPlaceOnMapPlace:(nonnull CNXPlace *)place;


/**
 *  Off route detected based on insideOffRouteThreshold and outsideOffRouteThreshold on CNXRoute
 *  If NO threshold is set on CNXRoute, 12.0 (meters) is used for inside and 40.0 for outside
 *  This protocol will ONLY be triggered if -(NSInteger)getInstructionIndexForLocation:(nonnull CNXLocationCoordinate *)location is used
 *  @param distance distance of the user from the route
 *  @param isWrongFloor true if it is on wrong floor after 30 sec, timer is needed as user may be in elevator.
 *  Notice: if isWrongFloor = true, then distance will be 0 (zero)
 */
-(void)offRouteDetectedWithDistance:(double)distance isWrongFloor:(BOOL) isWrongFloor;

-(void)nextRouteLeg:(nonnull CNXRouteLeg *)leg inRoute:(nonnull CNXGeneralRoute *)route;

-(void)nextRouteSegment:(nonnull CNXRouteSegment *)segment inRouteLeg:(nonnull CNXRouteLeg *)leg;


@end



/**
 *  @brief Map manager which is loading the map, changing views, draw routes, etc.
 */
@interface CNXMapManager : NSObject

/**
 *  Map delegate. See protocol for more details.
 */
@property (nonatomic, weak, nullable) id<CNXMapDelegate> mapDelegate;

/**
 *  Navigation delegate. See protocol for more details.
 */
@property (nonatomic, weak, nullable) id<CNXNavigationDelegate> navigationDelegate;


/**
 *  UIView sublass where map is rendered.
 */
@property (nonatomic, nullable) CNXMapView *mapView;

/**
 *  Map configuration details
 */
@property (nonatomic, nonnull) CNXMapConfig *mapConfig;

/**
 *  If map is loaded into memory, this will be set to YES
 */
@property (nonatomic) BOOL mMapIsLoaded;

/**
 *  You are able to set this property BEFORE loading a map, and route style will be changed. To change route style after that you need to unload and load again the map.
 */
@property (nonatomic) CNXRouteStlyeColor routeColorStyle;

/**
 *  If set YES, route instruction view will not switch to "close" version when you are less then 10ft to instruction position.
 */
@property (nonatomic) BOOL disableAutoSwitchRouteInstructionBannerToClose;

/**
 *  When you reach that treshold, baner will switch to "close" version
 */
@property (nonatomic) double autoSwitchRouteInstructionBannerToCloseTresholdInFeets;


/**
 *  Close route instruction color background. If nil, will be default green.
 */
@property (nonatomic, nullable) UIColor *closeRouteInstructionColor;

/**
 *  All map markers
 */
@property (nonatomic, nonnull) NSMutableArray *allMarkers;

/**
 *  Special kind of marker, which represents user's location on the map. This marker will not be removed with -(void)clearAllMarkers method.
 */
@property (nonatomic, nullable) CNXMapMarker *userLocationMarker;

/**
 *  All place objects in map
 */
@property (nonatomic, nullable) NSMutableArray *allPlaces;




/**
 *  Array of all markers user created and putted on map
 */
@property (nonatomic, nullable) NSMutableArray *allCustomMarkers;


/**
 *  Block which will be called when map is ready.
 */

@property (nonatomic, copy, nullable) void(^mOnMapLoadedBlock)(CNXMapManager* __nullable lMyViewController);

/**
 *  Currently loaded map.
 */
@property (nonatomic, nullable) CNXMap *currentMap;


/**
 *  Helper method to check map version strings
 *
 *  @param pVersion1 current map version
 *  @param pVersion2 comparing to map version
 *
 *  @return YES if first param is older then second
 */
+ (BOOL)isVersion:(nonnull NSString*)pVersion1 olderThan:(nonnull NSString*)pVersion2;


#pragma mark - Map configuration and bundle

/**
 *  Initialize MapManager from custom CNXConfig object and mapView
 *
 *  @param mapConfig Custom CNXConfig instance
 *  @param mapView   CNXMapView instance
 *
 *  @return NCXMapManager instance
 */
- (nonnull id)initWithConfigFile:(nonnull CNXMapConfig *)mapConfig andMap:(nonnull CNXMapView *)mapView;

/**
 *  Initialize MapManager from mapView
 *
 *  @param map CNXMap instance
 *
 *  @param mapView CNXMapView instance
 *
 *  @return CNXMapManager instance
 */
- (nonnull id)initWithMap:(nonnull CNXMap *)map andMapView:(nonnull CNXMapView *)mapView;

/**
 *  Initialize MapManager from mapView and using default map
 * *
 *  @param mapView CNXMapView instance
 *
 *  @return CNXMapManager instance
 */
- (nonnull id)initWithDefaultMapandMapView:(nonnull CNXMapView *)mapView;


/**
 *  Initialize MapManager just for finding places, without map
 *
 *  @return CNXMapManager instance
 */
- (nonnull id)initWithPlaceFinder;

/**
 *  Returns current language
 *
 *  @return NSString language
 */
+(nonnull NSString *)currentLanguage;

/**
 *  Loads map from app bundle
 *
 *  @return BOOL is map loaded
 */
- (BOOL)loadMap;

- (void)buildRouteSegments;

/**
 *  Uload map from memory
 */
- (void)unloadMap;

-(void)handleDidBecomeActive:(nullable id)sender;

-(void)handleWillResign:(nullable id)sender;


-(void)notifyDidReceiveMemoryWarning;

-(nonnull NSString*)vgVersion;

/**
 *
 * Preloads maps from local bundle or from the server
 *
 */
+ (void)prepareMapsForUse;


/**
 *  Version of the map
 *
 *  @return version as NSString object
 */
- (nonnull NSString *)getMapVersion;

/**
 *  Version of the map db
 *
 *  @return version as NSString object
 */
- (nonnull NSString *)getMapDbVersion;


/**
 *  Version of the mapKit framework
 *
 *  @return version as NSString object
 */
+ (nonnull NSString *)getMapKitVersion;

/**
 *  Set underneath layers visible. It MUST be set before loading a map.
 *
 *  @param visible      BOOL, visible or not
 *
 */
-(void)setLayersVisible:(BOOL)visible;


-(void)updateMapViewParameters;

#pragma mark - Camera and view setup

/**
 *  Set Camera position
 *
 *  @param location     CNXLocationCoordinate object
 *  @param pitch        pitchFloat
 *  @param layerName    layerName
 *  @param heading      heading
 *  @param animated     isAnimated
 */

-(void)setCameraLocation:(nonnull CNXLocationCoordinate *)location pitch:(double)pitch layerName:(nonnull NSString *)layerName andHeading:(double)heading animated:(BOOL)animated;

/**
 *  Set Camera position
 *
 *  @param location     CNXLocationCoordinate object
 *  @param animated     isAnimated
 */
-(void)setCameraLocation:(nonnull CNXLocationCoordinate *)location  animated:(BOOL)animated;


/**
 * @return CNXLocationCoordinate object with location
 */
-(nonnull CNXLocationCoordinate *)getCameraLocation;

/**
 * @return Camera pitch value
 */
-(float)getCameraPitch;

/**
 * @return Camera heading value
 */
-(float)getCameraHeading;

/**
 *  Show specific floor in the building
 *
 *  @param floor id of the floor
 *  @param viewMode of the CNXMapViewType (view mode of the map)
 */
- (void)showFloor:(nonnull NSString *)floor inViewMode:(CNXMapViewType)viewMode;

/**
 *  Show specific floor in the building
 *
 *  @param floor id of the floor
 *  @param viewMode of the CNXMapViewType (view mode of the map)
 *  @param animated BOOL - is floor change animated?
 */
- (void)showFloor:(nonnull NSString *)floor inViewMode:(CNXMapViewType)viewMode animated:(BOOL)animated;

/**
 *  Change view mode between multibuilding mode (Global), Building mode (single building) and floor view.
 *
 *  @param viewMode CNXMapViewType
 *  @param animated is change animated?
 */
- (void)changeViewModeTo:(CNXMapViewType)viewMode animated:(BOOL)animated;

/**
 *  Get current View mode
 *
 *  @return CNXMapViewType
 */
- (CNXMapViewType)viewMode;

/**
 *  Returns current active building for multibuilind maps
 *
 *  @return CNXMapBuilding
 */
-(nonnull CNXMapBuilding *)activeBuilding;

/**
 *  Changes active building for multibuilding map
 *
 *  @param building CNXMapBuilding object
 *  @param animated is change animated?
 */
-(void)setActiveBuilding:(nonnull CNXMapBuilding *)building animated:(BOOL)animated;

/**
 *  Returns all buildings on loaded map
 *
 *  @return array of CNXBuilding objects
 */
-(nonnull NSArray<CNXMapBuilding*>*)getAllBuildings;

#pragma mark - Route support


/**
 *  Draw route on the map
 *
 *  @param route CNXRoute instance
 */
- (void)drawRoute:(nonnull CNXRoute *)route;

/**
 *  Draw route on the map in segment mode view
 *
 *  @param route CNXRoute instance
 */
-(void)drawRoute:(nonnull CNXRoute *)route inSegmentMode:(BOOL)segmentMode;

/**
 *  Clear current route from the map
 */
- (void)clearRoute;

/**
 *  Returns current route
 *
 *  @return CNXRoute instance
 */
- (nullable CNXRoute*)currentRoute;


/**
 *  Contains information is auto routing paused or not
 */
@property (nonatomic) BOOL routeInProgress;


/**
 *  Here you can set route instruction banner style.
 */
@property (nonatomic) CNXRouteInstructionsStyle routeInstructionsStyle;


/**
 *  Hide specific route instruction on top, or show it back
 *
 *  @param flag YES means hide, NO means show it
 */
- (void)hideRouteInstructionsView:(BOOL)flag;

/**
 *  Show off route red banner animated
 */
-(void)showOffRouteBanner;


/**
 *  Hide off route red banner animated
 */
-(void)hideOffRouteBanner;

/**
 *  Show close instructions banner animated
 */
-(void)showCloseInstructionsBannerWithBackgroundColor:(nonnull UIColor * )color;

/**
 *  Hide close instructions banner animated
 */
-(void)hideCloseInstructionsBanner;

/**
 *  Update distance in feets on Instruction banner.
 */
-(void)updateFeetsOnInstructionsBanner:(nonnull NSNumber *)distanceInFeets;

/**
 *  Steps for current route
 *
 *  @return Array of steps
 */
- (nullable NSArray<CNXRouteStep *> *)getRouteSteps;

/**
 *  Goes to specific instruction in route
 *
 *  @param instructionIndex Index of the step
 */
- (void)gotoRouteInstruction:(int)instructionIndex;


/**
 *  List of segments for current route
 *
 *  @return Array of segments
 */
-(nonnull NSArray <CNXRouteSegment *> *)currentRouteSegments;

/**
 *  Moves to previous step in segment
 *
 *  @param animated is move animated?
 */
- (void)moveToPreviousStepInSegment:(BOOL)animated;

/**
 *  Moves to next step in segment
 *
 *  @param animated is move animated?
 */
- (void)moveToNextStepInSegment:(BOOL)animated;

/**
 *  Number of segments in this route
 *
 *  @return Integer of segments
 */
- (int)getTotalNumberOfSegments;


/**
 *  Get name of the layer from some location coordinate
 *
 *  @param locationCoordinate position on the map
 *
 *  @return Name of the layer, as a NSString object
 */
-(nullable NSString *)getLayerNameFromPosition:(nonnull CNXLocationCoordinate *)locationCoordinate;

/**
 *  Get name of the layer from some map id
 *
 *  @param mapId position on the map
 *
 *  @return Name of the layer, as a NSString object
 */
-(nonnull NSString *)getLayerNameFromMapId:(nonnull NSString *)mapId;


/**
 *  Get scene position for specific map id in runtime
 *
 *  @param mapId position on the map
 *
 *  @return CNXLocationCoordinate, scene
 */
-(nullable CNXLocationCoordinate *)getLocationFromMapId:(nonnull NSString *)mapId;

/**
 *  Will show route preview view on top of the screen
 *
 *  @param route object which is result of [CNXGeneralRouteBuilder build] method
 */
-(void)showRoutePreviewForRoute:(nonnull CNXGeneralRoute *)route;

/**
 *  Removes route preview view
 *
 */
-(void)hideRoutePreview;

/**
 *  Generates route segments for route leg
 */
-(nonnull NSArray <CNXRouteSegment *> *)getRouteSegmentsForRouteLeg:(nonnull CNXRouteLeg *)routeLeg;

/**
 *  Display route segment on the map
 */
-(void)showRouteSegmentOnMap:(nonnull CNXRouteSegment *)segment;

#pragma mark - Parking planner

/**
 *  Returns closest parking place from specific map id
 *
 *  @param mapId String which represents position on the map
 *
 *  @return CNXPlace object
 */
- (nullable CNXPlace *)getClosestParkingFromMapId:(nonnull NSString *)mapId;

/**
 *  Returns closest parking place from specific map id
 *
 *  @param location Location coordiante object which represents location on the object. Can be described in geolocation or scene location
 *
 *  @return CNXPlace object
 */
- (nullable CNXPlace *)getClosestParkingFromLocation:(nonnull CNXLocationCoordinate *)location;

/**
 *  Returns closest places (sorted array) from specific map id
 *
 *  @param listOfPlaces - List of CNXPlaces for sorting
 *  @param mapId - referent place on the map (mapID) from where you want to sort places by location distance
 *
 *  @return CNXPlace object
 */
- (nonnull NSArray <CNXPlace *> *)getSortedPlacesByDistanceInList:(nonnull NSArray *)listOfPlaces fromMapId:(nonnull NSString *)mapId;


/**
 *  Returns closest parking placec (sorted array) from specific map id
 *
 *  @param location Location coordiante object which represents location on the object. Can be described in geolocation or scene location
 *
 *  @return CNXPlace object
 */
- (nonnull NSArray <CNXPlace *> *)getSortedPlacesByDistanceInList:(nonnull NSArray *)listOfPlaces fromLocation:(nonnull CNXLocationCoordinate *)location;

#pragma mark - Marker support

/**
 *  Shows the current position marker on the map
 *
 *  @param location             Marker location on the map described as CNXPlace object
 *  @param animated          is marker change animated
 *  @param imageName         name of the image in main bundle
 */
- (void)showCurrentLocationMarkerFromLocation:(CNXLocationCoordinate *_Nullable)location animated:(BOOL)animated withImageNameFromMainBundle:(NSString *_Nullable)imageName;

/**
 *  Shows custom marker on the map
 *
 *  @param place             Marker location on the map described as CNXPlace object
 *  @param view              Custom UIVIew interface to be shown as Marker
 */
- (void)showMarkerOnPlace:(nonnull CNXPlace *)place withUIView:(nonnull UIView *)view;


/**
 *  Shows custom marker on the map with image
 *
 *  @param place             Marker location on the map described as CNXPlace object
 *  @param imageName         Image name with extension
 *  @param bundle            Bundle where image is. If it's nil, MainBundle will be used
 */
- (void)showMarkerOnPlace:(nonnull CNXPlace *)place withImageName:(nonnull NSString *)imageName inBundle:(nonnull NSBundle *)bundle;

/**
 *  Shows the current position marker on the map
 *
 *  @param location             Marker location on the map described as CNXLocationCoordinate object
 *  @param animated          is marker change animated
 */
- (void)showCurrentLocationMarkerFromLocation:(nonnull CNXLocationCoordinate *)location animated:(BOOL)animated;



/**
 *  Shows custom marker on the map
 *
 *  @param location          Marker location on the map described as CNXLocationCoordinate object
 *  @param view              Custom UIVIew interface to be shown as Marker
 */
- (void)showMarkerOnLocation:(nonnull CNXLocationCoordinate *)location withUIView:(nonnull UIView *)view;


/**
 *  Shows custom marker on the map with image
 *
 *  @param location             Marker location on the map described as CNXLocationCoordinate object
 *  @param imageName         Image name with extension
 *  @param bundle            Bundle where image is. If it's nil, MainBundle will be used
 */
- (void)showMarkerOnLocation:(nonnull CNXLocationCoordinate *)location withImageName:(nonnull NSString *)imageName inBundle:(nonnull NSBundle *)bundle;

/**
 *  Removes all markers (including XIB markers) from mapview
 *
 */
- (void)clearAllMarkers;

/**
 *  Removes all markers from mapview (but not POIs)
 *
 */
- (void)clearAllCustomMarkers;

/**
 *  Removes all UIView from mapview
 *
 */
-(void)clearAllUIMarkers;

#pragma mark - User location / blue dot handling


/**
 *  Set position of the marker, without animation
 *
 *  @param marker     CNXMapMarker object
 *  @param location   CNXLocationCoordinate object
 *  @param layerName  NSString layer name
 */
- (void)setPositionForMarker:(nonnull CNXMapMarker *)marker toLocation:(nonnull CNXLocationCoordinate *)location atLayer:(nonnull NSString *)layerName;


/**
 *  Set position of the marker, with animation
 *
 *  @param marker     CNXMapMarker object
 *  @param location   CNXLocationCoordinate object
 *  @param duration   animation duration in seconds
 */
- (void)animateMarker:(nonnull CNXMapMarker *)marker toLocation:(nonnull CNXLocationCoordinate *)location withAnimationDuration:(double)duration;

#pragma mark --
#pragma mark - Getter/setter methods

/**
 *  Returns config of the map from Preferences
 *
 *  @return CNXMapConfig instance
 */
- (nullable CNXMapConfig *)getMapConfigFromPreferences;



#pragma mark - Helper methods


/**
 *  Returns a nearest place for global coordinates, on specific floor
 *
 *  @return CNXPlace or nil
 */
-(nullable CNXPlace *)getNearestPlace:(CGFloat)lat andLng:(CGFloat)lon onFloor:(NSInteger)floor includingLandmarks:(BOOL)landmarks;


/**
 *  Returns a nearest place for local (sceene) coordinates, on specific floor
 *
 *  @return CNXPlace or nil
 */
-(nullable CNXPlace *)getNearestPlaceOnMap:(CGFloat)lat andLng:(CGFloat)lon altitude:(CGFloat)altitude;


-(nullable CNXPlace *)getNearestPlaceInDB:(nonnull CNXLocationCoordinate *)location;

/**
 *  Returns a nearest place from provided list of places, based on mapID
 *
 *  @return CNXPlace
 */
- (nonnull CNXPlace *)getClosestPlaceInList:(nonnull NSArray *)listOfPlaces fromMapId:(nonnull NSString *)mapId;

/**
 *  Returns a nearest place from provided list of places, based on location coordiante
 *
 *  @return CNXPlace or nil
 */
- (nonnull CNXPlace *)getClosestPlaceInList:(nonnull NSArray *)listOfPlaces fromLocation:(nonnull CNXLocationCoordinate *)location;


/**
 *  Converts Scene to GEO location (based on usingGeoCoordinates value in location)
 *
 *  @param location CNXLocationCoordinate instance
 *
 *  @return converter CNXLocationCoordinate instance
 */
-(nonnull CNXLocationCoordinate *)convertSceneLocationToGeoLocation:(nonnull CNXLocationCoordinate *)location;


/**
 *  Converts GEO location to Scene
 *
 *  @param location CNXLocationCoordinate instance
 *
 *  @return converter CNXLocationCoordinate instance
 */
-(nonnull CNXLocationCoordinate *)convertGeolocationToSceneLocation:(nonnull CNXLocationCoordinate *)location;


/**
 *  Calculates how long is the route between two locations on the map
 *
 *  @param location       starting location
 *  @param secondLocation final location
 *
 *  @return number of meters
 */
-(double)routingDistanceBetweenLocation:(nonnull CNXLocationCoordinate *)location andSecondLocation:(nonnull CNXLocationCoordinate *)secondLocation;

/**
 *  Calculates how long is the route between two locations on the map
 *
 *  @param place1       starting location
 *  @param place2       final location
 *
 *  @return number of meters
 */
-(double)routingDistanceBetweenPlace:(nonnull CNXPlace *)place1 andSecondPlace:(nonnull CNXPlace *)place2;


/**
 *  Returns the instruction Index according to the location
 *
 *  @param location     location
 *  @return index of the instruction step
 */
-(NSInteger)getInstructionIndexForLocation:(nonnull CNXLocationCoordinate *)location;

/**
 *  Returns the array of locations for all nodes in current route on the map
 *
 *  @return array of locations
 */
-(nonnull NSArray *)getAllNodeLocationsForCurrentRoute;

/**
 *  Returns the snapped to route location from the location given
 *  Ex: If one location is received from GPS, this method will return the location on the route that would
 *  best fit for the location received
 *
 *  @param location     location
 *  @return Snapped to route geo location
 */
-(nonnull CNXLocationCoordinate *) getSnappedGeoRouteLocationFromLocation:(nonnull CNXLocationCoordinate *)location;

/**
 *  Returns the heading for camera from 2 location
 *  @param fromLoc From location
 *  @param toLoc To location
 *  @return heading
 */

-(double) calcHeadingForDirectionFromCoordinate:(nonnull CNXLocationCoordinate *)fromLoc toCoordinate:(nonnull CNXLocationCoordinate *)toLoc;

/**
 *  Returns the altitude for layer/floor
 *  @param layerName Name of layer
 *  @return altitude
 */
-(double)getAltitudeForLayerWithName:(nonnull NSString *)layerName;

/**
 *  Returns the index for layer/floor
 *  @param layerName Name of layer
 *  @return index
 */
-(int)getLayerIndexFromLayerName:(nonnull NSString *)layerName;

// by CJS 03-08-2019
-(void) addPOIMarkerAtLayer:(nonnull NSString*)layer withImageName:(nonnull NSString *)imageNamed andPosition:(nonnull CNXLocationCoordinate *) location;
-(void) removeAllPoisFromMap;

// by CJS 06/17/2019 - to be able to have 0 distance places
// when a person is at the place, for example
- (NSArray < CNXPlace * > *_Nullable)getSortedPlacesByDistanceInWithZeroDistanceList:(nonnull NSArray *)listOfPlaces fromLocation:(nonnull CNXLocationCoordinate *)location;
@end
