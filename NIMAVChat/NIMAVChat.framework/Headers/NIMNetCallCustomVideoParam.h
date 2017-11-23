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

/**
 *  自定义视频输入参数
 */
@interface NIMNetCallCustomVideoParam : NSObject<NSCopying>

/**
 *  编码帧率
 */
@property (nonatomic, assign) NSUInteger videoFrameRate;

/**
 *  提供对自定义输入视频的前处理功能
 */
@property (nonatomic, assign) BOOL provideVideoProcess;

@end
