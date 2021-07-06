//
//  CNXRoutingWaypoint.h
//  ConnexientKit
//
//  Created by Mladjan Antic on 10/12/18.
//  Copyright © 2018 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNXPlace.h"
#import "CNXLocationCoordinate.h"

NS_ASSUME_NONNULL_BEGIN

@interface CNXRoutingWaypoint : NSObject

@property (nonatomic) CNXPlace *place;

@property (nonatomic) CNXLocationCoordinate *location;

@end

NS_ASSUME_NONNULL_END
