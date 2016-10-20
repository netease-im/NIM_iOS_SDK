//
//  NIMAVChat.h
//  NIMAVChat
//
//  Created by Netease
//  Copyright © 2016 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMSDK.h"

/**
 *  实时会话选项定义
 */
#import "NIMRTSManagerProtocol.h"
#import "NIMRTSOption.h"
#import "NIMRTSRecordingInfo.h"

/**
 *  音视频网络通话定义
 */
#import "NIMNetCallDefs.h"
#import "NIMNetCallManagerProtocol.h"
#import "NIMNetCallOption.h"
#import "NIMNetCallRecordingInfo.h"
#import "NIMNetCallMeeting.h"
#import "NIMNetCallUserInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  NIMSDK NIMAVChat Category
 */
@interface NIMSDK (NIMAVChat)

/**
 *  网络通话管理类
 */
@property (nonatomic,strong,readonly)   id<NIMNetCallManager> netCallManager;

/**
 *  实时会话管理类
 */
@property (nonatomic,strong,readonly)   id<NIMRTSManager> rtsManager;

@end

NS_ASSUME_NONNULL_END
