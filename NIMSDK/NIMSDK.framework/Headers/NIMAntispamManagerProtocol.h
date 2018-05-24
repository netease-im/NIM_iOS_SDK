//
//  NIMAntispamManagerProtocol.h
//  NIMLib
//
//  Created by chris on 2018/3/9.
//  Copyright © 2018年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@class NIMLocalAntiSpamCheckOption;
@class NIMLocalAntiSpamCheckResult;

/**
 *  反垃圾协议
 */
@protocol NIMAntispamManager <NSObject>

/**
 *  本地反垃圾检查器
 *
 *  @param option        本地反垃圾检查选项
 *  @param error         错误提示
 *  @discussion          此扩展不会漫游到其他端,上层需要保证 NSDictionary 可以转换为 JSON。
 *  @return              本地反垃圾检查结果，本地反垃圾列表会在每次登录后同步更新
 *                       因为网络问题，或者没有登录，都会导致本地反垃圾列表无效的情况，error 中会包含具体出错原因
 */
- (NIMLocalAntiSpamCheckResult *)checkLocalAntispam:(NIMLocalAntiSpamCheckOption *)option
                                              error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
