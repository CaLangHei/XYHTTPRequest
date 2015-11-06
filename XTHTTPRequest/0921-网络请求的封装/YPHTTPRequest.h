//
//  YPHTTPRequest.h
//  MusicPlayer
//
//  Created by 张晓彤 on 15/8/13.
//  Copyright (c) 2015年 week. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YPHTTPRequest;

// 请求成功的回调
typedef void(^YPHTTPRequestFinishBlock)(YPHTTPRequest *request);
// 请求失败的回调
typedef void(^YPHTTPRequestErrorBlock)(NSError *error);
// 进度的回调
typedef void(^YPHTTPRequestDidReceiveProgessBlock)(float progress);

@interface YPHTTPRequest : NSObject

@property (nonatomic, strong) NSData *responseData;

@property (nonatomic, copy) NSString *responseString;


/**
 *  构造方法
 */
- (instancetype)initWithUrl:(NSURL *)url;

/**
 *  发送异步请求
 */
- (void)startHttpRequest;

- (void)setHTTPRequestFinishBlock:(YPHTTPRequestFinishBlock)block;

//- (void)setHTTPRequestFinishBlock2:(void(^)(YPHTTPRequest *request))block2;

/**
 *  get请求
 *
 *  @param urlString    url字符串
 *  @param successBlock 成功的回调
 *  @param failureBlock 失败的回调
 */
- (void)GET:(NSString *)urlString success:(YPHTTPRequestFinishBlock)successBlock failure:(YPHTTPRequestErrorBlock)failureBlock;

- (void)setRecevieProgessBlock:(YPHTTPRequestDidReceiveProgessBlock)progressBlock;

@end
























