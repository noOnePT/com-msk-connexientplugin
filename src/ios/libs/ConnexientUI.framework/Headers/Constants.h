//
//  Constants.h
//  com.connexient.SDKAPP
//
//  Created by Curcio Jamunda Sobrinho on 16/12/15.
//  Copyright © 2015 CNX. All rights reserved.
//
#import "DejalActivityView.h"
#import <ConnexientKit/CNXSQLite.h>
#import <ConnexientMapKit/CNXMapLocalManager.h>

#ifndef Constants_h
#define Constants_h

// iOS version
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define SCREEN_HEIGHT [[UIScreen mainScreen] bounds].size.height
#define SCREEN_WIDTH [[UIScreen mainScreen] bounds].size.width
#define kSQLiteLocalDBFileName @"local.db"
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue] // float
// by CJS - translation
#define CNXTranslateString(key) [[NSBundle bundleWithIdentifier: @"com.connexient.ConnexientUI"] localizedStringForKey:(key) value:@"" table:nil]

#define ALog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)



// iOS version
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

#define IS_IPHONE_5 (IS_IPHONE && [[UIScreen mainScreen] bounds].size.height == 568.0f)
#define IS_IPHONE_4 (IS_IPHONE && [[UIScreen mainScreen] bounds].size.height == 480.0f)

//RGB color macro

#define UIColorFromRGB(rgbValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define DISABLED_COLOR [UIColor lightGrayColor];
#define ENABLED_COLOR UIColorFromRGB(0x384ad1);

//RGB color macro with alpha
#define UIColorFromRGBWithAlpha(rgbValue,a) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:a]

typedef NS_ENUM(NSInteger, SDKAPPMeanTransport){
    MeanTransportFoot = 3,
    MeanTransportCar = 1,
    MeanTransportShuttle = 4,
    MeanTransportBus = 5,
    MeanTransportTransit = 2
};

// VG Map Params
#define kCameraAltitudeForDropPin 40.0
#define kCameraAltitudeForBubble 2.5
#define kCameraAltitudeForHotspotSelector 5.0
#define kCameraPitch -90.0
#define kKioskCameraPitch -87.0
#define kCameraHeading 200
#define kCameraAltitudeForDrawRoute 30.0

#define kMapTabIndex 2
#define kHomeTabIndex 0
#define kGoToTabIndex 3

// Hospital Coordinates

#define kApplicationDidTimeoutNotification @"AppTimeOut"
#define kApplicationPopMailClientNotification @"PopMailClient"

#define kSQLiteLocalDBFileName   @"local.db"
#define kSQLiteImageOfflineDB @"images.db"
#define kSQLiteImageDB @"landmarks.db"
#define kSQLiteQueryDB @"queries.db"
#define kSQLiteStaffDB @"staff.db"

#define SURVEY_BASE_URL @"https://analytics-dev.connexient.com"
#define SURVEY_GENERATOR @"survey-generator/show"
#define SURVEY_WELCOME @"api/welcome-offer"
#define SURVEY_INFO @"api/survey"

#define FEEDS_BASE_URL @"https://cxtadmin-dev.connexient.com"
#define NEWS_GENERATOR @"news/generator"

#define kGoogleMapAppID @"AIzaSyCgoI2w7zSS0CWpyvukb2_tch_iaH7k7-A" // changed per Nev email on Oct/10/18 old => @"AIzaSyDRboS849O0tv86s1jLYyBJOji-xGsUlqY"
#define kGoogleMapAppClientID @"gme-connexient"
#define kGoogleMapAppSignature @"eSlOYXy_EJugPo3gI_cnb-qK2xA="
#define GOOGLE_MAPS_URL @"https://www.google.com/maps/dir"
#define kDirectionsURL [NSString stringWithFormat:@"https://maps.googleapis.com/maps/api/directions/json?key=%@&", kGoogleMapAppID]
#define kGoogleMainApiURL @"https://maps.googleapis.com"

// Query DB identify
#define kModelStaffDB @"medinav3-staff"
#define kModelSDKDB @"medinav3-sdk"

// Sign Up
#define ACTION_SIGN_UP @"signup_smh"
#define ACTION_SIGN_IN @"signin_smh"
#define ACTION_SIGN_IN_KIOSK @"signin_new_smh"
#define ACTION_SIGN_OUT @"signout_smh"
#define ACTION_FORGOT_PASSWORD @"forgot_password_smh"
#define ACTION_UPDATE_PROFILE @"update_user_details_smh"
#define ACTION_CHANGE_PASSWORD @"change_password_smh"
#define ACTION_EMAIL_ME @"mobile_app_smh"
#define ACTION_SAVE_FAVORITE @"save_user_favorites"
#define ACTION_DELETE_FAVORITE @"del_user_favorites"
#define ACTION_GET_HOTSPOT_FAVORITE_LISTING @"get_all_user_favorites"
#define ACTION_GET_EMAIL_APP_LINK @"send_download_email"
#define ACTION_GET_DB_UPDATE_TIME @"get_dbUpdateTime"
#define ACTION_GET_DB_CHECKSUM @"get_db_checksum"
#define ACTION_POST_SEND_EMAIL @"send_email"
#define ACTION_SEND_ROUTE_SEGMENT_SMS @"send_sms"
#define ACTION_SEND_FILE_FOR_SMS @"save_pdf"

// by CJS
#define ACTION_GET_LAST_TWEETS @"get_last_tweets"
#define ACTION_SEND_PDF @"send_pdf_web"
#define ACTION_ADD_LANDMARK @"add_landmark"
#define ACTION_REMOVE_LANDMARK @"remove_landmark"
#define ACTION_ADD_IMAGE @"add_image"

#define kInstructionViewSelectedType @"instructionViewType"
#define kInstructionViewRefresh @"instructionViewRefresh"
#define kRoutePathSelectedType @"kRoutePathSelectedType"
#define kLocationKitSyncDisable @"kLocationKitSyncDisable"
#define kCurrentLocationDotImage @"kCurrentLocationDotImage"
#define kDestinationMapId @"kDestinationMapId"
#define kRoutePathRefresh @"kRoutePathRefresh"
#define kNavigationDoNotShowAgain @"kNavigationDoNotShowAgain"
#define kShowNavigationHintWithLandmark @"kShowNavigationHintWithLandmark"
#define kAddThisLandmarkToMap @"kAddThisLandmarkToMap"
#define kApplicationDidBecomeActive @"kApplicationDidBecomeActive"
#define kInitialScreen @"kInitialScreen"

#define kNewCampusSelected @"kNewCampusSelected"
#define kMapLoaded @"kMapLoaded"

#define kCarWasSaved @"kCarWasSaved"

// show dejal
#define DEJALVIEW_SHOW(view, title)           [DejalBezelActivityView activityViewForView:view withLabel:title]
#define DEJALVIEW_DISMISS                     [DejalBezelActivityView removeViewAnimated:YES]


//////
// DEFAULT VALUES
//////
#define ENABLE_CHANGE_KEY 0
//////

#define MEETME_APP_NAME @"rush" // remember to set for target and have the same on plist -> CFBundleURLName and CFBundleURLSchemes
#warning TODO: Change meetme constant

#endif /* Constants_h */
