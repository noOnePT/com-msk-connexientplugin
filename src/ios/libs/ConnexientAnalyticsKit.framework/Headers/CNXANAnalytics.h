//
//  CNXANAnalytics.h
//  ConnexientSDK
//
//  Created by Curcio Jamunda Sobrinho on 28/12/16.
//  Copyright © 2016 Connexient. All rights reserved.
//

#import "CNXANWebService.h"

@interface CNXANAnalytics : NSObject

/**
 *  Version of the analyticsKit framework
 *
 *  @return version as NSString object
 */
+ (nonnull NSString *)getAnalyticsKitVersion;

+(void) getStarted;
+(void) sendEvent:(CNXANEventType) type withParameters:(nullable NSDictionary *) params;
+(void) syncEvents;
@end
