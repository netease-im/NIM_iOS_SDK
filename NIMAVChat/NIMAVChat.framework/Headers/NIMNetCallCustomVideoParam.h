//
//  NIMNetCallCustomVideoParam.h
//  NIMAVChat
//
//  Created by Netease on 2017/7/17.
//  Copyright © 2017年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CMSampleBuffer.h>
#import "NIMAVChatDefs.h"

@class NIMNetCallVideoProcessorParam;

/**
 *  自定义视频输入参数
 */
@interface NIMNetCallCustomVideoParam : NSObject<NSCopying>

/**
 *  编码帧率
 */
@property (nonatomic, assign) NSUInteger videoFrameRate;

/**
 * 视频前处理参数，如需开启前处理请指定该参数，不指定将不开启前处理。
 
 @discussion 如果需要在通话开始时就已添加美颜，水印等前处理，请指定该参数中对应的参数。
 */
@property (nonatomic, strong) NIMNetCallVideoProcessorParam *videoProcessorParam;

@end
