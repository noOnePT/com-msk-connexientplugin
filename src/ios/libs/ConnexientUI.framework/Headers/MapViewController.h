//
//  ViewController.h
//  com.connexient.SDKAPP
//
//  Created by Curcio Jamunda Sobrinho on 15/12/15.
//  Copyright © 2015 CNX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ConnexientMapKit/ConnexientMapKit.h>
#import "SlideMenuController.h"
#import "SDKAPPUtils.h"
#import "SDKAPPMainSlideView.h"

@interface MapViewController : UIViewController
@property BOOL showFirstTime;
// when showing route
@property BOOL isInNavigationMode;
@property BOOL isInNavigationPreviewMode;
// it will have all places
@property (nonatomic) NSMutableDictionary *placesDic;
// the user location
@property CNXLocationCoordinate *myCurrentLocation;
@property CLLocation *googleGPSLocation;
@property BOOL isToShowProfile;
@property BOOL isToShowSaveMyCar;
// by CJS 12-18-2018
@property BOOL isToShowOutsideProfile;

// by Mladjan - to diferentiate parking
@property BOOL isShowingParkingCard;

//we need to know if it is from directory tile like Parking
@property BOOL isFromDirectory;
@property BOOL shouldPopWhenRouteIsDone;
@property BOOL returningToSavedCar;

// to be easier to use in other classes and avoid new object
@property CNXMapManager *mapManager;
@property (nonatomic) SDKAPPMainSlideView *profileView;
@property (nonatomic) SDKAPPMainSlideView *saveMyCarSlideView;

// by CJS 06-18-2018 - Just making this property public
@property int showingTheMapVC;

-(void) showGotoView:(BOOL) show;
-(void) showSearchView:(BOOL) show;
-(void) showGotoViewWithDelay;
-(void) setDestinationMarker:(SDKAPPExtendedMarker *)marker;
-(void) clearMap;
-(void) showInsideMap;
-(void) showMarkerOnMap:(SDKAPPExtendedMarker *)marker;
-(void) loadMap:(CNXMap *)map;
-(void) loadNewAppKey:(NSString *) appKey;
-(void) checkShowGoogleMaps:(BOOL) show completion:(void(^)(void))block;
-(void) didPressGotoButtonFromMarker:(SDKAPPExtendedMarker *)fromMarker toMarker:(SDKAPPExtendedMarker *)toMarker andMean:(SDKAPPMeanTransport) meanKind;
//save my car
-(void) saveMyCarWithMarker:(SDKAPPExtendedMarker *) marker;
-(void) showParkings;
-(void) reCreatePlacesDic;

// force google tracking
-(void) trackGooglePositioning;
-(void) leaveFullscreen;
-(void) checkToShowDelayedMarker:(SDKAPPExtendedMarker *)marker;
-(void) checkToDelayedRouteToMarker:(SDKAPPExtendedMarker *)marker;
-(void) callPreviewNavigation:(SDKAPPExtendedMarker *)fromMarker toMarker:(SDKAPPExtendedMarker *)toMarker andMean:(SDKAPPMeanTransport) meanKind;
// by CJS 03-21-2019
-(void) hideAllRouteElements;
-(void) didSelectMarker:(SDKAPPExtendedMarker *) marker isSource:(BOOL)isSource;
@end
