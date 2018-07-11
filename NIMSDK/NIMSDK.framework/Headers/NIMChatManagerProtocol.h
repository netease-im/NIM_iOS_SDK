//
//  NIMChatManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NIMMessage;
@class NIMSession;
@class NIMMessageReceipt;
@class NIMRevokeMessageNotification;
@class NIMTeamMessageReceiptDetail;

NS_ASSUME_NONNULL_BEGIN

/**
 *  P2P 发送已读回执 Block
 *
 *  @param error 错误信息,如果成功,error 为 nil
 */
typedef void(^NIMSendMessageReceiptBlock)(NSError * __nullable error);

/**
 *  Team 发送已读回执 Block
 *
 *  @param error 错误信息,如果成功,error 为 nil
 *  @param failedReceipts 失败的回执
 */
typedef void(^NIMSendTeamMessageReceiptsBlock)(NSError * __nullable error,NSArray<NIMMessageReceipt *> * __nullable failedReceipts);

/**
 *  撤回消息Block
 *
 *  @param error 错误信息,如果成功,error 为 nil
 */
typedef void(^NIMRevokeMessageBlock)(NSError * __nullable error);

/**
 *  查询群组消息回执详情Block
 *
 *  @param error      错误,如果成功则error为nil
 *  @param detail     已读回执详情
 */
typedef void(^NIMQueryReceiptDetailBlock)(NSError * __nullable error,NIMTeamMessageReceiptDetail * __nullable detail);



/**
 *  聊天委托
 */
@protocol NIMChatManagerDelegate <NSObject>

@optional
/**
 *  即将发送消息回调
 *  @discussion 因为发消息之前可能会有个准备过程,所以需要在收到这个回调时才将消息加入到 Datasource 中
 *  @param message 当前发送的消息
 */
- (void)willSendMessage:(NIMMessage *)message;


/**
 *  上传资源文件成功的回调
 *  @discussion 对于需要上传资源的消息(图片，视频，音频等)，SDK 将在上传资源成功后通过这个接口进行回调，上层可以在收到该回调后进行推送信息的重新配置 (APNS payload)
 *  @param urlString 当前消息资源获得的 url 地址
 *  @param message 当前发送的消息
 */
- (void)uploadAttachmentSuccess:(NSString *)urlString
                     forMessage:(NIMMessage *)message;

/**
 *  发送消息进度回调
 *
 *  @param message  当前发送的消息
 *  @param progress 进度
 */
- (void)sendMessage:(NIMMessage *)message
           progress:(float)progress;

/**
 *  发送消息完成回调
 *
 *  @param message 当前发送的消息
 *  @param error   失败原因,如果发送成功则error为nil
 */
- (void)sendMessage:(NIMMessage *)message
    didCompleteWithError:(nullable NSError *)error;


/**
 *  收到消息回调
 *
 *  @param messages 消息列表,内部为NIMMessage
 */
- (void)onRecvMessages:(NSArray<NIMMessage *> *)messages;


/**
 *  收到消息回执
 *
 *  @param receipts 消息回执数组
 *  @discussion 当上层收到此消息时所有的存储和 model 层业务都已经更新，只需要更新 UI 即可。
 */
- (void)onRecvMessageReceipts:(NSArray<NIMMessageReceipt *> *)receipts;


/**
 *  收到消息被撤回的通知
 *
 *  @param notification 被撤回的消息信息
 *  @discusssion 云信在收到消息撤回后，会先从本地数据库中找到对应消息并进行删除，之后通知上层消息已删除
 */
- (void)onRecvRevokeMessageNotification:(NIMRevokeMessageNotification *)notification;


/**
 *  收取消息附件回调
 *  @param message  当前收取的消息
 *  @param progress 进度
 *  @discussion 附件包括:图片,视频的缩略图,语音文件
 */
- (void)fetchMessageAttachment:(NIMMessage *)message
                      progress:(float)progress;


/**
 *  收取消息附件完成回调
 *
 *  @param message 当前收取的消息
 *  @param error   错误返回,如果收取成功,error为nil
 */
- (void)fetchMessageAttachment:(NIMMessage *)message
          didCompleteWithError:(nullable NSError *)error;

@end


/**
 *  聊天协议
 */
@protocol NIMChatManager <NSObject>

/**
 *  发送消息
 *
 *  @param message 消息
 *  @param session 接受方
 *  @param error   错误 如果在准备发送消息阶段发生错误,这个error会被填充相应的信息
 *
 *  @return 是否调用成功,这里返回的 result 只是表示当前这个函数调用是否成功,需要后续的回调才能够判断消息是否已经发送至服务器
 */
- (BOOL)sendMessage:(NIMMessage *)message
          toSession:(NIMSession *)session
              error:(NSError * __nullable *)error;

/**
 *  重发消息
 *
 *  @param message 重发消息
 *  @param error   错误 如果在准备发送消息阶段发生错误,这个error会被填充相应的信息
 *
 *  @return 是否调用成功,这里返回的 result 只是表示当前这个函数调用是否成功,需要后续的回调才能够判断消息是否已经发送至服务器
 */
- (BOOL)resendMessage:(NIMMessage *)message
                error:(NSError * __nullable *)error;


/**
 *  转发消息
 *
 *  @param message 消息
 *  @param session 接收方
 *  @param error   错误 如果在准备发送消息阶段发生错误,这个error会被填充相应的信息
 *
 *  @return 是否调用成功,这里返回的 result 只是表示当前这个函数调用是否成功,需要后续的回调才能够判断消息是否已经发送至服务器
 */
- (BOOL)forwardMessage:(NIMMessage *)message
             toSession:(NIMSession *)session
                 error:(NSError * __nullable *)error;


/**
 *  发送已读回执 (P2P)
 *
 *  @param receipt    已读回执
 *  @param completion 完成回调
 *  @discussion 此接口仅适用于 P2P 消息，群消息已读回执使用 sendTeamMessageReceipts:completion 如果已有比当前已读回执时间戳更大的已读回执已确认，则接口返回成功。
 */
- (void)sendMessageReceipt:(NIMMessageReceipt *)receipt
                completion:(nullable NIMSendMessageReceiptBlock)completion;


/**
 *  发送已读回执 (Team 批量接口)
 *
 *  @param receipts   已读回执
 *  @param completion 完成回调
 *  @discussion 此接口仅适用于 Team 消息。
 */
- (void)sendTeamMessageReceipts:(NSArray<NIMMessageReceipt *> *)receipts
                     completion:(nullable NIMSendTeamMessageReceiptsBlock)completion;


/**
 *  刷新群组消息已读、未读数量
 *
 *  @param messages      要查询的消息集合
 *  @discussion          消息已读变化后，会通过 NIMChatManager 的代理 onRecvMessageReceipts: 回调给上层
 *                       刷新的消息必须为群组消息
 */
- (void)refreshTeamMessageReceipts:(NSArray<NIMMessage *> *)messages;


/**
 *  查询群组消息回执详情
 *
 *  @param message       要查询的消息
 *  @param completion    完成后的回调
 *  @discussion          详情包括已读人数的 id 列表和未读人数的 id 列表
 *                       查询详情对象不会跟着回执人数变化而变化，如果要获取最新的详情，必须再次调用此接口
 *
 */
- (void)queryMessageReceiptDetail:(NIMMessage *)message
                       completion:(NIMQueryReceiptDetailBlock)completion;


/**
 *  撤回消息
 *
 *  @param message    需要被撤回的消息
 *  @param completion 完成回调
 */
- (void)revokeMessage:(NIMMessage *)message
           completion:(nullable NIMRevokeMessageBlock)completion;


/**
 *  收取消息附件
 *
 *  @param message 需要收取附件的消息
 *  @param error   错误
 *
 *  @return 是否调用成功
 *  @discussion 附件包括：图片消息的图片缩略图，视频消息的视频缩略图，音频消息的音频文件，文件消息的文件以及自定义消息中的自定义文件
 *              个人和群组消息 SDK 会在收到该消息时自动调用本接口，自动下载除 "文件消息的文件" 外的所有附件内容
 *
 */
- (BOOL)fetchMessageAttachment:(NIMMessage *)message
                         error:(NSError * __nullable *)error;



/**
 *  取消收取消息附件
 *
 *  @param message 需要取消收取附件的消息
 *
 *  @discussion 附件包括：图片消息的图片缩略图，视频消息的视频缩略图，音频消息的音频文件，文件消息的文件以及自定义消息中的自定义文件
 *              个人和群组消息。SDK 不会触发任何下载回调
 */
- (void)cancelFetchingMessageAttachment:(NIMMessage *)message;

/**
 *  消息是否正在传输 (发送/接受附件)
 *
 *  @param message 消息
 *
 *  @return 是否正在传输
 */
- (BOOL)messageInTransport:(NIMMessage *)message;

/**	
 *  传输消息的进度 (发送/接受附件)
 *
 *  @param message 消息
 *
 *  @return 正在传输的消息进度,如果消息不在传输,则返回0
 */
- (float)messageTransportProgress:(NIMMessage *)message;

/**
 *  添加聊天委托
 *
 *  @param delegate 聊天委托
 */
- (void)addDelegate:(id<NIMChatManagerDelegate>)delegate;

/**
 *  移除聊天委托
 *
 *  @param delegate 聊天委托
 */
- (void)removeDelegate:(id<NIMChatManagerDelegate>)delegate;
@end

NS_ASSUME_NONNULL_END
