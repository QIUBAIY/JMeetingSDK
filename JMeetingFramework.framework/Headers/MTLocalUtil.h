//
//  LocalUtil.h
//  NetPhone
//
//  Created by AHQN on 15-1-29.
//  Copyright (c) 2015年 青牛软件. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MTLocalUtil : NSObject
/**
 * 根据key获取Localizable.strings中的value
 */
+(NSString *) localString:(NSString *) key;

/**
 * 根据key获取Localizable.strings中的value
 * comment: 对第一个参数的注释，暂无其他效果
 */
+(NSString *) localString:(NSString *) key comment:(NSString *) comment;

/**
 *  根据key获取Localizable.strings中的value
 *  value：默认值
 */
+(NSString *) localString:(NSString *) key value:(NSString *) value;

/**
 *  根据key获取Localizable.strings中的value
 *  value：默认值
 *  comment: 对第一个参数的注释，暂无其他效果
 */
+(NSString *) localString:(NSString *) key value:(NSString *) value comment:(NSString *) comment;

/**
 *  根据key获取tbl.strings中的value
 */
+(NSString *) localString:(NSString *) key table:(NSString *) tbl;

/**
 *  根据key获取tbl.strings中的value
 *  tbl:对应key所在的.strings文件（表）名
 *  comment: 对第一个参数的注释，暂无其他效果
 */
+(NSString *) localString:(NSString *) key table:(NSString *) tbl comment:(NSString *) comment;

/**
 *  根据key获取tbl.strings中的value
 *  tbl:对应key所在的.strings文件（表）名
 *  bundle: 包含tbl.strings的资源集合（只是表达个意思哈）
 */
+(NSString *) localString:(NSString *) key table:(NSString *) tbl bundle:(NSBundle *) bundle;

/**
 *  根据key获取tbl.strings中的value
 *  tbl:对应key所在的.strings文件（表）名
 *  bundle: 包含tbl.strings的资源集合（只是表达个意思哈）
 *  comment: 对第一个参数的注释，暂无其他效果
 */
+(NSString *) localString:(NSString *) key table:(NSString *) tbl bundle:(NSBundle *) bundle comment:(NSString *) comment;

/**
 *  根据key获取tbl.strings中的value
 *  tbl:对应key所在的.strings文件（表）名
 *  bundle: 包含tbl.strings的资源集合（只是表达个意思哈）
 *  value：默认值
 */
+(NSString *) localString:(NSString *) key table:(NSString *) tbl bundle:(NSBundle *) bundle value:(NSString *) value;

/**
 *  根据key获取tbl.strings中的value
 *  tbl:对应key所在的.strings文件（表）名
 *  bundle: 包含tbl.strings的资源集合（只是表达个意思哈）
 *  value：默认值
 *  comment: 对第一个参数的注释，暂无其他效果
 */
+(NSString *) localString:(NSString *) key table:(NSString *) tbl bundle:(NSBundle *) bundle value:(NSString *) value comment:(NSString *) comment;


/**
 *  初始化程序的用户语言属性参数
 *  获取系统的当前语言
 */
+(void)initUserLanguage;
/**
 * 获取当前的系统语言  中文zh-Hans,英文en
 */
+(NSString *)userLanguage;
/**
 *  判断当前的用户语言是否是英语
 */
+(Boolean) isEnLanguage;
@end
