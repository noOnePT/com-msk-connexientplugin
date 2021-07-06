//
//  CNXGeneralRoute.h
//  ConnexientSDK
//
//  Created by Mladjan Antic on 9/4/17.
//  Copyright © 2017 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientMapKit/CNXRouteLeg.h>

@interface CNXGeneralRoute : NSObject

@property (nonatomic, nonnull) NSMutableArray <CNXRouteLeg *> *legs;
@property (nonatomic, nonnull) CNXRouteLeg *currentLeg;
@property (nonatomic) CNXPlace * _Nullable preferredParking;

-(void)clear;
-(void)prepareMapsForUseWithComplitionBlock:(void (^ _Nullable)(BOOL completed))finishBlock;
-(void)compactRoute;

@end
