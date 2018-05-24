//
//  NIMBroadcastMessage.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  系统广播
 */
@interface NIMBroadcastMessage : NSObject

/**
 *  系统广播 id，全局唯一
 */
@property (nonatomic,assign,readonly)               int64_t     broadcastId;

/**
 *  发起者 id
 */
@property (nullable,nonatomic,copy,readonly)        NSString    *sender;

/**
 *  时间
 */
@property (nonatomic,assign,readonly)               NSTimeInterval timestamp;

/**
 *  内容
 */
@property (nullable,nonatomic,copy,readonly)         NSString    *content;
@end

NS_ASSUME_NONNULL_END
