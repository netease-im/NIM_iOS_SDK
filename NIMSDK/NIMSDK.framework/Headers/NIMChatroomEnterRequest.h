//
//  NIMChatroomEnterRequest.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



/**
 *  获取聊天室地址回调
 */
typedef void(^NIMRequestChatroomAddressesCallback)(NSError * __nullable error,NSArray<NSString *> * __nullable addresses);

/**
 *  获取聊天室地址方法
 */
typedef void(^NIMRequestChatroomAddressesHandler)(NSString *roomId,NIMRequestChatroomAddressesCallback callback);



/**
 *  聊天室独立模式
 */
@interface NIMChatroomIndependentMode : NSObject

/**
 *  独立模式下的用户名
 *  @discussion 设置为 nil 情况下，SDK 将使用匿名账号进行登录。在匿名模式下，NIMChatroomEnterRequest 必须设置昵称和头像信息
 */
@property (nullable,nonatomic,copy)  NSString    *username;

/**
 *  独立模式下的 Token
 *  @discussion 当用户名为空时，token 无效
 */
@property (nullable,nonatomic,copy)  NSString    *token;

/**
 *  注册获取聊天室地址的回调方法
 *
 *  @param handler 获取聊天室地址信息的方法
 *  @discussion 在进入聊天室和刷新聊天室 IP 时，SDK 都会主动调用这个回调方法，并传入相应的两个参数 `roomId` 和 `callback`。
 *              当前回调接口要求上层使用 `roomId` 走自己的网络请求获取对应聊天室地址并通过 callback 回调给 SDK。
 *              需要注意的是无论请求成功，都需要通过 callback 进行回调，否则进入聊天室请求将会一直等待。同时此接口只需注册一次即可，多次注册将使用后者覆盖前者。
 *
 *  参考代码：
 *
 *   [NIMChatroomIndependentMode registerRequestChatroomAddressesHandler:^(NSString * _Nonnull roomId, NIMRequestChatroomAddressesCallback  _Nonnull callback) {
 *           [YourHTTPService request:roomId completion:^(NSError *error,NSArray *addresses)
 *           {
 *                //无论请求是否成功，都需要进行回调
 *                if(callback)
 *                {
 *                    callback(error,addresses);
 *                }
 *            }];
 *        }];
 *
 */
+ (void)registerRequestChatroomAddressesHandler:(NIMRequestChatroomAddressesHandler)handler;

@end

/**
 *  进入聊天室请求
 */
@interface NIMChatroomEnterRequest : NSObject

/**
 *  聊天室Id
 */
@property (nonatomic,copy)  NSString    *roomId;

/**
 *  聊天室昵称
 *  @discussion 上层可以自主设置在聊天室内的昵称，没有设置则使用用户本身的信息
 */
@property (nullable,nonatomic,copy)  NSString    *roomNickname;

/**
 *  聊天室头像
 *  @discussion 上层可以自主设置在聊天室内的头像，没有设置则使用用户本身的信息
 */
@property (nullable,nonatomic,copy)  NSString    *roomAvatar;

/**
 *  本人的聊天室成员信息拓展字段，仅对当次进入有效
 */
@property (nullable,nonatomic,copy)  NSString    *roomExt;
/**
 *  聊天室事件通知拓展字段
 */
@property (nullable,nonatomic,copy)  NSString    *roomNotifyExt;

/**
 *  聊天室重连次数,默认为三次
 *  @discussion 设置成 0 后一旦一次连接失败后，SDK 将不在重试。 APP 可以根据自己的需求进行设置
 */
@property (nonatomic,assign) NSInteger retryCount;


/**
 *  聊天室独立模式
 *  @discussion 默认为 nil，即聊天室登录需要依赖 IM 登录，只有 IM 登录后才能够登录聊天室。设置后可以在不依赖 IM 通道的情况下进行登录
 */
@property (nullable,nonatomic,strong)   NIMChatroomIndependentMode *mode;


@end





NS_ASSUME_NONNULL_END

