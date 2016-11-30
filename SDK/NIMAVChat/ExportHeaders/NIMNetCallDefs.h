//
//  NIMNetCallDefs.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2016年 Netease. All rights reserved.
//

#ifndef NIMLib_NIMNetCallDefs_h
#define NIMLib_NIMNetCallDefs_h

/**
 *  网络通话视频质量
 */
typedef NS_ENUM(NSInteger, NIMNetCallVideoQuality) {
    /**
     *  默认视频质量
     */
    NIMNetCallVideoQualityDefault    = 0,
    /**
     *  低视频质量
     */
    NIMNetCallVideoQualityLow        = 1,
    /**
     *  中等视频质量
     */
    NIMNetCallVideoQualityMedium     = 2,
    /**
     *  高视频质量
     */
    NIMNetCallVideoQualityHigh       = 3,
    /**
     *  480P等级视频质量
     */
    NIMNetCallVideoQuality480pLevel  = 4,
    /**
     *  720P等级视频质量
     */
    NIMNetCallVideoQuality720pLevel  = 5,

};


/**
 *  视频编码器
 */
typedef NS_ENUM(NSUInteger, NIMNetCallVideoCodec) {
    /**
     *  默认编解码器, SDK 自己选择合适的编码器
     */
    NIMNetCallVideoCodecDefault = 0,
    /**
     *  软件编解码
     */
    NIMNetCallVideoCodecSoftware = 1,
    /**
     *  硬件编解码. 注意: 硬件编解码只在 iOS 8.0 及以上系统适用
     */
    NIMNetCallVideoCodecHardware = 2,
};


/**
 *  视频帧率
 */
typedef NS_ENUM(NSUInteger, NIMNetCallVideoFrameRate) {
    /**
     *  SDK 支持的最小帧率
     */
    NIMNetCallVideoFrameRateMin = 0,
    /**
     *  5 FPS
     */
    NIMNetCallVideoFrameRate5FPS,
    /**
     *  10 FPS
     */
    NIMNetCallVideoFrameRate10FPS,
    /**
     *  15 FPS
     */
    NIMNetCallVideoFrameRate15FPS,
    /**
     *  20 FPS
     */
    NIMNetCallVideoFrameRate20FPS,
    /**
     *  25 FPS
     */
    NIMNetCallVideoFrameRate25FPS,
    /**
     *  缺省帧率
     */
    NIMNetCallVideoFrameRateDefault,
    /**
     *  SDK 支持的最大帧率
     */
    NIMNetCallVideoFrameRateMax,
};


/**
 *  NIM 网络通话 Error Domain
 */
extern NSString *const NIMNetCallErrorDomain;

/**
 *  网络通话错误码
 */
typedef NS_ENUM(NSInteger, NIMNetCallErrorCode) {
    /**
     *  超过最大允许直播节点数量
     */
    NIMNetCallErrorCodeBypassSetExceedMax = 20202,
    
    /**
     *  必须由主播第一个开启直播
     */
    NIMNetCallErrorCodeBypassSetHostNotJoined = 20203,
    
    /**
     *  互动直播服务器错误
     */
    NIMNetCallErrorCodeBypassSetServerError = 20204,
    
    /**
     *  互动直播其他错误
     */
    NIMNetCallErrorCodeBypassSetOtherError = 20205,
    
    /**
     *  互动直播服务器没有响应
     */
    NIMNetCallErrorCodeBypassSetNoResponse = 20404,

    /**
     *  重连过程中无法进行相关操作，稍后再试
     */
    NIMNetCallErrorCodeBypassReconnecting = 20405,

    /**
     *  互动直播设置超时
     */
    NIMNetCallErrorCodeBypassSetTimeout = 20408,
    
};



#endif
