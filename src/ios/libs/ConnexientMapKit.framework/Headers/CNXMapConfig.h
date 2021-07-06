//
//  CNXMapConfig.h
//  ConnexientSDK
//
//  Created by Fabian Fermin Guerra Soto on 11/29/13.
//  Copyright (c) 2013 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  @brief config class for MapView which contains details about map configuration and license
 */
@interface CNXMapConfig : NSObject

/**
 *  Secred of the map
 */
@property (nonatomic) int mapSecret;


/**
 *  URL of the configuration file for the map
 */
@property (nonatomic, nonnull) NSString *mapConfigurationFile;

/**
 *  Map license URL
 */
@property (nonatomic, nonnull) NSString *mapLicenseURL;

/**
 *  Version of the map
 */
@property (nonatomic, nonnull) NSString *mapVersion;


/**
 *  Init CNXMapConfig
 *
 *  @param secret            secret of the map
 *  @param configurationFile Map configuration file URL
 *  @param licenseURL        Map license file URL
 *  @param version           version of the map
 *
 *  @return CNXMapConfig instance
 */
- (id _Nonnull)initWithSecret:(int)secret configFile:(nonnull NSString *)configurationFile licenseURL:(nonnull NSString *)licenseURL andVersion:(nonnull NSString *)version;

@end
