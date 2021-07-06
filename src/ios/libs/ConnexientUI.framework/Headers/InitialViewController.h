//
//  InitialViewController.h
//  com.connexient.SDKAPP
//
//  Created by Curcio Jamunda Sobrinho on 15/12/15.
//  Copyright © 2015 CNX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SlideMenuController.h"



@interface InitialViewController : UIViewController<NSFileManagerDelegate>

+(id) sharedInstance;
+(id) initSharedInstance;
+(id) returnMenuInstance;
+(id) returnMapNavInstance;
+(id) returnMapInstance;
+(id) returnSlideMenuInstance;
+(id) returnProfileMapInstance;
+(void) resetMapInstance;
@end
