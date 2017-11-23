//
//  NIMPlatform.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017年 Netease. All rights reserved.
//

#ifndef NIMPlatform_h
#define NIMPlatform_h

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
#define NIM_IOS 1
#endif

#if TARGET_OS_MAC && !TARGET_OS_IPHONE
#define NIM_MAC 1
#endif


#if NIM_IOS
#import <UIKit/UIKit.h>
#elif NIM_MAC
#import <Cocoa/Cocoa.h>
@compatibility_alias UIImage NSImage;
#endif


#endif /* NIMPlatform_h */
