//
//  KCAccountManager.h
//  SignupForm
//
//  Created by Tim Sakhuja on 8/5/14.
//  Copyright (c) 2014 Kamcord, Inc. All rights reserved.
//

#import "KCAccountValidator.h"
#import <Foundation/Foundation.h>

@interface KCAccountManager : NSObject

/**
 * Makes a request to the server to create a new user account.
 */
+ (void)createWithEmail:(NSString *)email
               username:(NSString *)username
               password:(NSString *)password
               callback:(void (^)(KCAccountErrorCode errorCode))callback;

@end
