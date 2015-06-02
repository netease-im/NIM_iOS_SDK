//
//  NIMConversationManager.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
@class NIMMessage;
@class NIMSession;
@class NIMRecentSession;
@class NIMHistoryMessageSearchOption;

/**
 *  读取服务器消息记录block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param messages 读取的消息列表
 */
typedef void(^NIMFetchMessageHistoryBlock)(NSError *error,NSArray *messages);

/**
 *  会话管理器回调
 */
@protocol NIMConversationManagerDelegate <NSObject>

@optional

/**
 *  增加最近会话的回调
 *
 *  @param recentSession    最近会话
 *  @param totalUnreadCount 目前总未读数
 */
- (void)didAddRecentSession:(NIMRecentSession *)recentSession
           totalUnreadCount:(NSInteger)totalUnreadCount;

/**
 *  最近会话修改的回调
 *
 *  @param recentSession    最近会话
 *  @param totalUnreadCount 目前总未读数
 */
- (void)didUpdateRecentSession:(NIMRecentSession *)recentSession
              totalUnreadCount:(NSInteger)totalUnreadCount;

/**
 *  删除最近会话的回调
 *
 *  @param recentSession    最近会话
 *  @param totalUnreadCount 目前总未读数
 */
- (void)didRemoveRecentSession:(NIMRecentSession *)recentSession
              totalUnreadCount:(NSInteger)totalUnreadCount;


@end

/**
 *  会话管理器
 */
@protocol NIMConversationManager <NSObject>

/**
 *  删除某条消息
 *
 *  @param message 待删除的聊天消息
 *  @discussion 异步方法，消息会标记为已删除
 */
- (void)delMessage:(NIMMessage *)message;

/**
 *  删除某个会话的所有消息
 *
 *  @param session 待删除会话
 *  @discussion 异步方法，最近会话仍然保留，会话内消息将会标记为已删除
 */
- (void)deleteAllmessagesInSession:(NIMSession *)session;


/**
 *  删除某个最近会话
 *
 *  @param recentSession 待删除的最近会话
 *  @discussion 异步方法，删除最近会话，但保留会话内消息
 */
- (void)deleteRecentSession:(NIMRecentSession *)recentSession;


/**
 *  设置一个会话里所有消息置为已读
 *
 *  @param session 需设置的会话
 *  @discussion 异步方法，消息会标记为设置的状态
 */
- (void)markAllMessageReadInSession:(NIMSession *)session;


/**
 *  从本地db读取一个会话里某条消息之前的若干条的消息
 *
 *  @param session 消息所属的会话
 *  @param message 当前最早的消息,没有则传入nil
 *  @param limit   个数限制
 *
 *  @return 消息列表
 */
- (NSArray*)messagesInSession:(NIMSession *)session
                      message:(NIMMessage *)message
                        limit:(NSInteger)limit;

/**
 *  获取所有未读数,在主线程调用
 *
 *  @return 未读数
 */
- (NSInteger)allUnreadCount;

/**
 *  获取所有最近会话
 *
 *  @return 最近会话列表
 */
- (NSArray*)allRecentSession;


/**
 *  从服务器上获取一个会话里某条消息之前的若干条的消息
 *
 *  @param session 消息所属的会话
 *  @param option  搜索选项
 *  @param block   读取的消息列表结果
 *
 */
- (void)fetchMessageHistory:(NIMSession *)session
                     option:(NIMHistoryMessageSearchOption *)option
                     result:(NIMFetchMessageHistoryBlock)block;

/**
 *  添加通知对象
 *
 *  @param delegate 通知对象
 */
- (void)addDelegate:(id<NIMConversationManagerDelegate>)delegate;

/**
 *  删除通知对象
 *
 *  @param delegate 通知对象
 */
- (void)removeDelegate:(id<NIMConversationManagerDelegate>)delegate;

@end

/**
 *  检索服务器历史消息选项
 */
@interface NIMHistoryMessageSearchOption : NSObject

/**
 *  检索消息起始时间
 *  @discussion 需要检索的起始时间,没有则传入0
 */
@property (nonatomic,assign)      NSTimeInterval  startTime;

/**
 *  检索消息终止时间
 *  @discussion 当前最早的时间,没有则传入0
 */
@property (nonatomic,assign)      NSTimeInterval  endTime;

/**
 *  检索消息的当前参考消息,返回的消息结果集里不会包含这条消息
 *  @discussion 传入最早时间,没有则传入nil
 */
@property (nonatomic,strong)      NIMMessage      *currentMessage;

/**
 *  检索条数
 *  @discussion 最大限制100条
 */
@property (nonatomic,assign)      NSUInteger       limit;

/**
 *  检索顺序
 *  @discussion true是表示反向查询(按时间正序起查，正序排列)，默认false表示按时间逆序起查，逆序排列
 */
@property (nonatomic,assign)      BOOL             reverse;

/**
 *  是否需要同步到DB
 */
@property (nonatomic,assign)      BOOL            sync;


@end


