//
//  HLInterceptorProtocol.h
//  HLNetworking
//
//  Created by 陈嘉豪 on 2018/7/25.
//  Copyright © 2018年 wangshiyu13. All rights reserved.
//

#import <Foundation/Foundation.h>
@class HLURLRequest;
@class HLAPIRequest;

@protocol HLInterceptorProtocol <NSObject>

@optional
// 出现错误的时候，用于拦截是否要执行这次 Retry
- (BOOL)needRetryForError:(NSError *)error forRequest:(HLURLRequest *)request;

- (NSError * _Nullable )interceptErrorForApiRequest:(HLAPIRequest *)request
                                           curError:(NSError * _Nullable)curError;

@end
