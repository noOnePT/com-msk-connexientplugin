

#import <Foundation/Foundation.h>
#import <ConnexientKit/CNXLocationCoordinate.h>

/**
 * Stores information related to a floor within the venue
 */
@interface CNXMapFloor : NSObject
-(instancetype)initWithId:(NSString*)pId andLayout:(NSDictionary*)pLayout andLocalisation:(NSDictionary*)pLocalisation;
@property (nonatomic, strong) NSString* mId;
@property (nonatomic, strong) NSString* mName;
@property (nonatomic, strong) NSString* mShortName;
@property (nonatomic, strong) NSString* mDescription;
@property (nonatomic, strong) NSString* mLayer;
@property NSInteger mLevelIndex;
@end

/**
 * Stores information related to a building within the venue
 */
@interface CNXMapBuilding : NSObject
-(instancetype)initWithId:(NSString*)pId andLayout:(NSDictionary*)pLayout andLocalisation:(NSDictionary*)pLocalisation;
/**
 * Returns the specific floor within the building
 * @param pID A floor id
 * @return The floor that corresponds to the floor id.
 */
-(CNXMapFloor*)getFloorWithId:(NSString*)pID;
/**
 * @returns The ground floor within the building.
 */
-(CNXMapFloor*) getGroundFloor;
/**
 * 
 */
-(CNXMapFloor*) getFloorWithLevelIndex:(NSInteger) pLevelIndex;
@property (nonatomic, strong) NSString* mId;
@property (nonatomic, strong) NSString* mName;
@property (nonatomic, strong) NSString* mShortName;
@property (nonatomic, strong) NSString* mDescription;
@property (nonatomic, strong) NSString* mDefaultFloor;
@property (nonatomic, strong) NSMutableArray* mFloors;
@property (nonatomic) NSArray <CNXLocationCoordinate *> *geoFenceCoordinates;

@property NSInteger mDisplayIndex;
@end

/**
 * This class stores the configuration for the map hierarchy.
 */
@interface CNXVenueLayout : NSObject
/**
 * Constructor
 * @param pLayout The venue layout
 * @param pLocalisation The localisation for the venue (where possible should
 * correspond with the devices current locale).000000
 */
-(instancetype)initWithLayout:(NSDictionary*)pLayout andLocalisation:(NSDictionary*)pLocalisation;
/**
 * Returns the building associated with a given id
 */
-(CNXMapBuilding*)getBuildingWithId:(NSString*)pID;
@property (nonatomic, strong) NSString* mMapName;
@property (nonatomic, strong) NSString* mGlobalLayerName;
@property (nonatomic, strong) NSString* mDefaultBuilding;

/**
 * An array of VgBuilding objects
 */
@property (nonatomic, strong) NSMutableArray* mBuildings;

@end
