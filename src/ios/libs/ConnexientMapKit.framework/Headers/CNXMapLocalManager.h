//
//  CNXMapLocalManager.h
//  ConnexientDemo
//
//  Created by Mladjan Antic on 5/30/16.
//  Copyright © 2016 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CNXMapManager;

@interface CNXMapLocalManager : NSObject


@property (nonatomic, weak) CNXMapManager *mapManager;
/**
 *  Shared instance
 *
 *  @return Returns the Connexient singleton object.
 
 */
+ (id)sharedManager;



@end
