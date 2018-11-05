//
//  HLURLRequest.h
//  HLNetworking
//
//  Created by wangshiyu13 on 2017/1/23.
//  Copyright © 2017年 wangshiyu13. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HLNetworkConst.h"
#import "HLInterceptorProtocol.h"
@class HLURLRequest;
@class HLSecurityPolicyConfig;
@protocol HLMultipartFormDataProtocol;
@protocol HLURLRequestDelegate;
NS_ASSUME_NONNULL_BEGIN

#pragma mark - HLAPIRequestDelegate
@protocol HLURLRequestDelegate <NSObject>
@optional
// 请求将要发出
- (void)requestWillBeSent:(nullable __kindof HLURLRequest *)request;
// 请求已经发出
- (void)requestDidSent:(nullable __kindof HLURLRequest *)request;
@end

@interface HLURLRequest : NSObject<NSCopying>

#pragma mark - property
@property (nonatomic, assign, readonly) NSTimeInterval timeoutInterval;
@property (nonatomic, copy, readonly) NSString *baseURL;
@property (nonatomic, copy, readonly) NSString *path;
@property (nonatomic, copy, nullable, getter=customURL, readonly) NSString *cURL;
@property (nonatomic, assign, readonly) HLRequestStatus status;
/*!
 @abstract Returns the HTTP status code of the receiver.
 @result The HTTP status code of the receiver.
 */
@property (readonly) NSInteger statusCode;

#pragma mark - initialize method
// 请使用API
+ (instancetype)request;
- (instancetype)init;
+ (instancetype)new NS_UNAVAILABLE;

#pragma mark - parameters append method
// 设置HLAPI的 拦截器
- (__kindof HLURLRequest *(^)(id<HLInterceptorProtocol> _Nullable interceptor))setInterceptor;
// 设置HLAPI的requestDelegate
- (__kindof HLURLRequest *(^)(id<HLURLRequestDelegate> _Nullable delegate))setDelegate;
// 设置API的baseURL，该参数会覆盖config中的baseURL
- (__kindof HLURLRequest *(^)(NSString *baseURL))setBaseURL;
// urlQuery，baseURL后的地址
- (__kindof HLURLRequest *(^)(NSString * _Nullable path))setPath;
// 自定义的RequestUrl，该参数会无视任何baseURL的设置，优先级最高
- (__kindof HLURLRequest *(^)(NSString *customURL))setCustomURL;
// HTTPS 请求的Security策略
- (__kindof HLURLRequest *(^)(HLSecurityPolicyConfig *securityPolicy))setSecurityPolicy;
// HTTP 请求的Cache策略
- (__kindof HLURLRequest *(^)(NSURLRequestCachePolicy requestCachePolicy))setCachePolicy;
// HTTP 请求超时的时间，默认为30秒
- (__kindof HLURLRequest *(^)(NSTimeInterval requestTimeoutInterval))setTimeout;
NS_ASSUME_NONNULL_END

#pragma mark - process
// 开启API 请求
- (__kindof HLURLRequest *)startWithSuccessHandler:(HLSuccessBlock)success
                                   progressHandler:(HLProgressBlock)progress
                                    failureHandler:(HLFailureBlock)failure;
// 开启API 请求
- (__kindof HLURLRequest *)startWithSuccessHandler:(HLSuccessBlock)success
                                    failureHandler:(HLFailureBlock)failure;

NS_ASSUME_NONNULL_BEGIN
// 开启API 请求
- (__kindof HLURLRequest *)start;
// 取消API 请求
- (__kindof HLURLRequest *)cancel;
// 继续Task
- (__kindof HLURLRequest *)resume;
// 暂停Task
- (__kindof HLURLRequest *)pause;

#pragma mark - helper
- (NSDictionary *)toDictionary;
- (NSString *)hashKey;
@end

#pragma mark - handler block function
@interface HLURLRequest (Handler)
/**
 API完成后的成功回调
 写法：
 .success(^(id obj) {
 dosomething
 })
 */
- (__kindof HLURLRequest *(^)(HLSuccessBlock))success;
/**
 API完成后的失败回调
 写法：
 .failure(^(NSError *error) {
 
 })
 */
- (__kindof HLURLRequest *(^)(HLFailureBlock))failure;
/**
 API上传、下载等长时间执行的Progress进度
 写法：
 .progress(^(NSProgress *proc){
 NSLog(@"当前进度：%@", proc);
 })
 */
- (__kindof HLURLRequest *(^)(HLProgressBlock))progress;
/**
 用于Debug的Block
 block内返回HLDebugMessage对象
 */
- (__kindof HLURLRequest *(^)(HLDebugBlock))debug;
@end
NS_ASSUME_NONNULL_END
