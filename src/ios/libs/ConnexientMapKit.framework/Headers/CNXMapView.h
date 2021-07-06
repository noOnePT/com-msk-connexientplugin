//
//  CNXMapView.h
//  ConnexientMapKit
//
//  Created by Mladjan Antic on 2/8/18.
//  Copyright © 2018 Connexient. All rights reserved.
//



#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PointOfInterest) {
    PointOfInterestRestrooms,
    PointOfInterestElevator,
    PointOfInterestParking,
    PointOfInterestATM,
    PointOfInterestVendingMachine,
    PointOfInterestDining,
    PointOfInterestShopping
};


@class CNXMarker;
@class CNXCamera;
@class VgEAGLView;
@class CNXMapManager;

/**
 *  @brief Represents map canvas
 */
@interface CNXMapView : UIView

@property (nonatomic, nullable) VgEAGLView *cpp;

@property (weak, nullable) CNXMapManager *mapManager;

/**
 *  Returns screenshot of the map view
 *
 *  @return UIImageView screenshot
 */
- (nonnull UIImage *)captureToImage;

/**
 *  This needs to be called after load map if you are not using init from storyboard!
 */
- (void)startAnimation;

/**
 *  This will schedule render of the map if you have need to force the render
 *
 *  @param onDemand on demand
 */
- (void)setRenderOnDemand:(BOOL)onDemand;

@end

