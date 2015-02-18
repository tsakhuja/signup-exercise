//
//  KCAccountValidator.h
//  SignupForm
//
//  Created by Tim Sakhuja on 8/5/14.
//  Copyright (c) 2014 Kamcord, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 A key indicating the nature of an error related to a user account.

 Currently all of these error code keys relate to login, signup, and editing user profile account
 details.
 */

typedef NS_ENUM(NSUInteger, KCAccountErrorCode) {
  KCAccountErrorCodeSuccess = 0,
  KCAccountErrorCodeUsernameExists,
  KCAccountErrorCodeUsernameTooShort,
  KCAccountErrorCodeUsernameTooLong,
  KCAccountErrorCodeUsernameMissing,
  KCAccountErrorCodeEmailExists,
  KCAccountErrorCodeEmailFormatInvalid,
  KCAccountErrorCodeEmailTooLong,
  KCAccountErrorCodeEmailMissing,
  KCAccountErrorCodePasswordTooShort,
  KCAccountErrorCodePasswordTooLong,
  KCAccountErrorCodePasswordMissing,
  KCAccountErrorCodeOldPasswordIncorrect,
  KCAccountErrorCodeEmailOrUsernameDoesNot,
  KCAccountErrorCodePasswordInvalid,
  KCAccountErrorCodeTooManyResetPasswordAttempts,
};

@interface KCAccountValidator : NSObject

/**
 * Validates an email address by verifying that the email is not already in use by a user and that
 * the email matches the form xxx@yyy.zzz. Callback is executed on the main thread.
 */
+ (void)validateEmail:(NSString *)email callback:(void(^)(KCAccountErrorCode code))callback;

+ (KCAccountErrorCode)validatePassword:(NSString *)password;

/** 
 * Validates a username by verifying that the username is not already in use and is between 2 and
 * 15 characters in length. Callback is executed on the main thread.
 */
+ (void)validateUsername:(NSString *)username callback:(void(^)(KCAccountErrorCode code))callback;

@end
