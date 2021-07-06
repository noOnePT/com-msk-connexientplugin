//
//  CNXVoice.h
//  ConnexientSDK
//
//  Created by Curcio Jamunda Sobrinho on 02/09/15.
//  Copyright (c) 2015 Connexient. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface CNXVoice : NSObject
+(void) turnVoiceService:(BOOL) on;
+(void) setVoiceEnable:(BOOL) enable;
+(BOOL) canUseVoice;
+(void) startVoice;
+(void) stopVoice;
+(void) removeVoice;
+(void) readText:(NSString *) text;
 @end
