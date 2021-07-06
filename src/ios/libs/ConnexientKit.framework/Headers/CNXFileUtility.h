//
//  CNXFileUtility.h
//  Stanford
//
//  Created by Fabian Fermin Guerra Soto on 6/1/15.
//  Copyright (c) 2015 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  @brief File helpers
 */
@interface CNXFileUtility : NSObject

+ (NSString*)md5CheckSumWithFileData:(NSData*)fileData;

@end
