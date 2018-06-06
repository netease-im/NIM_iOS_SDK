//
//  NIMAVChatNetDetectManagerProtocol.h
//  NIMAVChat
//
//  Created by Netease.
//  Copyright (c) 2016 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMAVChatDefs.h"
NS_ASSUME_NONNULL_BEGIN

@class NIMAVChatNetDetectResult;

/**
 网络探测类型
 */
typedef NS_ENUM(NSUInteger, NIMAVChatNetDetectType)
{
    /**
     *  音频探测
     */
    NIMAVChatNetDetectTypeAudio = 0,
    /**
     *  默认清晰度 （视频探测）
     */
    NIMAVChatNetDetectTypeDefault ,
    /**
     *  低视频质量 （视频探测）
     */
    NIMAVChatNetDetectTypeLow  ,
    /**
     *  中等视频质量 （视频探测）
     */
    NIMAVChatNetDetectTypeMedium ,
    /**
     *  高视频质量 （视频探测）
     */
    NIMAVChatNetDetectTypeHigh ,
    /**
     *  480P （视频探测）
     */
    NIMAVChatNetDetectType480P ,
    /**
     *  540P （视频探测）
     */
    NIMAVChatNetDetectType540P ,
    /**
     *  720P （视频探测）
     */
    NIMAVChatNetDetectType720P ,
};

/**
 网络探测结果 Block

 @param result 网络探测的结果
 */
typedef void(^NIMAVChatNetDetectCompleteBlock)(NIMAVChatNetDetectResult *result);

/**
 *  音视频实时会话网络探测管理类
 */
@protocol NIMAVChatNetDetectManager <NSObject>

/**
 *  开始网络探测任务
 *
 *  @param detectType 探测类型 包括音频探测 及6种清晰度的视频探测
 *
 *  @param completion 任务完成 block
 *
 *  @return 开始的网络探测任务的 id，可以用该 id 停止该任务，如果返回 0 表示开始失败
 */
- (UInt64)startDetectTaskForDetectType:(NIMAVChatNetDetectType)detectType
                            completion:(NIMAVChatNetDetectCompleteBlock)completion;


/**
 *  停止网络探测任务
 *
 *  @param taskId 需要停止的任务的 id
 */
- (void)stopDetectTask:(UInt64)taskId;

/**
 *  获得 SDK 网络探测 log 文件路径
 *
 *  @return 网络探测 log 文件路径
 */
- (NSString *)logFilepath;

@end

NS_ASSUME_NONNULL_END
