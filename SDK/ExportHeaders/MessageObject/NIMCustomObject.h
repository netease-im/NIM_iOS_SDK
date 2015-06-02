//
//  NIMCustomObject.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#import "NIMMessageObjectProtocol.h"
/**
 *  用户自定义消息对象
 */
@interface NIMCustomObject : NSObject<NIMMessageObject>

/**
 *  用户自定义消息体
 */
@property(nonatomic, copy) NSString * content;

@end
