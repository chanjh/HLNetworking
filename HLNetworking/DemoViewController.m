//
//  DemoViewController.m
//  HLNetworking
//
//  Created by 陈嘉豪 on 2018/7/25.
//  Copyright © 2018年 wangshiyu13. All rights reserved.
//

#import "DemoViewController.h"
#import "GithubSearchAPI.h"
#import "HLNetworkManager.h"

@interface DemoViewController ()

@end

@implementation DemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    GithubSearchAPI *api = [[GithubSearchAPI alloc]initWithSearchKey:@"photo" type:GithubSearchTypeRepositories];
    [api startWithSuccessHandler:^(__kindof HLURLRequest *request, id  _Nullable responseObj) {
        NSLog(@"Request: %@", request);
        NSLog(@"Response: %@", responseObj);
        HLAPIRequest *api = (HLAPIRequest *)request;
        NSLog(@"ReformedObj: %@", api.reformedObj);
    } failureHandler:^(__kindof HLURLRequest *request, NSError * _Nullable error) {
        NSLog(@"Error: %@", error);
    }];
    [api startWithSuccessHandler:^(__kindof HLURLRequest *request, id  _Nullable responseObj) {
        NSLog(@"ReformedObj: %@", api.reformedObj);
    } failureHandler:^(__kindof HLURLRequest *request, NSError * _Nullable error) {
        NSLog(@"Error: %@", error);
    }];
    GithubSearchAPI *api2 = [[GithubSearchAPI alloc]initWithSearchKey:@"photo" type:GithubSearchTypeRepositories];
    [api2 startWithSuccessHandler:^(__kindof HLURLRequest *request, id  _Nullable responseObj) {
        NSLog(@";;;");
        
        
    } failureHandler:^(__kindof HLURLRequest *request, NSError * _Nullable error) {
        NSLog(@"Error: %@", error);
    }];
}

@end
