//
//  NIMAntiSpamOption.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 反垃圾选项
 * @discussion 这个选项用于配置易盾反垃圾，设置 enabled 为 YES (默认为 NO) 后该消息进投递到易盾系统进行反垃圾检测 （需要开启易盾服务），只对自定义消息有效
 */
@interface NIMAntiSpamOption : NSObject

/**
 * 是否开启易盾反垃圾
 */
@property (nonatomic,assign)            BOOL       yidunEnabled;


/**
 * 需要反垃圾的内容
 */
@property (nullable,nonatomic,copy)     NSString    *content;

/**
 * 用户在易盾配置的额外反垃圾的业务ID
 */
@property (nullable,nonatomic,copy)     NSString    *businessId;


/**
 *  是否命中客户端反垃圾
 *  @discussion 默认为NO，使用 NIMConversationManager 中的 checkLocalAntispam:error: 方法来确定所给文本是否命中客户端本地反垃圾，根据结果填写这个字段
 */
@property (nonatomic,assign)    BOOL        hitClientAntispam;


@end



/**
 * 本地反垃圾检查选项
 * @discussion 这个选项用于反垃圾的本地检查，可以用这个选项进行一些字符串的本地替换操作
 */
@interface NIMLocalAntiSpamCheckOption : NSObject

/**
 * 检查内容
 */
@property (nonatomic,copy)              NSString    *content;


/**
 * 需要替换的字符串
 */
@property (nullable,nonatomic,copy)     NSString    *replacement;


@end


/**
 * 本地反垃圾检查结果类型
 */
typedef NS_ENUM (NSInteger, NIMLocalAntiSpamOperate){
    /**
     *  本地反垃圾列表不存在
     */
    NIMAntiSpamOperateFileNotExists,
    /**
     *  本地替换
     */
    NIMAntiSpamResultLocalReplace,
    /**
     *  本地屏蔽
     */
    NIMAntiSpamResultLocalForbidden,
    /**
     *  服务器屏蔽
     */
    NIMAntiSpamResultServerForbidden,
    /**
     *  没有命中词库，检查通过
     */
    NIMAntiSpamResultNotHit,
};

/**
 * 本地反垃圾检查选项
 * @discussion 这个选项用于反垃圾的本地检查，可以用这个选项进行一些字符串的本地替换操作
 */
@interface NIMLocalAntiSpamCheckResult : NSObject

/**
 * 结果类型
 */
@property (nonatomic, assign, readonly)            NIMLocalAntiSpamOperate type;

/**
 * 替换后的字符串，只有当类型为本地替换时才有效
 */
@property (nonatomic, copy, readonly)              NSString    *content;


@end

NS_ASSUME_NONNULL_END
