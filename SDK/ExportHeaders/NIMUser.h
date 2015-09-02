//
//  NIMUser.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  好友操作类型
 */
typedef NS_ENUM(NSInteger, NIMUserOperation){
    /**
     *  添加好友
     *  @discussion 直接添加为好友,无需验证
     */
    NIMUserOperationAdd     =   1,
    /**
     *  请求添加好友
     */
    NIMUserOperationRequest =   2,
    /**
     *  通过添加好友请求
     */
    NIMUserOperationVerify  =   3,
    /**
     *  拒绝添加好友请求
     */
    NIMUserOperationReject  =   4,
};



/**
 *  云信用户
 */
@interface NIMUser : NSObject

/**
 *  用户Id
 */
@property (nonatomic,copy,readonly)  NSString    *userId;

/**
 *  是否需要消息提醒
 *
 *  @return 是否需要消息提醒
 */
- (BOOL)notifyForNewMsg;

/**
 *  是否在黑名单中
 *
 *  @return 是否在黑名单中
 */

- (BOOL)isInMyBlackList;

@end


/**
 *  好友请求
 */
@interface NIMUserRequest : NSObject
/**
 *  目标用户ID
 */
@property (nonatomic,copy)      NSString            *userId;

/**
 *  操作类型
 */
@property (nonatomic,assign)    NIMUserOperation    operation;

/**
 *  附言
 *  @dicussion 
 */
@property (nonatomic,copy)      NSString            *message;

@end
