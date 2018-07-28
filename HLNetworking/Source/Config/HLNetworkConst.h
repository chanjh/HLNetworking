//
//  HLNetworkConst.h
//  HLNetworking
//
//  Created by wangshiyu13 on 2017/1/22.
//  Copyright © 2017年 wangshiyu13. All rights reserved.
//

#ifndef HLNetworkConst_h
#define HLNetworkConst_h
@protocol HLMultipartFormDataProtocol;
@class HLDebugMessage;
@class HLURLRequest;

typedef NS_ENUM(NSUInteger, HLRequestStatus) {
    HLRequestStatusNotKnown = 0,
    HLRequestStatusSuccess,
    HLRequestStatusFailure,
};

// 网络请求类型
typedef NS_ENUM(NSUInteger, HLRequestTaskType) {
    Upload = 16,
    Download = 17
};

// 网络请求类型
typedef NS_ENUM(NSUInteger, HLRequestMethodType) {
    GET = 10,
    POST = 11,
    HEAD = 12,
    PUT = 13,
    PATCH = 14,
    DELETE = 15
};

// 请求的序列化格式
typedef NS_ENUM(NSUInteger, HLRequestSerializerType) {
    // Content-Type = application/x-www-form-urlencoded
    RequestHTTP = 100,
    // Content-Type = application/json
    RequestJSON = 101,
    // Content-Type = application/x-plist
    RequestPlist = 102
};

// 请求返回的序列化格式
typedef NS_ENUM(NSUInteger, HLResponseSerializerType) {
    // 默认的Response序列化方式（不处理）
    ResponseHTTP = 200,
    // 使用NSJSONSerialization解析Response Data
    ResponseJSON = 201,
    // 使用NSPropertyListSerialization解析Response Data
    ResponsePlist = 202,
    // 使用NSXMLParser解析Response Data
    ResponseXML = 203
};

// reachability的状态
typedef NS_ENUM(NSUInteger, HLReachabilityStatus) {
    HLReachabilityStatusUnknown,
    HLReachabilityStatusNotReachable,
    HLReachabilityStatusReachableViaWWAN,
    HLReachabilityStatusReachableViaWiFi
};

// 定义的Block
// 请求结果回调
typedef void(^HLSuccessBlock)(__kindof HLURLRequest *request, id __nullable responseObj);
// 请求失败回调
typedef void(^HLFailureBlock)(__kindof HLURLRequest *request, NSError * __nullable error);
// 请求进度回调
typedef void(^HLProgressBlock)(__kindof HLURLRequest *request, NSProgress * __nullable progress);
// formData拼接回调
typedef void(^HLRequestConstructingBodyBlock)(id<HLMultipartFormDataProtocol> __nullable formData);
// debug回调
typedef void(^HLDebugBlock)(HLDebugMessage * __nonnull debugMessage);
// reachability回调
typedef void(^HLReachabilityBlock)(HLReachabilityStatus status);
// 桥接回调
typedef void(^HLCallbackBlock)(id __nonnull request, id __nullable responseObject, NSError * __nullable error);

#endif /* HLNetworkConst_h */
