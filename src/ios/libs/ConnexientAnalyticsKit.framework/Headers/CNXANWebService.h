//
//  CNXANWebService.h
//  ConnexientSDK
//
//  Created by Curcio Jamunda Sobrinho on 27/12/16.
//  Copyright © 2016 Connexient. All rights reserved.
//

#import "CNXANUser.h"
#import "CNXANEvent.h"

@interface CNXANWebService : NSObject
+(void) sendEvent:(CNXANEvent *)event withReturnBlock:(void(^)(BOOL eventCreated, CNXANEvent *eventDone, NSError *error)) block;

// this will check token, if does not exist, will create new userID and save
+(void) checkUserID:(CNXANUser *)user;
@end
