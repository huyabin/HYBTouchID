//
//  HYBTouchID.h
//  HYBTouchIDExample
//
//  Created by mac on 16/4/22.
//  Copyright © 2016年 Dimon_Hu. All rights reserved.
//

#import <Foundation/Foundation.h>

#define HYBNotice(Chinese,English) [[[[NSUserDefaults standardUserDefaults] objectForKey:@"AppleLanguages"] objectAtIndex:0] containsString:@"zh-Hans"] ? Chinese : English
@protocol   HYBTouchIDDelegate <NSObject>

@required

/**
 *  TouchID验证成功
 *
 *  Authentication Successul
 */
- (void)HYBTouchIDAuthorizeSuccess;

/**
 *  TouchID验证失败
 *
 *  Authentication Failure
 */
- (void)HYBTouchIDAuthorizeFailure;

@optional
/**
 *  取消TouchID验证 (用户点击了取消)
 *
 *  Authentication was canceled by user (e.g. tapped Cancel button).
 */
- (void)HYBTouchIDAuthorizeErrorUserCancel;

/**
 *  在TouchID对话框中点击输入密码按钮
 *
 *  User tapped the fallback button
 */
- (void)HYBTouchIDAuthorizeErrorUserFallback;

/**
 *  在验证的TouchID的过程中被系统取消 例如突然来电话、按了Home键、锁屏...
 *
 *  Authentication was canceled by system (e.g. another application went to foreground).
 */
- (void)HYBTouchIDAuthorizeErrorSystemCancel;

/**
 *  无法启用TouchID,设备没有设置密码
 *
 *  Authentication could not start, because passcode is not set on the device.
 */
- (void)HYBTouchIDAuthorizeErrorPasscodeNotSet;

/**
 *  设备没有录入TouchID,无法启用TouchID
 *
 *  Authentication could not start, because Touch ID has no enrolled fingers
 */
- (void)HYBTouchIDAuthorizeErrorTouchIDNotEnrolled;

/**
 *  该设备的TouchID无效
 *
 *  Authentication could not start, because Touch ID is not available on the device.
 */
- (void)HYBTouchIDAuthorizeErrorTouchIDNotAvailable;

/**
 *  多次连续使用Touch ID失败，Touch ID被锁，需要用户输入密码解锁
 *
 *  Authentication was not successful, because there were too many failed Touch ID attempts and Touch ID is now locked. Passcode is required to unlock Touch ID, e.g. evaluating LAPolicyDeviceOwnerAuthenticationWithBiometrics will ask for passcode as a prerequisite.
 *
 */
- (void)HYBTouchIDAuthorizeErrorTouchIDLockout;

/**
 *  当前软件被挂起取消了授权(如突然来了电话,应用进入前台)
 *
 *  Authentication was canceled by application (e.g. invalidate was called while authentication was inprogress).
 *
 */
- (void)HYBTouchIDAuthorizeErrorAppCancel;

/**
 *  当前软件被挂起取消了授权 (授权过程中,LAContext对象被释)
 *
 *  LAContext passed to this call has been previously invalidated.
 */
- (void)HYBTouchIDAuthorizeErrorInvalidContext;

/**
 *  当前设备不支持指纹识别
 *
 *  The current device does not support fingerprint identification
 */
-(void)HYBTouchIDIsNotSupport;

@end

@interface HYBTouchID : NSObject
@property (nonatomic, weak) id<HYBTouchIDDelegate> delegate;

+ (instancetype)touchID;

/**
 *  发起TouchID验证 (Initiate TouchID validation)
 *
 *  @param message       自定义提示信息 (The custom message)
 *  @param fallbackTitle 按钮标题      (Fallback Title)
 *  @param delegate      delegate
 */
- (void)startHYBTouchIDWithMessage:(NSString *)message
                    fallbackTitle:(NSString *)fallbackTitle
                         delegate:(id<HYBTouchIDDelegate>)delegate;


@end
