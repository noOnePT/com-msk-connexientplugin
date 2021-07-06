//
//  CNXANUser.h
//  Stanford
//
//  Created by Curcio Jamunda Sobrinho on 27/12/16.
//  Copyright © 2016 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CNXANUser : NSObject
@property (nonatomic) NSString *userID;
@property (nonatomic) NSString *clientID;
@property (nonatomic) NSString *userToken;
@property (nonatomic) NSString *userDeviceOS;
@property (nonatomic) NSString *userDeviceModel;
@property (nonatomic) NSString *userDeviceVersion;
@property (nonatomic) NSString *userLanguage;

+(id) sharedInstance;
+(void) saveUserID:(NSString *) userID;
@end
