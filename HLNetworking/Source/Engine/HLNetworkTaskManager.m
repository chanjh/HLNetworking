//
//  HLNetworkObserver.m
//  HLNetworking
//
//  Created by 陈嘉豪 on 2018/9/6.
//  Copyright © 2018年 wangshiyu13. All rights reserved.
//

#import "HLNetworkTaskManager.h"
#import "HLURLRequest.h"
#import "HLNetworkManager.h"
#import "HLURLRequest_InternalParams.h"
#import "HLAPIRequest.h"
#import "HLAPIRequest_InternalParams.h"
#import "HLTaskRequest.h"
@interface HLNetworkTaskManager()<HLNetworkResponseDelegate, HLURLRequestDelegate>
@property (nonatomic, strong) NSMutableDictionary *requestRecord;
@property (nonatomic, strong) NSMutableArray *requestList;
@end
@implementation HLNetworkTaskManager

- (instancetype)init{
    if(self = [super init]){
        [[HLNetworkManager sharedManager] registerResponseObserver:self];
    }
    return self;
}

- (NSArray <__kindof HLURLRequest *>*)observerRequests{
    return self.requestList;
}

- (void)requestProgress:(nullable NSProgress *)progress atRequest:(nullable __kindof HLURLRequest *)request{
    NSString *key = [request hashKey];
    if([self.requestRecord.allKeys containsObject:key]){
        for(HLURLRequest *requestObj in self.requestRecord[key]){
            if([request isEqual:requestObj]){
                continue;
            }
            requestObj.progressHandler(requestObj, progress);
        }
    }
}

- (void)requestSucess:(nullable id)responseObject atRequest:(nullable __kindof HLURLRequest *)request{
    NSString *key = [request hashKey];
    if([self.requestRecord.allKeys containsObject:key]){
        for(HLURLRequest *requestObj in self.requestRecord[key]){
            if([request isEqual:requestObj]){
                continue;
            }
            requestObj.successHandler(requestObj, responseObject);
            // APIRequest
            if([requestObj isKindOfClass:HLAPIRequest.class]){
                HLAPIRequest *apiRequest = (HLAPIRequest *)requestObj;
                if([apiRequest.objReformerDelegate respondsToSelector:@selector(modelingFormJSONResponseObject:)]){
                    [apiRequest.objReformerDelegate modelingFormJSONResponseObject:responseObject];
                }
                if([apiRequest.objReformerDelegate respondsToSelector:@selector(reformerObject:andError:atRequest:)]){
                    [apiRequest.objReformerDelegate reformerObject:responseObject andError:nil atRequest:apiRequest];
                }
            }
            // Task Request
            if([requestObj isKindOfClass:HLTaskRequest.class]){
                // TODO
            }
        }
        [self removeForKey:key];
    }
}

- (void)requestFailure:(nullable NSError *)error atRequest:(nullable __kindof HLURLRequest *)request{
    NSString *key = [request hashKey];
    if([self.requestRecord.allKeys containsObject:key]){
        for(HLURLRequest *requestObj in self.requestRecord[key]){
            requestObj.failureHandler(requestObj, error);
            // APIRequest
            if([requestObj isKindOfClass:HLAPIRequest.class]){
                // TODO
            }
            // Task Request
            if([requestObj isKindOfClass:HLTaskRequest.class]){
                // TODO
            }
        }
        [self removeForKey:key];
    }
}

- (void)cancelForRequest:(HLURLRequest *)request{
    if([self.requestList containsObject:request]){
        [self.requestList removeObject:request];
    }
    NSString *key = [request hashKey];
    if([self.requestRecord valueForKey:key]){
        NSMutableArray *list = [NSMutableArray arrayWithArray:self.requestRecord[key]];
        [list removeObject:request];
        self.requestRecord[key] = [list copy];
    }
    [request cancel];
}

- (void)removeForKey:(NSString *)key{
    // 删除操作
    NSArray *list = self.requestRecord[key];
    for(HLURLRequest *requestObj in list){
        if([self.requestList containsObject:requestObj]){
            [self.requestList removeObject:requestObj];
        }
    }
    [self.requestRecord removeObjectForKey:key];
}

// 取消所有和该 Request 相同 hashKey 的请求
- (void)cancelForSomeKindRequest:(HLURLRequest *)request{
    NSString *key = [request hashKey];
    NSArray *list = self.requestRecord[key];
    for(HLURLRequest *requestObj in list){
        if([self.requestList containsObject:requestObj]){
            [requestObj cancel];
            [self.requestList removeObject:requestObj];
        }
    }
    [self.requestRecord removeObjectForKey:key];
}

- (BOOL)addRequest:(HLURLRequest *)request{
    if(![self.requestList containsObject:request]){
        [self.requestList addObject:request];
    }
    NSString *key = [request hashKey];
    BOOL result = [self.requestRecord valueForKey:key];
    if(result){
        NSMutableArray *list = [NSMutableArray arrayWithArray:self.requestRecord[key]];
        if(![list containsObject:request]){
            [list addObject:request];
            self.requestRecord[key] = [list copy];
        }
    }else{
        [self.requestRecord setObject:@[request] forKey:key];
    }
    return result;
}

- (NSMutableArray *)requestList{
    if(!_requestList){
        _requestList = [NSMutableArray array];
    }
    return _requestList;
}

- (NSMutableDictionary *)requestRecord{
    if(!_requestRecord){
        _requestRecord = [NSMutableDictionary dictionary];
    }
    return _requestRecord;
}

@end
