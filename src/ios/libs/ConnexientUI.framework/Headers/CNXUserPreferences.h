//
//  CNXUserPreferences.h
//  Stanford
//
//  Created by Fabian Fermin Guerra Soto on 2/18/14.
//  Copyright (c) 2014 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
@class SDKAPPExtendedMarker;
@interface CNXUserPreferences : NSObject

+ (CNXUserPreferences *)sharedStore;

- (void)saveSelectedLandingView:(NSMutableArray *)landingView;
- (NSMutableArray *)selectedLandingView;

- (void)saveSelectedDefaultMap:(NSMutableArray *)defaultMap;
- (NSMutableArray *)selectedDefaultMap;

- (void)saveSelectedPOI:(NSMutableArray *)poi;
- (NSMutableArray *)selectedPOI;

- (void)saveDefaultFloor:(NSString *)floorID;
- (NSString *)defaultFloor;

- (void)saveSurveyToken:(NSString *)token;
- (NSString *)sessionToken;

- (void)savePromptsAndNotification:(NSMutableArray *)prompts;
- (NSMutableArray *)promptsAndNotification;

- (void)saveEnableLocationServicesIndoor:(BOOL)val;
- (BOOL)enableLocationServicesIndoor;

- (void)saveEnableLocationServicesOutdoor:(BOOL)val;
- (BOOL)enableLocationServicesOutdoor;

- (void)saveHandicapAccess:(NSString *)startPointID;
- (NSString *)handicapAcess;

- (void)synchronize;

- (void)promptListWithCompletionHandler:(void(^)(NSArray *searchResults, NSError *error))handler;

- (void)saveParkingLocation:(SDKAPPExtendedMarker *)parking;
- (void)saveDefaultStartPoint:(NSString *)startPointID;
- (NSString *)defaultStartPoint;

- (SDKAPPExtendedMarker *)loadParkingLocation;
- (void) deleteParkingLocation;
- (void)saveLastDestination:(SDKAPPExtendedMarker *)parking;
- (SDKAPPExtendedMarker *)loadLastDestination;

- (void)saveVoiceTurnedON:(BOOL)val;
- (BOOL)voiceTurnedON;

@end
