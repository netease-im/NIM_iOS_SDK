//
//  NIMAVChatDefs.h
//  NIMAVChat
//
//  Created by fenric on 16/10/28.
//  Copyright © 2016年 Netease. All rights reserved.
//

#ifndef NIMAVChatDefs_h
#define NIMAVChatDefs_h

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
 *  网络通话类型
 */
typedef NS_ENUM(NSInteger, NIMNetCallMediaType){
    /**
     *  音频通话
     */
    NIMNetCallMediaTypeAudio = 1,
    /**
     *  视频通话
     */
    NIMNetCallMediaTypeVideo = 2,
};


/**
 *  视频混频模式, 用于互动直播连麦时的视频混频参数设置
 */
typedef NS_ENUM(NSUInteger, NIMNetCallVideoMixMode) {
    /**
     *  右侧纵排浮窗(画中画)
     */
    NIMNetCallVideoMixModeFloatingRightVertical  = 0,
    /**
     *  左侧纵排浮窗(画中画)
     */
    NIMNetCallVideoMixModeFloatingLeftVertical   = 1,
    /**
     *  分格平铺, 显示完整画面, 不裁剪
     */
    NIMNetCallVideoMixModeLatticeAspectFit       = 2,
    /**
     *  分格平铺, 填满区域, 可能裁剪
     */
    NIMNetCallVideoMixModeLatticeAspectFill      = 3,
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
     *  网络通话没有启动
     */
    NIMNetCallErrorCodeNotStarted         = 20001,
    /**
     *  操作失败
     */
    NIMNetCallErrorCodeOperationFailed    = 20002,
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
    NIMNetCallErrorCodeBypassSetTimeout   = 20408,
    
    /**
     *  与音视频服务器连接断开
     */
    NIMNetCallErrorCodeServerDisconnected = 20409,
    
    /**
     *  对方超时离开了房间
     */
    NIMNetCallErrorCodePeerLeftForTimeout = 20410,
    
    /**
     *  音频设备异常
     */
    NIMNetCallErrorCodeAudioDeviceError   = 20411,
    
    /**
     *  被踢出了音视频
     */
    NIMNetCallErrorCodeBeKicked           = 20412,


};


/**
 *  本地错误码 （AV） Doamin: NIMLocalErrorDomain
 */
typedef NS_ENUM(NSInteger, NIMAVLocalErrorCode) {
    /**
     *  无法开始录制, 因为文件路径不合法
     */
    NIMAVLocalErrorCodeRecordInvalidFilePath       = 17,
    /**
     *  开始录制失败
     */
    NIMAVLocalErrorCodeRecordStartFailed           = 18,
    
    /**
     *  创建录制文件失败
     */
    NIMAVLocalErrorCodeRecordCreateFileFailed      = 19,
    
    /**
     *  初始化录制音频失败
     */
    NIMAVLocalErrorCodeRecordInitAudioFailed       = 20,
    
    /**
     *  初始化录制视频失败
     */
    NIMAVLocalErrorCodeRecordInitVideoFailed       = 21,
    
    /**
     *  开始写录制文件失败
     */
    NIMAVLocalErrorCodeRecordStartWritingFailed    = 22,
    
    /**
     *  结束录制失败
     */
    NIMAVLocalErrorCodeRecordStopFailed            = 23,
    
    /**
     *  写录制文件失败
     */
    NIMAVLocalErrorCodeRecordWritingFileFailed     = 24,
    
    /**
     *  空间不足，录制即将结束
     */
    NIMAVLocalErrorCodeRecordWillStopForLackSpace  = 25,
    
    /**
     *  操作尚未完成
     */
    NIMAVLocalErrorCodeOperationIncomplete         = 27,
    /**
     *  连接网络通话服务器超时
     */
    NIMAVLocalErrorCodeNetCallConnectTimeout       = 29,
    /**
     *  非互动直播用户无法加入开启互动直播的房间，互动直播用户指主播和连麦者
     */
    NIMAVLocalErrorCodeNetCallCannotJoinBypassChannel = 30,
    /**
     *  该频道超过了互动直播房间用户数限制: 每个房间只能有一个主播和一个连麦者
     */
    NIMAVLocalErrorCodeNetCallTooManyBypassStreamers = 31,
    /**
     *  该房间超过了互动直播主播数限制: 每个房间只能有一个主播和一个连麦者
     */
    NIMAVLocalErrorCodeNetCallTooManyBypassStreamingHosts = 32,
    /**
     *  主播尚未加入互动直播房间，连麦者无法在主播之前加入
     */
    NIMAVLocalErrorCodeNetCallHostNotJoined = 33,
    
};

/**
 *  服务器错误码 （AV） Doamin: NIMRemoteErrorDomain
 *  @discussion 更多错误详见 http://dev.netease.im/docs?doc=nim_status_code#服务器端状态码
 */
typedef NS_ENUM(NSInteger, NIMAVRemoteErrorCode) {
    /**
     *  被叫离线(无可送达的被叫方)
     */
    NIMAVRemoteErrorCodeCalleeOffline       = 11001,
};




/**
 *  用户离开多人实时会话的原因
 */
typedef NS_ENUM(NSUInteger, NIMRTSConferenceUserLeaveReason) {
    /**
     *  正常离开
     */
    NIMRTSConferenceUserLeaveReasonNormal,
    /**
     *  超时离开
     */
    NIMRTSConferenceUserLeaveReasonTimeout,
};



/**
 *  NIM 多人实时会话 Error Domain
 */
extern NSString *const NIMRTSConferenceErrorDomain;

/**
 *  多人实时会话错误码
 */
typedef NS_ENUM(NSInteger, NIMRTSConferenceErrorCode) {
    /**
     *  与服务器连接已断开
     */
    NIMRTSConferenceErrorCodeServerDisconnected = 21001,

};


/***********                            老版本写法错误码兼容                              **************/

#define NIMLocalErrorCodeRecordInvalidFilePath                  NIMAVLocalErrorCodeRecordInvalidFilePath
#define NIMLocalErrorCodeRecordStartFailed                      NIMAVLocalErrorCodeRecordStartFailed
#define NIMLocalErrorCodeRecordCreateFileFailed                 NIMAVLocalErrorCodeRecordCreateFileFailed
#define NIMLocalErrorCodeRecordInitAudioFailed                  NIMAVLocalErrorCodeRecordCreateFileFailed
#define NIMLocalErrorCodeRecordInitVideoFailed                  NIMAVLocalErrorCodeRecordInitVideoFailed
#define NIMLocalErrorCodeRecordStartWritingFailed               NIMAVLocalErrorCodeRecordStartWritingFailed
#define NIMLocalErrorCodeRecordStopFailed                       NIMAVLocalErrorCodeRecordStopFailed
#define NIMLocalErrorCodeRecordWritingFileFailed                NIMAVLocalErrorCodeRecordWritingFileFailed
#define NIMLocalErrorCodeRecordWillStopForLackSpace             NIMAVLocalErrorCodeRecordWillStopForLackSpace
#define NIMLocalErrorCodeOperationIncomplete                    NIMAVLocalErrorCodeOperationIncomplete
#define NIMLocalErrorCodeNetCallConnectTimeout                  NIMAVLocalErrorCodeNetCallConnectTimeout
#define NIMLocalErrorCodeNetCallCannotJoinBypassChannel         NIMAVLocalErrorCodeNetCallCannotJoinBypassChannel
#define NIMLocalErrorCodeNetCallTooManyBypassStreamers          NIMAVLocalErrorCodeNetCallTooManyBypassStreamers
#define NIMLocalErrorCodeNetCallTooManyBypassStreamingHosts     NIMAVLocalErrorCodeNetCallTooManyBypassStreamingHosts
#define NIMLocalErrorCodeNetCallHostNotJoined                   NIMAVLocalErrorCodeNetCallHostNotJoined
#define NIMNetCallLocalErrorCodeUserInfoNeeded                  (16)


#define NIMRemoteErrorCodeCalleeOffline                         NIMAVRemoteErrorCodeCalleeOffline



#endif /* NIMAVChatDefs_h */
