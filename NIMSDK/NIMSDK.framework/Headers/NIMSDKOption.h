//
//  NIMSDKOption.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



/**
 * 注册选项
 */
@interface NIMSDKOption : NSObject

/**
 *  云信 AppKey
 */
@property (nonatomic,copy)          NSString    *appKey;

/**
 *  云信 Apns 推送证书名
 */
@property (nullable,nonatomic,copy)  NSString    *apnsCername;

/**
 *  云信 PushKit 推送证书名
 */
@property (nullable,nonatomic,copy)  NSString    *pkCername;


/**
 *  注册选项初始化方法
 *  @param appKey  云信 AppKey
 */
+ (instancetype)optionWithAppKey:(NSString *)appKey;

@end

NS_ASSUME_NONNULL_END
