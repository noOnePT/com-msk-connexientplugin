//
//  SDKAPPExtendedMaker.h
//  com.connexient.SDKAPP
//
//  Created by Curcio Jamunda Sobrinho on 31/05/16.
//  Copyright © 2016 CNX. All rights reserved.
//

#import "CNXParkingMarker.h"
#import "SDKAPPProfileCMS.h"
#import "CNXWayPoint.h"
/*
 * This values comes from Way.db entity hotspot_types
 // * For each change convertToInt and convertToCNXSearchByType must be updated.
 */
enum CNXSearchByType {
    SearchByDepartment=1,
    SearchByInformationDesk=29,
    SearchByStaff=503,
    SearchByAllStaff=500,
    SearchByRoom=2,
    SearchByParkingGarage=7,
    SearchByShopping=11,
    SearchByDining=16,
    SearchByBanksATM=10,
    SearchByElevator=15,
    SearchByRestroom=9,
    SearchByConferenceRoom=13,
    SearchByPOVPhotos = 17,
    SearchBySpecialities=501,
    SearchByDepartmentWithRooms=30,
    SearchByRoute=40,
    SearchByKiosk=19,
    SearchByExit=4,
    SearchByMyPlace=100,
    SearchByClinicalDepartment=51,
    SearchByClinic=52,
    SearchByHotel=57,
    SearchByCourtyard=58,
    SearchByHospitality=59,
    SearchByParkingPayStation=20,
    SearchByBikeRake=55,
    SearchByStair=22,
    SearchByVendingMachine=21,
    SearchByPOI=1000,
    SearcyByNursingUnit=60,
    SearchByPointOfInterest=61,
    SearchByEmergencyDepartment=62,
    SearchBySurgicalSuit=63,
    SearchByAncillaryDepartment=64,
    SearchByShuttle=65,
    SearchByOutsideHotel=37,
    SearchByBuilding=75,
    SearchByBusStop=76,
    SearchBySecurity=77,
    SearchByParking=25, // check later
    SearchByPatientCareUnit=78,
    SearchByOutsideBuilding=75,
    SearchByOutsideStamfordHospital=70,
    SearchByOutPatient=71,
    SearchByImagingDiagnostic=72,
    SearchByUrgentCare=73,
    SearchByLabLaw=74,
    SearchByPharmacy=12,
    SearchCommunityBasedService=35,
    SearchPlaceOfWorship=36,
    SearchRehabService=38,
    SearchByLibrary=39,
    SearchByOutsideMarker=502,
    SearchByPatientTravel=80,
    SearchByTransportation=82,
    SearchByLobby=81,
    SearchByPostalBox=83,
    SearchByCashierVoucher=90,
    SearchByPatientService=5,
    SearchByMacSuit=95,
    SearchByHealthCare=30,
    SearchByGroceryStore=91,
    SearchByPostOffice=92,
    
} typedef CNXSearchByType ;

@interface SDKAPPExtendedMarker : CNXParkingMarker
@property (nonatomic) enum CNXSearchByType markerType;

@property (nonatomic) NSString *markerID;
@property (nonatomic) NSString *lastName;
@property (nonatomic) NSString *markerTitle;
@property (nonatomic) NSString *subtitle;
@property (nonatomic) NSString *zipCode;
@property (nonatomic) NSString *registrationMapID;
@property (nonatomic) NSString *yhaMessage;
@property (readwrite) BOOL isYouAreHereActive;

// by Mladjan - New fields for 3.5.3 - https://connexient.atlassian.net/browse/MEDINAV3-1823
@property (nonatomic) NSArray *specialties;
@property (nonatomic) NSArray *certifications;
@property (nonatomic) NSArray *education;
@property (nonatomic) NSArray *languages;
@property (nonatomic) NSArray *publishedWorks;
@property (nonatomic) NSArray *residencies;
@property (nonatomic) NSArray *biography;
@property (nonatomic) NSString *websiteURL;
// end of new fields

@property (nonatomic) NSString *thumbnailImage;
// by CJS 10-12-2015
@property (nonatomic) NSString *fullStreetAddress;
@property (nonatomic) BOOL isUserLocation;
@property (nonatomic, readonly) BOOL isInside;
@property (nonatomic) NSString *parkingName;
// 09-13-2017
@property (nonatomic) SDKAPPProfileCMS *profileCMS;
// by Sarto 2018-03-01
@property (nonatomic) NSString *pavilionName;

// by CJS 04-25-2018
@property (nonatomic) NSString *preferredParkingFromConfig;

// by CJS 05-21-2019
@property (nonatomic) NSString *preferredEntranceFromConfig;

// by CJS 08-23-2018
@property (nonatomic) BOOL isCampusLocation;

// by Sarto 20180914
@property (nonatomic) NSString *imageURL;
@property (nonatomic) NSString *additionalInfo;

// by CJS 11/05/2018 - https://connexient.atlassian.net/browse/MEDINAV3-944
@property (nonatomic) CNXWayPoint *waypoint;
// by Waseem 04-13-2019 add level2key for second level filtering
@property (nonatomic) NSString *level2Key;

// by CJS 12-19-2018
@property UIView *yhaCustomView;

@property (nonatomic) NSArray *otherOfficeLocations;
@property (nonatomic) NSString *phoneNumber;
@property (nonatomic) NSString *faxNumber;

// by Mladjan - 06.06.2019. - validation of the marker
@property (nonatomic) BOOL isValid;

// by Waseem 01-08-2019
@property (nonatomic) NSString *concatinatedListingName;
@property (nonatomic) NSString *concatinatedProfileName;

- (id)initWithTitle:(NSString *)title subtitle:(NSString *)subtitle andLocationCoordinate:(CNXLocationCoordinate *)locationCoordinate;
- (id)initWithTitle:(NSString *)title andCNXPlace:(CNXPlace *)place;
- (id)initWithLocation:(CNXLocationCoordinate *) location;
@end
