//
//  KCAccountValidator.m
//  SignupForm
//
//  Created by Tim Sakhuja on 8/5/14.
//  Copyright (c) 2014 Kamcord, Inc. All rights reserved.
//

#import "KCAccountValidator.h"

@implementation KCAccountValidator

static const NSInteger kMinPasswordLength = 6;
static const NSInteger kMaxPasswordLength = 30;
static const NSInteger kMinUsernameLength = 2;
static const NSInteger kMaxUsernameLength = 15;

+ (void)validateEmail:(NSString *)email callback:(void(^)(KCAccountErrorCode code))callback   {
  CGFloat delay = (CGFloat) drand48() * 5.f;
  dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delay * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
    if (![self isEmailValid:email]) {
      callback(KCEmailFormatInvalidCode);
    } else {
      if ([email isEqualToString:@"tim@kamcord.com"]) {
        callback(KCEmailAlreadyExistsCode);
      } else {
        callback(KCSuccessCode);
      }
    }
  });
}

+ (KCAccountErrorCode)validatePassword:(NSString *)password {
  NSUInteger passwordLength = password.length;
  if (passwordLength == 0) {
    return KCPasswordMissingCode;
  } else if (passwordLength < kMinPasswordLength) {
    return KCPasswordTooShortCode;
  } else if (passwordLength > kMaxPasswordLength){
    return KCPasswordTooLongCode;
  }

  return KCSuccessCode;
}

+ (void)validateUsername:(NSString *)username callback:(void(^)(KCAccountErrorCode code))callback {
  CGFloat delay = (CGFloat) drand48() * 5.f;
  dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delay * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
    if (username.length == 0) {
      callback(KCUsernameMissingCode);
    } else if (username.length < kMinUsernameLength) {
      callback(KCUsernameTooShortCode);
    } else if (username.length > kMaxUsernameLength) {
      callback(KCUsernameTooLongCode);
    } else {
      callback(KCSuccessCode);
    }
  });
}

+ (BOOL)isEmailValid:(NSString *)email {
  NSString *emailRegex = @"[^@]+@[^.@]+(\\.[^.@]+)+";
  NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];

  return [emailTest evaluateWithObject:email];
}

@end
