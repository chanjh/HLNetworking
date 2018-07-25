//
//  GithubSearchAPI.m
//  HLNetworking
//
//  Created by 陈嘉豪 on 2018/7/25.
//  Copyright © 2018年 wangshiyu13. All rights reserved.
//

#import "GithubSearchAPI.h"
#define SearchPath(search_type) @[@"/search/commits", @"/search/repositories"][search_type]
@implementation GithubSearchAPI
- (instancetype)initWithSearchKey:(NSString *)keyword
                             type:(GithubSearchType)type{
    if(self == [[self class] request]){
        self.setPath(SearchPath(type)).setParams(@{@"q":keyword});
    }
    return self;
}
@end
