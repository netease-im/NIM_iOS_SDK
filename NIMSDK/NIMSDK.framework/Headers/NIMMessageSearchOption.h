//
//  NIMMessageSearchOption.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMGlobalDefs.h"

NS_ASSUME_NONNULL_BEGIN

@class NIMMessage;


/**
 *  搜索顺序
 */
typedef NS_ENUM(NSInteger,NIMMessageSearchOrder) {
    /**
     *  从新消息往旧消息查询
     */
    NIMMessageSearchOrderDesc       =   0,
    
    /**
     *  从旧消息往新消息查询
     */
    NIMMessageSearchOrderAsc        =   1,
};


/**
 *  本地搜索选项
 *  @discussion 搜索条件: 时间在(startTime,endTime) 内(不包含)，类型为 messageTypes （或全类型） ，且匹配 searchContent 或 fromIds 的一定数量 (limit) 消息
 */
@interface NIMMessageSearchOption : NSObject

/**
 *  起始时间,默认为0
 */
@property (nonatomic,assign)    NSTimeInterval startTime;


/**
 *  结束时间,默认为0
 *  @discussion 搜索的结束时间,0 表示最大时间戳
 */
@property (nonatomic,assign)    NSTimeInterval endTime;

/**
 *  检索条数
 *  @discussion 默认100条,设置为0表示无条数限制
 */
@property (nonatomic,assign)    NSUInteger limit;

/**
 *  检索顺序
 */
@property (nonatomic,assign)    NIMMessageSearchOrder order;

/**
 *  查询的消息类型
 *  @discusssion 消息类型组合，默认只搜索文本类型, 只有在 allMessageTypes 为 NO 时有效
 */
@property (nonatomic,copy)    NSArray<NSNumber *> *messageTypes;

/**
 *  全部消息类型
 *  @discussion 默认为 NO
 */
@property (nonatomic,assign)    BOOL allMessageTypes;

/**
 *  检索文本
 */
@property (nullable,nonatomic,copy)      NSString *searchContent;

/**
 *  消息发出者帐号列表
 */
@property (nullable,nonatomic,copy)      NSArray<NSString *> *fromIds;

@end


/**
 *  检索服务器历史消息选项 (服务器)
 */
@interface NIMHistoryMessageSearchOption : NSObject

/**
 *  检索消息起始时间
 *  @discussion 需要检索的起始时间,没有则传入0。
 */
@property (nonatomic,assign)      NSTimeInterval  startTime;

/**
 *  检索条数
 *  @discussion 最大限制100条
 */
@property (nonatomic,assign)      NSUInteger       limit;


/**
 *  检索消息终止时间,此参数对聊天室会话无效。
 *  @discussion 当前最早的时间,没有则传入 0。
 */
@property (nonatomic,assign)      NSTimeInterval  endTime;


/**
 *  检索消息的当前参考消息,返回的消息结果集里不会包含这条消息,此参数对聊天室会话无效。
 *  @discussion 传入最早时间,没有则传入nil。
 */
@property (nullable,nonatomic,strong)      NIMMessage      *currentMessage;


/**
 *  检索顺序。
 */
@property (nonatomic,assign)      NIMMessageSearchOrder             order;

/**
 *  是否需要同步到 db，此参数对聊天室会话无效。
 *  @discussion SDK 删除消息分为两种模式：标记删除和彻底删除（参见 NIMDeleteMessagesOption）。
 *  若消息集在本地被标记删除，则意味着消息仍存在本地，但被打上了特殊的记号，同步后写入 db 会失败。
 *  只有不存在本地的消息才可以通过 sync 标记进行 db 存储
 */
@property (nonatomic,assign)      BOOL            sync;


/**
 *  查询的消息类型
 *  @discusssion 消息类型组合，默认为 nil ，搜索全类型。 此参数只对聊天室会话有效
 */
@property (nonatomic,copy)    NSArray<NSNumber *> *messageTypes;


@end

NS_ASSUME_NONNULL_END
