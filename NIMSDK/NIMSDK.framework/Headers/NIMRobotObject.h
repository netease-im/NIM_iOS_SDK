//
//  NIMRobotObject.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017年 Netease. All rights reserved.
//

#import "NIMMessageObjectProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  机器人消息附件实例对象
 */
@interface NIMRobotObject : NSObject<NIMMessageObject>

/**
 *  机器人消息附件对象构造方法
 * 
 *  @param content 机器人识别内容
 *
 *  @param robotId 机器人 Id
 *
 *  @discussion content 参数不是用来做 UI 显示的， 显示 (如对话气泡) 请用 message.text 字段
 *
 *  @return  机器人消息附件对象实例
 */
- (instancetype)initWithRobot:(NSString *)content
                      robotId:(NSString *)robotId;


/**
 *  机器人消息附件对象构造方法
 *
 *  @param robotId  机器人 Id
 *
 *  @param target   模块 Id
 *
 *  @param param    模块跳转参数
 *
 *  @return  机器人消息附件对象实例
 */
- (instancetype)initWithRobotId:(NSString *)robotId
                         target:(NSString *)target
                          param:(NSString *)param;


/**
 *  判断此消息是否是属于机器人回复的消息
 */
@property (nonatomic, assign, readonly) BOOL isFromRobot;

/**
 *  当该消息为用户上行发送给机器人时，此字段为目标机器人 Id,
 *  当该消息为机器人回复的消息时, 此字段为本消息所属机器人 Id
 */
@property (nullable, nonatomic, copy, readonly) NSString *robotId;


/**
 *  机器人回复的消息结果，只在机器人下行消息，此字段有效
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary *response;

/**
 *  机器人回复的消息所属的提问消息 Id ，只在机器人下行消息，此字段有效
 */
@property (nullable, nonatomic, copy, readonly) NSString *responseForMessageId;

@end


NS_ASSUME_NONNULL_END
