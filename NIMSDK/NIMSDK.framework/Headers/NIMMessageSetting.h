//
//  NIMMessageSetting.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  消息配置
 */
@interface NIMMessageSetting : NSObject
/**
 *  消息是否允许在消息历史中拉取
 *  @discussion 默认为YES。 正常而言所有消息都会出现在通过 NIMConversationManager 调用(fetchMessageHistory:option:result:)返回的结果中，但是可以通过设置这个值来使得消息不出现在这其中。
 */
@property (nonatomic,assign)    BOOL        historyEnabled;
/**
 *  消息是否支持漫游
 *  @discussion 默认为YES。 消息漫游的概念是指一定时间内发送的消息可以在另一端被同步到，以保证最大限度的消息同步。(如iOS上收发的消息过了一天登录PC仍旧会收到，这种消息我们称之为漫游消息)
 */
@property (nonatomic,assign)    BOOL        roamingEnabled;
/**
 *  消息是否支持多端同步
 *  @discussion 默认为YES。在默认情况下，如果用户在 iOS端和其他端（如PC）同时登录一个帐号，那么iOS 端发送的消息会被同步到其他端，同样其他端发送的消息也会被同步到 iOS 端。但是需要注意的是因为 iOS 经常会退到后台，所以其他端发送的消息在 iOS 断线后是通过漫游消息来同步到的。
 */
@property (nonatomic,assign)    BOOL        syncEnabled;
/**
 *  消息是否需要被计入未读计数
 *  @discussion 默认为YES。默认情况下，用户收到的所有消息都会被计入未读。设置这个为NO后，对应的消息被对端接受后将不计入未读消息计数内。
 */
@property (nonatomic,assign)    BOOL        shouldBeCounted;
/**
 *  消息是否需要推送
 *  @discussion 默认为YES。将这个字段设为NO，消息将不再有苹果推送通知。
 */
@property (nonatomic,assign)    BOOL        apnsEnabled;
/**
 *  推送是否需要带前缀(一般为昵称)
 *  @discussion 默认为YES。将这个字段设为NO，推送消息将不带有前缀(xx:)。
 */
@property (nonatomic,assign)    BOOL        apnsWithPrefix;

/**
 *  是否需要抄送
 *  @discussion 默认为YES，即默认会抄送消息给开发者的服务器(如果有配置的话)
 */
@property (nonatomic,assign)    BOOL        routeEnabled;

/**
 *  其他群成员收到此消息是否需要发送已读回执
 *  @discussion 默认为NO，设置成 YES 之后所有群回执相关操作才会生效
 */
@property (nonatomic,assign)    BOOL        teamReceiptEnabled;

/**
 *  消息是否支持离线
 *  @discussion 默认为YES，设置成 NO 之后消息将只会发送到在线的对端，对端不在线则会被丢弃。此开关对聊天室消息不生效
 */
@property (nonatomic,assign)    BOOL        persistEnable;


@end

NS_ASSUME_NONNULL_END
