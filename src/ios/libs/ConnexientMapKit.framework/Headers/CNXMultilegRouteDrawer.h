//
//  CNXMultilegRouteDrawer.h
//  ConnexientSDK
//
//  Created by Mladjan Antic on 9/18/17.
//  Copyright © 2017 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNXGeneralRoute.h"
#import "CNXRouteLeg.h"

@protocol CNXMultilegRouteDelegate<NSObject>

@optional

/**
 *  Leg started drawing
 *
 */
-(void)startLegDrawing:(CNXRouteLeg *_Nonnull)routeLeg;
-(void)routeNotCalculated;
@end

@interface CNXMultilegRouteDrawer : NSObject


@property (nonatomic, weak, nullable) id<CNXMultilegRouteDelegate> multilegRouteDelegate;

@property (nonatomic) CNXRouteLeg * _Nullable currentRouteleg;
@property (nonatomic) CNXGeneralRoute * _Nullable currentRoute;

-(void)drawGeneralRoute:(CNXGeneralRoute *_Nonnull)route;

/**
 *  Leg started drawing
 *
 */
-(void)legEndedDrawing;

-(void)showNextLeg;
-(void)showPreviousLeg;
-(void)drawLeg:(nonnull CNXRouteLeg *)leg;

@end
