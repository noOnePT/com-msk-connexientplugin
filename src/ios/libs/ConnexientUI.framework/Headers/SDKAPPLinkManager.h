//
//  SDKAPPLinkManager.h
//  com.connexient.SDKAPP
//
//  Created by Curcio Jamunda Sobrinho on 22/08/18.
//  Copyright © 2018 CNX. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SDKAPPLinkManager : NSObject

// this is the main checker, it has to be called on every important controller
+(BOOL) hasProcessForThisVC:(__weak UIViewController *)viewController;
+(void) processURL:(NSURL *) url;
+(NSDictionary *)deeplinkData;

@end
