//
//  NIMTeamMessageReceiptDetail.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2018年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@class NIMMessageReceipt;
/**
 *  已读回执详情
 */
@interface NIMTeamMessageReceiptDetail : NSObject

/**
 *  所属消息 Id
 */
@property (nonatomic, copy, readonly) NSString *messageId;

/**
 *  所属会话 Id
 */
@property (nonatomic, copy, readonly) NSString *sessionId;

/**
 *  已读用户列表
 */
@property (nonatomic, copy, readonly) NSArray *readUserIds;

/**
 *  未读用户列表
 */
@property (nonatomic, copy, readonly) NSArray *unreadUserIds;

@end


NS_ASSUME_NONNULL_END
