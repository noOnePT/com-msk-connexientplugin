//
//  CNXANEvent.h
//  ConnexientSDK
//
//  Created by Curcio Jamunda Sobrinho on 27/12/16.
//  Copyright © 2016 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    CNXANEventOpenAPP=1,
    CNXANEventCloseAPP=2,
    CNXANEventOnViewController=3,
    CNXANEventGotoSearching=4,
    CNXANEventFindingARoute=5,
    CNXANEventBrowsingTheMap=6,
    CNXANEventShowingMarkerInMap=7,
    CNXANEventShowingRouteInMap=8,
    CNXANEventShowingGoogleMapsOutsideRoute=9,
    CNXANEventZoneEnter=10,
    CNXANEventZoneExit=11,
    CNXANEventFirstTimeUse=12,
    CNXANEventSearch=13,
    CNXANEventRouteStart=14,
    CNXANEventRouteEnd=15,
    CNXANEventSendToPhone=16,
    CNXANEventSaveMyCar=17,
    CNXANEventRetrnToCar=18,
    CNXANEventStarsRating=19,
    CNXANEventSend2Email=20,
    CNXANEventPrintDirections=21,
    CNXANEventGooglePlayDownloads=22,
    CNXANEventAppStoreDownloads=23,
    CNXANEventUncompletedRoute=24,
    CNXANEventOffroute=25,
    CNXANEventEmergencyContinueButton = 26
} CNXANEventType;


@interface CNXANEvent : NSObject<NSCoding>
@property (nonatomic) NSString *appID;
@property (nonatomic) NSString *clientID;
@property (nonatomic) CNXANEventType typeID;
@property (nonatomic) NSString *userID;
@property (nonatomic) NSDictionary *params;
@property (nonatomic) BOOL isProduction;
@property (nonatomic) NSTimeInterval eventUnixTime;
@property (nonatomic) NSString *eventCustomID;
@end
