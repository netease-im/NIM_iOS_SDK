//
//  NIMMediaManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  音频输出设备类型
 */
typedef NS_ENUM(NSInteger, NIMAudioOutputDevice){
    /**
     *  听筒
     */
    NIMAudioOutputDeviceReceiver,
    /**
     *  扬声器
     */
    NIMAudioOutputDeviceSpeaker
};

/**
 *  多媒体委托
 */
@protocol NIMMediaManagerDelgate <NSObject>

@optional

/**
 *  开始播放音频的回调
 *
 *  @param filePath 音频文件路径
 *  @param error    错误信息
 */
- (void)playAudio:(NSString *)filePath didBeganWithError:(NSError *)error;

/**
 *  播放完音频的回调
 *
 *  @param filePath 音频文件路径
 *  @param error    错误信息
 */
- (void)playAudio:(NSString *)filePath didCompletedWithError:(NSError *)error;

/**
 *  播放音频开始被打断回调
 */
- (void)playAudioInterruptionBegin;

/**
 *  播放音频结束被打断回调
 */
- (void)playAudioInterruptionEnd;

/**
 *  开始录制音频的回调
 *
 *  @param filePath 录制的音频的文件路径
 *  @param error    错误信息
 */
- (void)recordAudio:(NSString *)filePath didBeganWithError:(NSError *)error;

/**
 *  录制音频完成后的回调
 *
 *  @param filePath 录制完成的音频文件路径
 *  @param error    错误信息
 */
- (void)recordAudio:(NSString *)filePath didCompletedWithError:(NSError *)error;

/**
 *  录音被取消的回调
 */
- (void)recordAudioDidCancelled;

/**
 *  音频录制进度更新回调
 *
 *  @param currentTime 当前录制的时间
 */
- (void)recordAudioProgress:(NSTimeInterval)currentTime;

/**
 *  录音开始被打断回调
 */
- (void)recordAudioInterruptionBegin;

/**
 *  录音结束被打断回调
 */
- (void)recordAudioInterruptionEnd;

@end

/**
 *  多媒体控制协议
 */
@protocol NIMMediaManager <NSObject>

@required

/**
 *  录音进度更新间隔
 *  @discussion 如果值大于0，则会按照相应间隔调用recordAudioProgress:回调,默认值为0.3
 */
@property (nonatomic, assign) NSTimeInterval recordProgressUpdateTimeInterval;

#pragma mark - play audio
/**
 *  切换音频输出设备
 *
 *  @param outputDevice 音频输出设备
 *
 *  @return 是否切换成功
 */
- (BOOL)switchAudioOutputDevice:(NIMAudioOutputDevice)outputDevice;

/**
 *  是否正在播放音频
 *
 */
- (BOOL)isPlaying;

/**
 *  播放音频文件
 *
 *  @discussion 开始播放，NIMMediaManagerDelgate中的playAudio:didBeganWithError:回调会被触发，播放完成后, NIMMediaManagerDelgate中的playAudio:didCompletedWithError:回调会被触发
 *  @param filePath 音频文件路径
 *  @param delegate NIMMediaManagerDelgate
 */
- (void)playAudio:(NSString *)filePath withDelegate:(id<NIMMediaManagerDelgate>)delegate;

/**
 *  停止播放音频
 *
 *  @discussion 音频播放完成后NIMMediaManagerDelgate中的playAudio:didCompletedWithError:回调会被触发
 */
- (void)stopPlay;

#pragma mark - record audio

/**
 *  是否正在录音
 *
 */
- (BOOL)isRecording;

/**
 *  开始录制音频
 *
 *  @discussion 开始录音，NIMMediaManagerDelgate中的recordAudio:didBeganWithError:回调会被触发，录音完成后, NIMMediaManagerDelgate中的recordAudio:didCompletedWithError:回调会被触发
 *  @param duration 最长录音时间
 *  @param delegate NIMMediaManagerDelgate
 */
- (void)recordAudioForDuration:(NSTimeInterval)duration withDelegate:(id<NIMMediaManagerDelgate>)delegate;

/**
 *  停止录制音频
 *
 *  @discussion 停止录音后NIMMediaManagerDelgate中的recordAudio:didCompletedWithError:回调会被触发
 */
- (void)stopRecord;

/**
 *  取消录制音频
 *
 *  @discussion 录音取消后，NIMMediaManagerDelgate中的recordAudioDidCancelled回调会被触发
 */
- (void)cancelRecord;

/**
 *  获取录音分贝
 *
 */
- (float)recordPeakPower;

/**
 *  获取录音分贝
 *
 */
- (float)recordAveragePower;

@end
