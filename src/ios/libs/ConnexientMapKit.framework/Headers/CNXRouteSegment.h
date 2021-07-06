//
//  CNXRouteSegment.h
//  Stanford
//
//  Created by Fabian Fermin Guerra Soto on 9/15/14.
//  Copyright (c) 2014 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  @brief Represents one segment in one route
 */
@interface CNXRouteSegment : NSObject

@property (nonatomic) int index;
@property (nonatomic) int startInstructionIndex;
@property (nonatomic) int endInstructionIndex;
@property (nonatomic) NSString *floorLayer;
@property (nonatomic, getter=isFloorChange) BOOL floorChange;
@property (nonatomic) float duration;
@property (nonatomic) float distance;
@property (nonatomic) float totalTime;
@property (nonatomic, strong) NSString *startPlace;
@property (nonatomic, strong) NSString *endPlace;
@property (nonatomic, strong) NSString *segmentInstruction;

@end
