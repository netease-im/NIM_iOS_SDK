//
//  NIMServerSetting.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN


/**
 *  云信服务器配置
 */
@interface NIMServerSetting : NSObject
/**
 * IM 服务器 lbs 地址
 */
@property (nonatomic,copy)              NSString    *lbsAddress;
/**
 * NOS 服务器 lbs 地址
 */
@property (nonatomic,copy)              NSString    *nosLbsAddress;
/**
 * IM 服务器默认地址
 */
@property (nonatomic,copy)              NSString    *linkAddress;
/**
 * 是否开启 HTTPS 支持
 * @discussion 默认情况为 YES，若需要使用非 HTTPS 进行文件上传下载，则设置为 NO。
 * 如果设置为 YES，上传将使用 https 上传，所有返回 url 的地方也会尝试将 http url 调整为 https url
 * 如果设置为 NO，上传将使用 http 上传，而所有返回 url 的地方都只返回原 url，而不做任何处理，同时 `SDKConfig` 中 `enabledHttpsForInfo` 和 `enabledHttpsForMessage` 将无效
 */
@property (nonatomic,assign)            BOOL       httpsEnabled;
/**
 * NOS 上传服务器默认地址
 */
@property (nonatomic,copy)              NSString    *nosUploadAddress;
/**
 * NOS 上传 Host，用于 HTTPS 上传时 Host 验证
 */
@property (nonatomic,copy,nullable)     NSString    *nosUploadHost;
/**
 * NOS 下载地址，用于拼接下载地址
 */
@property (nonatomic,copy)              NSString    *nosDownloadAddress;

/**
 * NOS 加速 Host
 */
@property (nonatomic,copy,nullable)     NSString    *nosAccelerateHost;
/**
 * NOS 加速替换地址
 */
@property (nonatomic,copy,nullable)     NSString    *nosAccelerateAddress;
/**
 * NRTC 服务器地址
 */
@property (nonatomic,copy)              NSString    *nrtcServerAddress;
/**
 * NT 服务器地址
 */
@property (nonatomic,copy)              NSString    *ntServerAddress;
/**
 * module
 */
@property (nonatomic,copy)              NSString    *module;
/**
 * 版本
 */
@property (nonatomic,assign)            NSInteger   version;
@end

NS_ASSUME_NONNULL_END
