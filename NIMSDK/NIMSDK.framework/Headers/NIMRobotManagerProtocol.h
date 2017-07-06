//
//  NIMRobotManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2017 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
@class NIMRobot;

NS_ASSUME_NONNULL_BEGIN

/**
 *  机器人管理器
 */
@protocol NIMRobotManager <NSObject>

/**
 *  获取所有的机器人
 *  @return 所有机器人信息
 */
- (nullable NSArray<NIMRobot *> *)allRobots;

/**
 *  是否是有效的机器人
 *
 *  @param userId 用户Id (机器人在云信的id)
 *  @return 是否是机器人
 */
- (BOOL)isValidRobot:(NSString *)userId;


/**
 *  好友操作类型
 *  @param userId 用户Id (机器人在云信的id)
 *  @return 机器人信息
 */
- (nullable NIMRobot *)robotInfo:(NSString *)userId;


@end

NS_ASSUME_NONNULL_END
