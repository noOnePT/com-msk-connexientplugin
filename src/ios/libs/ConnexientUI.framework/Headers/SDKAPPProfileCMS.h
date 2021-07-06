//
//  SDKAPPProfileCMS.h
//  com.connexient.SDKAPP
//
//  Created by Curcio Jamunda Sobrinho on 13/09/17.
//  Copyright © 2017 CNX. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SDKAPPProfileCMS : NSObject <NSCopying>

@property (nonatomic) NSString *campusName;
@property (nonatomic) NSString *fullAddress;
@property (nonatomic) NSString *profileDescription;
// array of dictionary in this format {@"text" : NSString text to be shown, @"image" : UIImage, @"target" : NString selectorName}
@property (nonatomic) NSArray <NSDictionary *> *profileOptions;
@property (nonatomic) NSString *recomendedParking;
@property (nonatomic) NSString *recomendedParkingMapID;
@property (nonatomic, copy) UIImage *profileImage;
// array of dictionary in this format {@"title" : NSString text to be shown, @"address" : NSString address}
@property (nonatomic) NSArray <NSDictionary *> *otherOfficeLocations;

@property (nonatomic) NSString *url;
@property (nonatomic) NSString *phoneNumber;
@property (nonatomic) NSString *urlTitle;

@end
