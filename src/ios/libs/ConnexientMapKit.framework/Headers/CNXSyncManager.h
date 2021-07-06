//
//  CNXSyncManager.h
//  ConnexientMapKit
//
//  Created by Curcio Jamunda Sobrinho on 17/05/19.
//  Copyright © 2019 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientKit/CNXConstants.h>

NS_ASSUME_NONNULL_BEGIN

// this class represents the synch objects
@interface CNXSyncObject : NSObject

// it is the entity that has the following properties below - example: en_locations.db
@property (nonatomic) NSString *fileName;

// config has "timestamp":1557345414
@property (nonatomic) double timestamp;

// config has "filesize":652288
@property (nonatomic) double filesize;

// config has "md5hash":"34a200e7b6594d2067dcf05173a2cc74"
@property (nonatomic) NSString *md5Hash;

// the URL of the file
@property (nonatomic) NSString *url;

// the File Path of the file
@property (nonatomic) NSString *filePath;
@end

// this class represents the group of sync objetcs
@interface CNXSync : NSObject

// This one holds the current objects that are in use (from embedded or downloaded files)
@property (nonatomic) NSArray <CNXSyncObject *> *currentSyncObjects; // the URL of the file

// This one holds the objects ready to be updated next
@property NSArray <CNXSyncObject *> *updatableSyncObjects; // the URL of the file

@end

/**
 * We use Notifications to broadcast the download status
 * check ConnexientKit/CNXConstants.h to know them
 */


@interface CNXSyncManager : NSObject

@property (nonatomic) CNXSyncUpdateMethod updateMethod;

+(instancetype) sharedInstance;

// the default method is AUTO if not set
// this method has to be called BEFORE [CNXMapManager prepareMapsForUse]
-(void) setUpdateMethod:(CNXSyncUpdateMethod) syncMethod;

// the Sync Object that contains the arrays of the sync Objects
-(CNXSync *) getSync;

// the simplified call to get the updatableSyncObjects
-(NSArray <CNXSyncObject *> *) getUpdatableSyncObjects;

// the simplified call to get the total size in Bytes of the updatableSyncObjects
-(double) getTotalSizeOfUpdatableSyncObjects;

// this method will start the sync process to populate the Sync Object
// this method is called automatically inside prepareMaps
-(void) startSync;

// this method will start to download the files (that are updatableSyncObjects of CNXSync)
// and trigger the notifications
-(void) startDownloadingSyncObjects;

// this method will cancel the current update Method
-(void) cancelUpdate;
@end

NS_ASSUME_NONNULL_END
