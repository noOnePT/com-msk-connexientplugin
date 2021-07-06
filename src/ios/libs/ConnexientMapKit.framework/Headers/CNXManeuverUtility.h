//
//  CNXManeuverUtility.h
//  ConnexientSDK
//
//  Created by Fabian Fermin Guerra Soto on 2/17/15.
//  Copyright (c) 2015 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientKit/CNXConstants.h>


/**
 *  @brief Helper for route maneuvers
 */
@interface CNXManeuverUtility : NSObject

/**
 *  Returns name of the image for specific maneuver type
 *
 *  @param maneuverType maneuver type integer
 *
 *  @return image name
 */
+ (nullable NSString*)getManeuverImageString:(unsigned int)maneuverType;


/**
 *  Returns CNXManeuverType enum based on maneuver type int
 *
 *  @param maneuverType maneuver type int
 *
 *  @return CNXManeuverType enum
 */
+ (CNXManeuverType)getManeuverType:(unsigned int)maneuverType;

@end
