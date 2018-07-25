//
//  DemoViewController.m
//  HLNetworking
//
//  Created by 陈嘉豪 on 2018/7/25.
//  Copyright © 2018年 wangshiyu13. All rights reserved.
//

#import "DemoViewController.h"
#import "GithubSearchAPI.h"

@interface DemoViewController ()

@end

@implementation DemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    GithubSearchAPI *api = [[GithubSearchAPI alloc]initWithSearchKey:@"photo" type:GithubSearchTypeRepositories];
    [api startWithSuccessHandler:^(__kindof HLURLRequest *request, id  _Nullable responseObj) {
        
    } failureHandler:nil];
}

@end