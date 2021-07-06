//
//  SDKAPPUtils.h
//  com.connexient.SDKAPP
//
//  Created by Curcio Jamunda Sobrinho on 04/01/16.
//  Copyright © 2016 CNX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ConnexientKit/CNXLocationCoordinate.h>
#import "SDKAPPExtendedMarker.h"
#import "Constants.h"
#import <ConnexientKit/CNXConstants.h>
#import <CoreLocation/CoreLocation.h>

@interface SDKAPPUtils : NSObject
+ (double)returnDistanceFromCoordinate:(CNXLocationCoordinate *)sourceCoordinate toCoordinate:(CNXLocationCoordinate *)resultCoordinate;
+ (int)convertToInt:(CNXSearchByType)type;
+ (NSString*)searchIconByType:(CNXPlaceLocationType)type;
+ (CNXSearchByType)convertToCNXSearchByType:(int)type;
+ (NSString *)searchByTypeEnumToString:(CNXPlaceLocationType)type;


+ (BOOL)autodetectLocation;
+ (void)setAutodetectLocation:(BOOL)newValue;

+ (NSInteger)lastDBUpdatedTime;
+ (void)setLastDBUpdatedTime:(NSInteger)time;

+ (void)setDefaultTabBarController:(UITabBarController *)tabBarController;
+ (BOOL)didAskAutodetectQuestion;
+ (void)setDidAskAutodetectQuestion:(BOOL)newValue;
+ (BOOL)navigationHintWindow;
+ (void)setNavigationHintWindow:(BOOL)newValue;
+ (void)loadDefaultConstans;

+ (id)instantiateViewController:(NSString*)controllerName fromStoryboard:(NSString*)boardName;
+(NSString *)convertToDayFromInteger:(int)day;
+(NSString *)makeCorrectPhoneNumberFromString:(NSString *)phone;

// by CJS
+ (NSString*)allSizesIconByType:(int)type;
+ (NSString*)outsidePOIIconByType:(int)type ;
+ (NSString*)insidePOIImageName:(CNXPlaceLocationType)type;
+ (NSString*) insidePOINameForType:(CNXSearchByType) type;
+ (BOOL) isFirstTimeLaunched;
+ (UIImage *)getOutsidePOIImageForSearchType:(CNXSearchByType)type;
+(NSString *) convertSecsToTime:(long)secs;
+(double) returnFeetFromMeters:(double)meters;
+(double) returnMilesFromMeters:(double)meters;
+(int) returnRoundedFeetFromMeters:(double)meters;
+(int) returnRoundedDistanceUnit:(double)unit;
+ (UIImage *) returnImageForRouteManuever:(CNXManeuverType)manuver white:(BOOL)white;

+(int) returnFloorForAltituteAccordingToCMSFloor:(double) altitute;
+(NSString *) returnFloorIDForAltituteAccordingToCMSFloor:(double) altitute;
+(NSString *) returnVGFloorLayerForAltituteAccordingToCMSFloor:(double) altitute;
+(NSString *) returnVGFloorAbbreviationForAltituteAccordingToCMSFloor:(double) altitute;
+(NSString *) returnVGFloorIDForAltituteAccordingToCMSFloor:(double) altitute;

// multi building
+(NSString *) returnVGFloorIDForAltituteAccordingToCMSFloor:(double) altitute buildingID:(int) buildingID;
+(NSString *) returnFloorAbbreviationForAltituteAccordingToCMSFloor:(double) altitute buildingID:(int) buildingID;
+(void) cleanFloorDic;
+ (double)returnRouteDistanceFromCoordinate:(CNXLocationCoordinate *)sourceCoordinate toCoordinate:(CNXLocationCoordinate *)resultCoordinate;

+(BOOL) isCoordinate:(CNXLocationCoordinate *)coordinate insideTopLeftCoordinate:(CNXLocationCoordinate *)topLeft andBottomRight:(CNXLocationCoordinate *)bottomRight;
+(BOOL) isInsideNIH:(CNXLocationCoordinate *) coordinate;
+(CLLocationCoordinate2D) returnMediumCLLLocationCoordinate2DFromArrayOfCNXLocationCoordinates:(NSArray <CNXLocationCoordinate *> *) coordinates;
+(CNXLocationCoordinate *) returnMediumCNXLocationCoordinateFromArrayOfCNXLocationCoordinates:(NSArray <CNXLocationCoordinate *> *) coordinates;
+(BOOL) isCoordinate:(CNXLocationCoordinate *)coordinate insideArrayOfCoordinates:(NSArray <CNXLocationCoordinate *> *)arrayCoordinates;
+(double) calcHeadingForDirectionFromCoordinate:(CNXLocationCoordinate *)fromLoc toCoordinate:(CNXLocationCoordinate *)toLoc;

// to control buttons, need to add didPressMenu: on yout VC for it to work
+(void) checkNavigationController:(__weak UIViewController *) controller;

// example #ffffff
+(unsigned) returnIntForColorString:(NSString *) colorString;
+(UIColor *) returnUIColorForColorString:(NSString *)colorString;

// image
+ (UIImage *)getImageFromURL:(NSString *)imageURL;

+(UIImage *)imageByScalingProportionallyToSize:(CGSize)targetSize image:(UIImage *)chosenImage;

+ (NSString *)encodeToBase64String:(UIImage *)image;

+ (NSString *)encodeToJPG30ThenBase64String:(UIImage *)image;

+ (UIImage *)decodeBase64ToImage:(NSString *)strEncodeData;

+ (UIImage *)encodeToJPG30:(UIImage *)image;

+ (CGSize)labelSize:(UILabel*)label usingBoundingRect:(CGRect)boundingRect;

// to check if user is inside Beacon range or not - if not, he is outside
// we check at the moment of the call, maybe we get GPS and then we return NO
+ (BOOL)isUserInBeaconRange;

// the last user known within 10 sec or nil if longer
+ (CNXLocationCoordinate *) lastKnownUserLocation;

+(void) showErrorMsg:(NSString *) message inController:(__weak UIViewController *) vc;

// by CJS 06-06-2018 - to remove google maps limit usage
+(NSString *) returnEncodedStringWithString:(NSString *) string withKey:(NSString *) key;

+ (CGFloat)getTextHeightForText:(NSString*)text withFont:(UIFont*)font andWidth:(float)width;
+ (CGFloat)getTextWidthForText:(NSString*)text withFont:(UIFont*)font;

+ (NSString*)getLocalizedLabel:(NSDictionary *)item forPath:(NSString*)path;
+ (NSString*)getLanguage;

+ (NSArray *)loadLocationTypes;
+ (BOOL)isUserInsideParkingBuilding;
+ (BOOL)isUserInsideTheCurrentCampus;
+ (NSDictionary *) termsAndConditionData;
+ (NSDictionary *) privacyData;
@end
