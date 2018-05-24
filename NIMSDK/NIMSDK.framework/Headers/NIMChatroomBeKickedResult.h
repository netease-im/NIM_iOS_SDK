//
//  NIMChatroomBeKickedResult.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2018年 Netease. All rights reserved.
//

#import "NIMChatroomManagerProtocol.h"
NS_ASSUME_NONNULL_BEGIN

/**
 *  聊天室被踢结果
 */
@interface NIMChatroomBeKickedResult : NSObject

/**
 *  被踢的聊天室 Id
 */
@property (nonatomic, copy)      NSString    *roomId;

/**
 *  被踢的原因
 */
@property (nonatomic, assign)    NIMChatroomKickReason   reason;

/**
 *  被踢的扩展字段
 */
@property (nonatomic, copy)      NSString    *ext;

@end

NS_ASSUME_NONNULL_END
