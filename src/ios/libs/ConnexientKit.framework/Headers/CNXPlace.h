//
//  CNXPlace.h
//  ConnexientSDK
//
//  Created by Mladjan Antic on 10/4/15.
//  Copyright © 2015 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientKit/CNXLocationCoordinate.h>
/**
 *  @brief Place model
 */
@interface CNXPlace : NSObject

typedef NS_ENUM(NSInteger, CNXPlaceType) {
    CNXPlaceTypeNetworkLocation = 1,
    CNXPlaceTypeBuilding,
    CNXPlaceTypeHotspot,
    CNXPlaceTypePOI,
    CNXPlaceTypeParking
};

typedef NS_ENUM(NSInteger, CNXPlaceLocationType) {
    CNXPlaceLocationTypeDepartment = 1,
    CNXPlaceLocationTypeRoom = 2,
    CNXPlaceLocationTypeEntrance = 4,
    CNXPlaceLocationTypePatientServices = 5,
    CNXPlaceLocationTypeHospitalAdmin = 6,
    CNXPlaceLocationTypeCarGarage = 7,
    CNXPlaceLocationTypeOffsiteServices = 8,
    CNXPlaceLocationTypeRestRoom = 9,
    CNXPlaceLocationTypeATM = 10,
    CNXPlaceLocationTypeShop = 11,
    CNXPlaceLocationTypePharmacy = 12,
    CNXPlaceLocationTypeConferenceRooms = 13,
    CNXPlaceLocationTypeBreakRoom = 14,
    CNXPlaceLocationTypeElevator = 15,
    CNXPlaceLocationTypeDining = 16,
    CNXPlaceLocationTypePOVPhoto = 17,
    CNXPlaceLocationTypeAmenities = 18,
    CNXPlaceLocationTypeKiosk = 19,
    CNXPlaceLocationTypeParkingPayStation = 20,
    CNXPlaceLocationTypeStairs = 22,
    CNXPlaceLocationTypeHotelAccommodation = 37,
    CNXPlaceLocationTypeStaffOnlyDepartment = 50,
    CNXPlaceLocationTypeDepartments = 51,
    CNXPlaceLocationTypeClinic = 52,
    CNXPlaceLocationTypeExit = 53,
    CNXPlaceLocationTypeEmergencyCallBox = 54,
    CNXPlaceLocationTypeEmergencyDepartment = 62,
    CNXPlaceLocationTypeBikeRack = 55,
    CNXPlaceLocationTypeDefibrillator = 56,
    CNXPlaceLocationTypeHotel = 57,
    CNXPlaceLocationTypeCourtyard = 58,
    CNXPlaceLocationTypeHospitality = 59,
    CNXPlaceLocationTypeChapel = 101,
    CNXPlaceLocationTypeChargingStationsElectronics = 97,
    CNXPlaceLocationTypeChargingStationsVehicles = 96,
    CNXPlaceLocationTypeInformationDesk = 29,
    CNXPlaceLocationTypeMothersRoom = 28,
    CNXPlaceLocationTypeLobby = 81,
    CNXPlaceLocationTypeMyFavorites = 222,
    CNXPlaceLocationTypePatientCareUnits = 78,
    CNXPlaceLocationTypePointsOfInterest = 223,
    CNXPlaceLocationTypeVendingMachine = 21,
    CNXPlaceLocationTypeBadgeDrop = 203,
    CNXPlaceLocationTypeRadiology = 196,        // added by MSK
    CNXPlaceLocationTypePantry = 204,           // added by MSK
    CNXPlaceLocationTypeWaitingArea = 205,
    CNXPlaceLocationTypeNursingStation = 207,    // added by MSK
    CNXPlaceLocationTypeBusStop = 76,           // added by MASH
    CNXPlaceLocationTypeOffsiteParking = 236,   // added by MASH,
    CNXPlaceLocationTypeGasStation = 171,
    CNXPlaceLocationTypeValetParking = 254,
    CNXPlaceLocationTypeCoffeeShop = 231,
    CNXPlaceLocationTypeCafeteria = 233,
    CNXPlaceLocationTypeMedicalOffices = 150,
    CNXPlaceLocationTypeRegistration = 181,
    CNXPlaceLocationTypeRetail = 237,
    CNXPlaceLocationTypePickupZone = 241,
    CNXPlaceLocationTypeWaitingRoom = 151,
    CNXPlaceLocationTypeEscalator = 104,
    CNXPlaceLocationTypeOutpatientTesting = 251,
    CNXPlaceLocationTypeOutpatientTreatment = 252,
    CNXPlaceLocationTypeMemorial = 220

};
/**
 *  Place name
 */
@property (nonatomic, nullable) NSString *name;

/**
 *  Map ID, which represents unique string ID for every place on the map.
 */
@property (nonatomic, nullable) NSString *mapID;

/**
 *  Floor ID
 */
@property (nonatomic, nullable) NSString *floorID;

/**
 *  Venue ID
 */
@property (nonatomic, nullable) NSNumber *venueID;


/**
 *  Tags
 */
@property (nonatomic, nullable) NSString *tags;

/**
 *  Config - additional configuration of the place
 */
@property (nonatomic, nullable) NSString *configString;


/**
 *  Is Place active?
 */
@property (nonatomic, nullable) NSNumber *isActive;

@property CNXPlaceLocationType placeLocationType;

@property (nonatomic, nonnull) NSNumber *placePositionTypeId;

@property (nonatomic, nullable) NSString *branchName;

@property (nonatomic, nullable) NSString *wingID;

@property (nonatomic, nullable) NSString *wingName;

@property (nonatomic, nullable) NSString *buildingID;

@property (nonatomic, nullable) NSString *buildingMapID;

@property (nonatomic, nullable) NSString *buildingGroupID;

@property (nonatomic, nullable) NSString *buildingName;

@property (nonatomic, nullable) NSString *floorName;

@property (nonatomic, nullable) NSString *externalId;

/**
 *  Distance in meters which is populated when you use getSortedPlacesByDistanceInList method
 */
@property (nonatomic) float distance;

/**
 *  User defined data, its nil by default and SDK is never populating this property
 */
@property (nonatomic, nullable) id data;

/**
 *  Geocordinate. Please be sure that you have set Geocoordiante OR Sceene coordinate
 */
@property (nonatomic, nullable) CNXLocationCoordinate *geoLocationCoordinate;

/**
 *  Sceene coordinate. Please be sure that you have set Geocoordiante OR Sceene coordinate
 */
@property (nonatomic, nullable) CNXLocationCoordinate *sceneLocationCoordinate;

@end
