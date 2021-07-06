//
//  SlideMenuViewController.h
//  com.connexient.SDKAPP
//
//  Created by Curcio Jamunda Sobrinho on 15/12/15.
//  Copyright © 2015 CNX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SlideMenuController.h"

typedef NS_ENUM(NSInteger, CNXMedinavInitialScreen) {
    CNXMedinavInitialScreenMap,
    CNXMedinavInitialScreenDirectory,
    CNXMedinavInitialScreenStaffSearch,
    CNXMedinavInitialScreenPlace
};

@interface SDKAPPSlideMenuViewController : UIViewController

// Delayed entry points
@property (nonatomic) BOOL showScreenAfterDelay;
@property (nonatomic) CNXMedinavInitialScreen screenToShowAfterDelay;
@property (nonatomic) NSString *mapIDToShowAfterDelay;

-(void) forceRefresh;
-(void) showDirectoryScreen;
-(void) showMapScreen;
-(void) showStuffSearchScreen;
-(void) showSpecificMapId:(NSString *)mapID;
-(void) showTargetScreen:(NSString*)target;
-(void) didPressCampusLocations:(id)sender;
-(void)showDirectoryScreenAfterMapLoaded;
-(void)showMapScreenAfterMapLoaded;
-(void)showSpecificMapIdAfterMapLoaded:(NSString *)mapID;
-(void)showStuffSearchScreenAfterMapLoaded;
-(void)checkForEmergencyAlert;
@end
