//
//  HLNetworkObserver.h
//  HLNetworking
//
//  Created by 陈嘉豪 on 2018/9/6.
//  Copyright © 2018年 wangshiyu13. All rights reserved.
//

#import <Foundation/Foundation.h>
@class HLURLRequest;
@interface HLNetworkTaskManager : NSObject
// 返回该请求是否需要再次发送
- (BOOL)addRequest:(HLURLRequest *)request;
// 取消指定的一个 Request
- (void)cancelForRequest:(HLURLRequest *)request;
// 取消所有和该 Request 相同 hashKey 的请求
//- (void)cancelForSomeKindRequest:(HLURLRequest *)request;
@end
