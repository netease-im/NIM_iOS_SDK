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
 *  机器人获取 block
 *
 *  @param error   错误,如果成功则error为nil
 *  @param robots  成功的机器人列表,内部为 NIMRobot
 */
typedef void(^NIMRobotsHandler)(NSError * __nullable error, NSArray<NIMRobot *> * __nullable robots);

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
 *  获取机器人信息
 *  @param userId 用户Id (机器人在云信的id)
 *  @return 机器人信息
 */
- (nullable NIMRobot *)robotInfo:(NSString *)userId;



/**
 *  远程获取机器人信息
 *  @param completion 机器人获取回调
 */
- (void)fetchAllRobotsFromServer:(nullable NIMRobotsHandler)completion;


@end

NS_ASSUME_NONNULL_END
