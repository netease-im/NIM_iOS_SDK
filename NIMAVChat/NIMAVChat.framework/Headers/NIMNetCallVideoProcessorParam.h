//
//  NIMNetCallVideoProcessorParam.h
//  NIMAVChat
//
//  Created by Simon Blue on 2017/11/30.
//  Copyright © 2017年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMAVChatDefs.h"

/**
 *  水印参数
 */
@interface NIMNetCallVideoWaterMarkParam : NSObject

/**
 *   水印图片 (静态水印需要指定)
 */
@property(nonatomic,strong)UIImage *image;

/**
 *   具体位置和大小（x，y根据location位置，计算具体的位置信息）
 */
@property(nonatomic)CGRect rect;

/**
 *   位置 默认右上
 */
@property(nonatomic)NIMNetCallWaterMarkLocation location;

/**
 *   动态图像数组 (动态水印需要指定)
 */
@property(nonatomic,strong)NSArray *imageArray;

/**
 *   播放速度的快慢:count代表count帧显示同一张图 (动态水印需要指定)
 */
@property(nonatomic)NSUInteger count;

/**
 *   是否循环，不循环就显示一次 (动态水印需要指定)
 */
@property(nonatomic)BOOL loop;

@end


/**
 *  前处理参数
 */
@interface NIMNetCallVideoProcessorParam : NSObject

/**
 *   美颜类型
 */
@property(nonatomic)NIMNetCallFilterType filterType;

/**
 *   对比度强度 [0-4] 默认为 1
 */
@property(nonatomic)float contrastIntensity;

/**
 *   磨皮强度 [0-1] 默认为 0
 */
@property(nonatomic)float smoothIntensity;

/**
 *   水印参数 如果需要在通话开始时添加请指定
 */
@property(nonatomic,strong)NIMNetCallVideoWaterMarkParam *waterMarkParam;

@end
