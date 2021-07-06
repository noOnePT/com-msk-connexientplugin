//
//  CNXBaseSQLiteStore.h
//  ConnexientSDK
//
//  Created by Fabian Fermin Guerra Soto on 2/14/14.
//  Copyright (c) 2014 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnexientKit/CNXSQLite.h>

/**
 *  @brief Helper method for SQLiteStore
 */
@interface CNXBaseSQLiteStore : NSObject

/**
 *  Helper method used in SQLiteStore
 *
 *  @param chars C chars
 *
 *  @return NSString instance
 */
- (nullable NSString *)stringWithChars:(nonnull char *)chars;

@end
