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

typedef NS_ENUM(NSInteger, KCAccountErrorCode) {
  KCSuccessCode = 0,
  KCUsernameAlreadyExistsCode = 1,
  KCUsernameTooShortCode = 2,
  KCUsernameTooLongCode = 3,
  KCUsernameMissingCode = 14,
  KCEmailAlreadyExistsCode = 5,
  KCEmailFormatInvalidCode = 6,
  KCEmailTooLongCode = 7,
  KCEmailMissingCode = 15,
  KCPasswordTooShortCode = 8,
  KCPasswordTooLongCode = 9,
  KCPasswordMissingCode,
  KCOldPasswordIncorrectCode = 10,
  KCEmailOrUsernameDoesNotExist = 11,
  KCPasswordInvalidCode = 12,
  KCTooManyResetPasswordAttemptsCode = 13,
  KCEmptyResponseCode = 16,
};

@interface KCAccountValidator : NSObject

/**
 * Validates an email address by verifying that the email is not already in use by a user and that
 * the email matches the form xxx@yyy.zzz.
 */
+ (void)validateEmail:(NSString *)email callback:(void(^)(KCAccountErrorCode))callback;

+ (KCAccountErrorCode)validatePassword:(NSString *)password;

/** 
 * Validates a username by verifying that the username is not already in use and is between 2 and
 * 15 characters in length.
 */
+ (void)validateUsername:(NSString *)username callback:(void(^)(KCAccountErrorCode))callback;

@end
