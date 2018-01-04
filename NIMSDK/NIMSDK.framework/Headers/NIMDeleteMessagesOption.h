//
//  NIMDeleteMessagesOption.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 批量删除消息选项
 */
@interface NIMDeleteMessagesOption : NSObject

/**
 *  是否移除对应最近会话
 *  @discussion 批量删除消息时是否移除最近会话，默认为 NO，设置为 YES 时将同时删除最近会话信息
 */
@property   (nonatomic,assign)  BOOL    removeSession;


/**
 *  是否删除消息表
 *  @discussion 默认情况下云信采用标记的方式进行消息删除，如果设置为 YES，将一并移除对应的消息表，进而减少消息表数量，加快 I/O
 */
@property   (nonatomic,assign)  BOOL    removeTable;

@end

NS_ASSUME_NONNULL_END
