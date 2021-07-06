//
//  CNXWayPoint.h
//  Stanford
//
//  Created by Curcio Jamunda Sobrinho on 27/10/15.
//  Copyright © 2015 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SDKAPPExtendedMarker;

@interface CNXWayPoint : NSObject
@property (nonatomic) double latitude;
@property (nonatomic) double longitude;
@property (nonatomic) NSString *address;
@property (nonatomic) NSInteger wayPointID;
@property (nonatomic) NSInteger hospital_hotspot_id;

// by CJS 01/17-2016
@property (nonatomic) NSInteger fallback_wayPointID;

// by CJS 11/05/2018 - https://connexient.atlassian.net/browse/MEDINAV3-944
@property (nonatomic) NSString *mapID;
@property (nonatomic) NSString *routeStartMsg;
@property (nonatomic) NSString *routeEndMsg;
@property (nonatomic) SDKAPPExtendedMarker *waypointPlace;
@property BOOL isToAddInTheRoute;
@property (nonatomic) NSString *takeMeToRegistrationText;
@property (nonatomic) NSString *alreadyRegisteredText;
@end
