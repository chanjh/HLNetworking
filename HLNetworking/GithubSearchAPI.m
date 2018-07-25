//
//  GithubSearchAPI.m
//  HLNetworking
//
//  Created by 陈嘉豪 on 2018/7/25.
//  Copyright © 2018年 wangshiyu13. All rights reserved.
//

#import "GithubSearchAPI.h"
#define SearchPath(search_type) @[@"search/commits", @"search/repositories"][search_type]

@interface GithubSearchAPI()<HLInterceptorProtocol, HLReformerDelegate>
@end

@implementation GithubSearchAPI
- (instancetype)initWithSearchKey:(NSString *)keyword
                             type:(GithubSearchType)type{
    self = [[self class] request];
    if(self){
        self.setPath(SearchPath(type))
        .setParams(@{@"q":keyword})
        .setObjReformerDelegate(self);
//        .setInterceptor(self);
    }
    return self;
}

- (NSError *)interceptErrorForApiRequest:(__kindof HLURLRequest *)request{
    return [NSError errorWithDomain:@"com.chanjh.network.error" code:400 userInfo:nil];
}

- (id)reformerObject:(id)responseObject andError:(NSError *)error atRequest:(HLAPIRequest *)request{
    return @"hahaha";
}

@end
