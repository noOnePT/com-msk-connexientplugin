//
//  CNXCore.h
//  ConnexientSDK
//
//  Created by Mladjan Antic on 9/17/15.
//  Copyright © 2015 Connexient. All rights reserved.
//



#import <Foundation/Foundation.h>
#import "CNXConstants.h"

/**
 *  @brief Core framework manager which is used for initial framework setup
 */
@interface CNXCore : NSObject

@property (nonatomic) BOOL debug DEPRECATED_ATTRIBUTE;

/**
 *  To stop updating preloading data, set it to YES
 */
// Deprecated -- use CNXSyncUpdateMethod below ---
// by Enabling this property you get the same effect as CNXSyncUpdateMethodNone
@property (nonatomic) BOOL doNotUpdatePrelaodedMapAndData DEPRECATED_ATTRIBUTE;


/**
 *  To control the sync method
 *  Default is CNXSyncUpdateMethodAuto
 */
@property (nonatomic) CNXSyncUpdateMethod syncUpdateMethod;

/**
 *  SDK Environment
 */
@property (nonatomic) CNXSDKEnvironment currentEnvironment;


+(nonnull NSString *)getCoreKitVersion;

/**
 *  App key you got from Connexient
 */
@property (nonatomic, strong, nonnull) NSString *appKey;


/**
 *  Completion block which will be called when SDK is ready
 */
@property (nonatomic, copy, nullable) void (^completitionBlock)(NSError * _Nullable error );


/**
*  Completion block which will be called when MeetMe link should be generated on Firebase Dynamic links
*/
@property (nonatomic, copy, nullable) void (^meetMeCompletitionBlock)(NSString * _Nonnull message,  NSString * _Nonnull url, UIViewController  * _Nonnull sender);

/**
 * ClientID for AnalyticsKit
 */
@property (strong, nonatomic, nullable) NSString *analyticsClientID;

/**
 *  Checks is license valid or not
 */
-(BOOL)isLicenseValid;

/**
 *  Shared instance
 *
 *  @return Returns the Connexient singleton object.
 */
+ (nonnull id)sharedManager;

/**
 *  Returns current language
 *
 *  @return NSString language
 */
+(nonnull NSString *)currentLanguage;

/**
 *  This is initial setup method for initializing the Core framework. This is required before using other frameworks (short version). It will use default db name provided by SDK API.
 *
 *  @param appKey Application key you got from Connexient
 */
-(void)setupWithAppKey:(nonnull NSString *)appKey;

/**
 *  This is initial setup method for initializing the Core framework. This is required before using other frameworks (short version). It will use default db name provided by SDK API. You are able to set debug to YES and use development servers.
 *
 *  @param appKey Application key you got from Connexient
 */
-(void)setupWithAppKey:(nonnull NSString *)appKey inDebugMode:(BOOL)debug DEPRECATED_ATTRIBUTE;

/**
 *  This is initial setup method for initializing the Core framework. This is required before using other frameworks (short version). You will be able to chose between Development, Staging and Production
 *
 *  @param appKey Application key you got from Connexient
 */
-(void)setupWithAppKey:(nonnull NSString *)appKey inEnvironment:(CNXSDKEnvironment)environment;


/**
 *  Checks does your license has TextToSpeech feature available
 *
 *  @return Returns YES or NO.
 */
-(BOOL)isTextToSpeechAvailable;

/**
 Checks if app has embedded optional map and license

 @return YES or NO
 */
-(BOOL)appHasEmbeddedMapAndLicense;



/**
 Checks if app has some map to load

 @return YES or NO
 */
-(BOOL)appHasInstalledAnyMaps;


@end
