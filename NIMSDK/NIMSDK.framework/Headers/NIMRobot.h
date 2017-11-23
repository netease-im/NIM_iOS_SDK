//
//  NIMRobot.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  机器人
 */
@interface NIMRobot : NSObject

/**
 *  机器人对应的云信账号 Id
 */
@property (nullable,nonatomic,copy)   NSString    *userId;

/**
 *  机器人对应的波特 Id
 */
@property (nullable,nonatomic,copy,readonly) NSString *botId;

/**
 *  机器人昵称
 */
@property (nullable,nonatomic,copy,readonly) NSString *nickname;

/**
 *  机器人简介
 */
@property (nullable,nonatomic,copy,readonly) NSString *intro;

/**
 *  机器人头像
 */
@property (nullable,nonatomic,copy,readonly) NSString *avatarUrl;

/**
 *  机器人头像缩略图
 *  @discussion 仅适用于使用云信上传服务进行上传的资源，否则无效。
 */
@property (nullable,nonatomic,copy,readonly) NSString *thumbAvatarUrl;


@end


NS_ASSUME_NONNULL_END
