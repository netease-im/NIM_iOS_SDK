//
//  NIMTeamMessageReceipt.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2018年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  群已读回执信息
 *  @discussion 只有当当前消息为 Team 消息且 teamReceiptEnabled 为 YES 时才有效，需要对端调用过发送已读回执的接口
 */
@interface NIMTeamMessageReceipt : NSObject

/**
 *  已读人数
 *  @discussion 只有当当前消息为 Team 消息且 teamReceiptEnabled 为 YES 时这个字段才有效，需要对端调用过发送已读回执的接口
 */
@property (nonatomic,assign,readonly)       NSInteger readCount;

/**
 *  未读人数
 *  @discussion 只有当当前消息为 Team 消息且 teamReceiptEnabled 为 YES 时这个字段才有效，需要对端调用过发送已读回执的接口
 */
@property (nonatomic,assign,readonly)       NSInteger unreadCount;

@end

NS_ASSUME_NONNULL_END
