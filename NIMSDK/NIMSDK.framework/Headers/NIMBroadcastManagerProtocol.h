//
//  NIMBroadcastManagerProtocol.h
//  NIMLib
//
//  Created by amao on 2017/9/19.
//  Copyright © 2017年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NIMBroadcastMessage;

/**
 *  广播消息委托
 */
@protocol NIMBroadcastManagerDelegate <NSObject>

/**
 *  收到广播消息回调
 *
 *  @param broadcastMessage 广播消息
 */

- (void)onReceiveBroadcastMessage:(NIMBroadcastMessage *)broadcastMessage;
@end

/**
 *  广播消息协议
 */
@protocol NIMBroadcastManager <NSObject>

/**
 *  添加广播消息委托
 *
 *  @param delegate 广播通知回调
 */
- (void)addDelegate:(id<NIMBroadcastManagerDelegate>)delegate;

/**
 *  移除广播消息委托
 *
 *  @param delegate 广播通知回调
 */
- (void)removeDelegate:(id<NIMBroadcastManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
