//
//  NIMSubscribeResult.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NIMSubscribeResult : NSObject

/**
 *  事件类型
 */
@property (nonatomic, assign, readonly) NSInteger type;

/**
 *  订阅有效期
 */
@property (nonatomic, assign, readonly) NSTimeInterval expiry;


/**
 *  订阅时间
 */
@property (nonatomic, assign, readonly) NSTimeInterval timestamp;


/**
 *  订阅发布事件者的 Id
 */
@property (nonatomic, copy, readonly) NSString *publisher;


@end
