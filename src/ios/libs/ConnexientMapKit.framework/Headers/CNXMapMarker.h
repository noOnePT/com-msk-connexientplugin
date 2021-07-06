//
//  CNXMapMarker.h
//  ConnexientDemo
//
//  Created by Mladjan Antic on 5/4/16.
//  Copyright © 2016 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ConnexientKit/CNXLocationCoordinate.h"

@class VgEAGLView;


@interface CNXMapMarker : NSObject

typedef NS_ENUM(NSInteger, CNXMapMarkerOrientation) {
    CNXMapMarkerOrientationHorizontal,
    CNXMapMarkerOrientationVertical
};
/**
 *  Location of the marker. CNXLocationCoordinate knows is it scene or geo referenting system
 */
@property (nonatomic, nonnull) CNXLocationCoordinate *locationCoordinate;

/**
 *  Map marker can be represented with UIView also
 */
@property (nonatomic, nullable) UIView *markerView;

/**
 *  Name of the map layer (floor)
 */
@property (nonatomic, nonnull) NSString* layerName;

/**
 *  This block of the code will be executed when you touch CNXMapMarker
 */
@property (nonatomic, nullable) void (^onTouch)(void);

/**
 *  User defined data, its nil by default and SDK is never populating this property
 */
@property (nonatomic, nullable) id data;

/**
 *  Initializer for CNXMapMarker using UIImage
 *
 *  @param locationCoordinate location of the marker
 *  @param mapView            map we are putting marker on
 *  @param imageName          image name of the marker (example: marker.png)
 *  @param bundle             If your image is located in some other bundle
 *  @param layerName          layer name of the map (floor)
 *  @param scale              Scale of the marker, default is 1.0
 *  @param orientation        Horizontal or vertical
 *  @param drawOnTop          Is Marker drawn on top of the other objects?
 *
 *  @return CNXMapMarker instance which can be used to move it or remove it from the map
 */
- (nonnull CNXMapMarker *)initWithLocation:(nonnull CNXLocationCoordinate *)locationCoordinate mapView:(nonnull VgEAGLView *)mapView markerImageName:(nonnull NSString *)imageName inBundle:(nonnull NSBundle *)bundle andLayer:(nonnull NSString *)layerName scale:(float)scale orientation:(CNXMapMarkerOrientation)orientation drawOnTop:(BOOL)drawOnTop;

/**
 *  Initializer for CNXMapMarker using UIImage
 *
 *  @param locationCoordinate location of the marker
 *  @param mapView            map we are putting marker on
 *  @param imageName          image name of the marker (example: marker.png)
 *  @param bundle             If your image is located in some other bundle
 *  @param layerName          layer name of the map (floor)
 *
 *  @return CNXMapMarker instance which can be used to move it or remove it from the map
 */
- (nonnull CNXMapMarker *)initWithLocation:(nonnull CNXLocationCoordinate *)locationCoordinate mapView:(nonnull VgEAGLView *)mapView markerImageName:(nonnull NSString *)imageName inBundle:(nonnull NSBundle *)bundle andLayer:(nonnull NSString *)layerName;

/**
 *  Initializer for CNXMapMarker using UIView instead of image
 *
 *  @param locationCoordinate location of the marker
 *  @param markerView         UIView instance
 *
 *  @return CNXMapMarker instance which can be used to move it or remove it from the map
 */
- (nonnull CNXMapMarker *)initWithLocation:(nonnull CNXLocationCoordinate *)locationCoordinate andMarkerView:(nonnull UIView *)markerView;


/**
 *  Hides marker on the map
 */
- (void)hideMarker;

/**
 *  Shows marker back if its hidden
 */
- (void)showMarker;

/**
 *  Change position of the marker to a new position and layer
 *
 *  @param location  location of the marker
 *  @param layerName layer name of the map (floor)
 */
- (void)setPositionForMarkerToLocation:(nonnull CNXLocationCoordinate *)location atLayer:(nonnull NSString *)layerName;

/**
 *  Change position of the marker to a new position and layer, with animation
 *
 *  @param location  location of the marker
 *  @param layerName layer name of the map (floor)
 *  @param duration  animation duration in seconds
 */
- (void)animateMarkerToLocation:(nonnull CNXLocationCoordinate *)location atLayer:(nonnull NSString *)layerName withAnimationDuration:(double)duration;


@end
