//
//  ConferenceSDKAgent.h
//  ConferenceSDK
//
//  Created by Setoge on 2020/3/28.
//  Copyright © 2020 taojunfeng. All rights reserved.
//  ConferenceSDK带UI的管理类

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//会议的显示模式
typedef enum {
    CONFERENCEPAGEMODE_COMMON = 1,// 普通模式
    CONFERENCEPAGEMODE_VOICESTIMULATION = 2,//语音激励模式
    CONFERENCEPAGEMODE_GALLERY = 3,//画廊模式
    CONFERENCEPAGEMODE_GALLERY_VOICESTIMULATION = 4,//语音激励模式+画廊模式
    
} CONFERENCEPAGEMODE;

@class ConferenceSDK;
@interface JMeetingSDKAgent : NSObject
/// ConferenceSDK事件的管理类
@property (strong, nonatomic) ConferenceSDK *conferenceSDK;
/// 会议室页面模式
@property (nonatomic,assign) CONFERENCEPAGEMODE pageMode;


+ (JMeetingSDKAgent *)shareManager;
#pragma mark - SDK生命周期
/** 初始化接口  1.异步接口;2.初始化结果通过onInit回调返回;
 @param userID 用户视讯号 (必填)
 @param userName  用户昵称
 @param masterNps  主nps地址appkey 信息(必填)
 @param slaveNps  从nps地址，支  持主从，如果有从地址使用 A|B的格式 (可以传空字符串)
 @param onInit 回调对象 (必发)
 */
- (NSInteger)init:(NSString *)token
           userID:(NSString *)userID
         userName:(NSString *)userName
     masterNewNps:(NSString *)masterNps
      slaveNewNps:(NSString *)slaveNps
           onInit:(InitListener *)onInit;

/** 初始化接口
 1.异步接口;
 2.初始化结果通过onInit回调返回;
 @param accountID 用户视讯号 (必填)
 @param secretID 登录密码  (开户密码明文)  (必填)
 @param appkey appkey 信息(必填)
 @param nps nps地址，支持主从，如果有从地址使用 A|B的格式 (可以传空字符串)
 @param onInit 回调对象 (必发)
 */
- (int)init:(NSString*)accountID
   secretID:(NSString*)secretID
     appkey:(NSString*)appkey
        nps:(NSString*)nps
     onInit:(InitListener *)onInit;


/**  创建会议室
 1. 异步接口；
 2. 创建结果通过onCreateMeeting异步返回；
 3. 如果出现网络异常，最多有30s超时；
 4.回调时会将传递上、下文信息
 @param onCreateMeeting   创建会议回调对象
 @param passWord  设置会议密码

 */
- (int)createMeeting:(CreateMeetingListener *)onCreateMeeting meetingPwd:(NSString *)passWord;


/**  创建并加入会议室
 1. 异步接口；
 2. 创建结果通过onCreateMeeting异步返回；
 3. 如果出现网络异常，最多有30s超时；
 4.回调时会将传递上、下文信息
 @param joinListener   创建会议回调对象
 @param pwd 创建会议的加密参数
 @param viewController        当前所在的viewController
 @return  =0 接口调用成功； -1 未初始化； -2 joinListener调用过程中；  <-2 接口调用失败；
 */

- (int)createAndJoinMeeting:(JoinMeetingListener *) joinListener pwd:(NSString *)pwd viewController:(UIViewController *)viewController;


/** 加入会议<确定会议无密码>
 如果参数meetingId不是当前正在进行的会议，将认为是从会议当中按Home键，然后点击短信邀请跳转过来的，切换到会议室页面后将弹出短信邀请弹框，并通过onEvent返回。
 1.加入会议，异步接口;
 2.加入会议结果通过onEvent返回，onJoinMeeting可以不处理；
 3.joinMeeting调用过程中则同步返回-2；
 4.正在会议过程中则通过onEvent异步返回加入会议；
 
 @param meetingID 需要加入的会议ID
 @param nickName 用户的参会名称
 @param viewController        当前所在的viewController
 @param onJoinMeeting 加入会议接口异步回调对象
 @return  =0 接口调用成功； -1 未初始化； -2 joinMeeting调用过程中；  <-2 接口调用失败；
 */
- (int)joinMeeting:(NSString *)meetingID
          nickName:(NSString*)nickName
    viewController:(UIViewController *)viewController
     onJoinMeeting:(JoinMeetingListener *)onJoinMeeting;

/** 加入会议<会自动校验会议密码>
 如果参数meetingId不是当前正在进行的会议，将认为是从会议当中按Home键，然后点击短信邀请跳转过来的，切换到会议室页面后将弹出短信邀请弹框，并通过onEvent返回。
 1.加入会议，异步接口;
 2.加入会议结果通过onEvent返回，onJoinMeeting可以不处理；
 3.joinMeeting调用过程中则同步返回-2；
 4.正在会议过程中则通过onEvent异步返回加入会议；
 
 @param meetingID 需要加入的会议ID
 @param nickName 用户的参会名称
 @param passWord 会议密码
 @param viewController        当前所在的viewController
 @param onJoinMeeting 加入会议接口异步回调对象
 @return  =0 接口调用成功； -1 未初始化； -2 joinMeeting调用过程中；  <-2 接口调用失败；
 */
- (void)joinMeeting:(NSString *)meetingID
          nickName:(NSString*)nickName
        meetingPwd:(NSString*)passWord
    viewController:(UIViewController *)viewController
     onJoinMeeting:(JoinMeetingListener *)onJoinMeeting;


/**加会时候的默认设置属性 麦克风和摄像头 0 是打开 1是关闭
 @param cameraType 摄像头属性 0 是打开 1是关闭
 @param micType  麦克风属性 0 是打开 1是关闭
 */
- (void)setMeetingCamerState:(int)cameraType micState:(int)micType;

/**获取会议列表
 @param nowMeetingsBlock 获取参会方列表回调
 @end
*/
- (NSInteger)getNowMeetings:(OnGetNowMeetings *)nowMeetingsBlock;
/**用户是否在会议中
*/
- (BOOL)isMeettingBusy;
/**更新token
*/
- (NSInteger)updateToken:(NSString *)token;

/**用户退出会议
*/
- (void)exitMeeting;

/**
 获取qos信息
 */
- (NSString *)getQosStr;

/**
 释放相关资源
 */
- (void)destorySDK;

/// 设置HTTPDNS账号信息 (初始化会议SDK之前调用)
/// @param aCode   所属国家二位简码
- (void)setHttpDNSAreaCode:(NSString *)aCode;
@end


