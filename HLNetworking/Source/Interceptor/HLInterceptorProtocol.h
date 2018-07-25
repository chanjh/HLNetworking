//
//  HLInterceptorProtocol.h
//  HLNetworking
//
//  Created by 陈嘉豪 on 2018/7/25.
//  Copyright © 2018年 wangshiyu13. All rights reserved.
//

#import <Foundation/Foundation.h>
@class HLURLRequest;

@protocol HLInterceptorProtocol <NSObject>

/**
 * 暂时只支持 HLAPIRequest
 * 但为了 HLNetworkManager 调用时方式，API 暂时这么设计
 */
- (NSError * _Nullable )interceptErrorForApiRequest:(__kindof HLURLRequest *)request;

@end
