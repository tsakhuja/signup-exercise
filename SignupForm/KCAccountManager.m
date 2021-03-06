//
//  KCAccountManager.m
//  SignupForm
//
//  Created by Tim Sakhuja on 8/5/14.
//  Copyright (c) 2014 Kamcord, Inc. All rights reserved.
//

#import "KCAccountManager.h"

@implementation KCAccountManager

+ (void)createWithEmail:(NSString *)email
               username:(NSString *)username
               password:(NSString *)password
               callback:(void (^)(KCAccountErrorCode errorCode))callback {
  CGFloat delay = (CGFloat) drand48() * 5.f;
  dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delay * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
    if ([email isEqualToString:@"tim@kamcord.com"]) {
      callback(KCAccountErrorCodeEmailExists);
    } else if ([username isEqualToString:@"tim"]) {
      callback(KCAccountErrorCodeUsernameExists);
    } else {
      callback(KCAccountErrorCodeSuccess);
    }
  });
}

@end
