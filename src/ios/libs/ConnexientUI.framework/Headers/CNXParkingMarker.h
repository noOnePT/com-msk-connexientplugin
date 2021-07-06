//
//  CNXParkingMarker.h
//  Stanford
//
//  Created by Curcio Jamunda Sobrinho on 23/11/15.
//  Copyright © 2015 Connexient. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <ConnexientKit/CNXPlace.h>

@interface SDKAPPParkingChild :NSObject
@property (nonatomic) NSString *labelName;
@property (nonatomic) NSString *shownName;
@property (nonatomic) NSString *mapID;
@property (nonatomic) NSArray <SDKAPPParkingChild *> *rows;
@property (nonatomic) SDKAPPParkingChild *parkingChild;
@end

@interface CNXParkingMarker : CNXPlace
@property (nonatomic) BOOL isPreferedParking;
@property (nonatomic) double distanceToIndoorSwitch;
@property (nonatomic) BOOL isSavedMyCarLocation;
@property (nonatomic) SDKAPPParkingChild *parkingChild;
@end
