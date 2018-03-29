//
//  NIMApnsManager.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NIMPushNotificationSetting;
@class NIMPushNotificationMultiportConfig;

/**
 *  更新推送回调
 *
 *  @param error 错误信息，成功则error为nil
 */
typedef void(^NIMApnsHandler)(NSError * __nullable error);

/**
 *  获取 badge 回调
 *
 *  @return badge 数量
 */
typedef NSUInteger(^NIMBadgeHandler)(void);


/**
 *  推送委托
 */
@protocol NIMApnsManagerDelegate <NSObject>

/**
 *  其他端修改推送配置
 */
- (void)onOtherClientChangedPushNotificationMultiportConfig;

@end

/**
 *  推送协议
 */
@protocol NIMApnsManager <NSObject>
/**
 *  获取当前的推送免打扰设置
 *
 *  @return 推送设置
 */
- (nullable NIMPushNotificationSetting *)currentSetting;

/**
 *  更新推送免打扰设置
 *
 *  @param setting    推送设置
 *  @param completion 完成的回调
 */
- (void)updateApnsSetting:(NIMPushNotificationSetting *)setting
               completion:(nullable NIMApnsHandler)completion;



/**
 *  获取当前推送自定义配置信息
 *
 *  @return  推送自定义配置
 */
- (nullable NIMPushNotificationMultiportConfig *)currentMultiportConfig;


/**
 *  更推送自定义配置信息
 *
 *  @param config     推送自定义配置
 *  @param completion 完成的回调
 */
- (void)updateApnsMultiportConfig:(NIMPushNotificationMultiportConfig *)config
                       completion:(nullable NIMApnsHandler)completion;


/**
 *  注册获取 badge 数量的回调函数
 *
 *  @param handler 获取 badge 回调
 *  @discussion 默认场景下，云信会将所有未读数量统一汇报给服务器，包括需要提醒和不需要提醒的会话未读数，上层可以通过注册该接口进行调整
 */
- (void)registerBadgeCountHandler:(NIMBadgeHandler)handler;

/**
 *  添加委托
 *
 *  @param delegate 委托
 */
- (void)addDelegate:(id<NIMApnsManagerDelegate>)delegate;


/**
 *  移除委托
 *
 *  @param delegate 委托
 */
- (void)removeDelegate:(id<NIMApnsManagerDelegate>)delegate;
@end

NS_ASSUME_NONNULL_END
