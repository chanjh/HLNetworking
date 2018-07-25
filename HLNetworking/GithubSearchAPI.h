//
//  GithubSearchAPI.h
//  HLNetworking
//
//  Created by 陈嘉豪 on 2018/7/25.
//  Copyright © 2018年 wangshiyu13. All rights reserved.
//

#import "HLAPIRequest.h"
typedef NS_ENUM(NSUInteger, GithubSearchType) {
    GithubSearchTypeCommits = 0,
    GithubSearchTypeRepositories,
};


@interface GithubSearchAPI : HLAPIRequest
- (instancetype)initWithSearchKey:(NSString *)keyword type:(GithubSearchType)type;
@end
