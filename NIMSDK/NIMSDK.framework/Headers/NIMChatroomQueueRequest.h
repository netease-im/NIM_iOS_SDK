//
//  NIMChatroomQueueRequest.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/**
 *  聊天室通用队列更新请求
 */
@interface NIMChatroomQueueUpdateRequest : NSObject

/**
 *  聊天室 ID
 */
@property (nonatomic,copy) NSString *roomId;

/**
 *  更新元素的 Key 值，如果 key 在队列中存在则更新，不存在则放到队列尾部 ，长度限制为 32 字节
 */
@property (nonatomic,copy) NSString *key;

/**
 *  更新元素的 Value 值，长度限制为 4096 字节
 */
@property (nonatomic,copy) NSString *value;


/**
 *  当提交这个新元素的用户从聊天室掉线或退出的时候，是否需要删除这个元素，默认为 NO 不删除。
 */
@property (nonatomic,assign) BOOL transient;

@end




/**
 *  聊天室通用队列取出请求
 */
@interface NIMChatroomQueueRemoveRequest : NSObject

/**
 *  聊天室ID
 */
@property (nonatomic,copy) NSString *roomId;

/**
 *  拉去元素的Key值，如果要拉取第一个元素，则传空
 */
@property (nullable,nonatomic,copy) NSString *key;


@end




NS_ASSUME_NONNULL_END
