//
//  SIToastView.h
//
//  Created by Kevin Cao on 13-6-14.
//  Copyright (c) 2013年 Sumi Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString *const SIToastViewWillShowNotification;
extern NSString *const SIToastViewDidShowNotification;
extern NSString *const SIToastViewWillDismissNotification;
extern NSString *const SIToastViewDidDismissNotification;

typedef NS_ENUM(NSInteger, SIToastViewGravity) {
    SIToastViewGravityBottom = 0,
    SIToastViewGravityTop,
};

typedef NS_ENUM(NSInteger, SIToastViewStyle) {
    SIToastViewStyleDefault = 0,
    SIToastViewStyleBanner
};

@class SIToastView;
typedef void(^SIToastViewHandler)(SIToastView *toastView);

@interface SIToastView : UIView

@property (nonatomic, strong) UIColor *viewBackgroundColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR; // default is [UIColor whiteColor]
@property (nonatomic, strong) UIColor *messageColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR; // [UIColor darkGrayColor]
@property (nonatomic, strong) UIFont *messageFont NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *activityIndicatorColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) CGFloat cornerRadius NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR; // default is 2.0
@property (nonatomic, assign) CGFloat shadowRadius NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR; // default is 0.0

@property (nonatomic, copy) NSString *message;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, assign) BOOL showsActivity;
@property (nonatomic, assign) NSTimeInterval duration;

@property (nonatomic, assign) SIToastViewGravity gravity; // default is SIToastViewGravityBottom
@property (nonatomic, assign) SIToastViewStyle style; // default is SIToastViewStyleToast
@property (nonatomic, assign) CGFloat offset; // default is 30.0

@property (nonatomic, readonly, getter = isVisible) BOOL visible;

@property (nonatomic, copy) SIToastViewHandler willShowHandler;
@property (nonatomic, copy) SIToastViewHandler didShowHandler;
@property (nonatomic, copy) SIToastViewHandler willDismissHandler;
@property (nonatomic, copy) SIToastViewHandler didDismissHandler;

+ (SIToastView *)toastView;

+ (SIToastView *)showToastWithMessage:(NSString *)message;
+ (SIToastView *)showToastWithMessage:(NSString *)message duration:(NSTimeInterval)duration;
+ (SIToastView *)showToastWithMessage:(NSString *)message duration:(NSTimeInterval)duration gravity:(SIToastViewGravity)gravity;
+ (SIToastView *)showToastWithMessage:(NSString *)message duration:(NSTimeInterval)duration gravity:(SIToastViewGravity)gravity offset:(CGFloat)offset;
+ (SIToastView *)showToastWithMessage:(NSString *)message duration:(NSTimeInterval)duration gravity:(SIToastViewGravity)gravity style:(SIToastViewStyle)style offset:(CGFloat)offset;

+ (SIToastView *)showToastWithActivityAndMessage:(NSString *)message;
+ (SIToastView *)showToastWithActivityAndMessage:(NSString *)message gravity:(SIToastViewGravity)gravity;
+ (SIToastView *)showToastWithActivityAndMessage:(NSString *)message gravity:(SIToastViewGravity)gravity offset:(CGFloat)offset;
+ (SIToastView *)showToastWithActivityAndMessage:(NSString *)message gravity:(SIToastViewGravity)gravity style:(SIToastViewStyle)style offset:(CGFloat)offset;

+ (SIToastView *)showToastWithImage:(UIImage *)image message:(NSString *)message;
+ (SIToastView *)showToastWithImage:(UIImage *)image message:(NSString *)message duration:(NSTimeInterval)duration;
+ (SIToastView *)showToastWithImage:(UIImage *)image message:(NSString *)message duration:(NSTimeInterval)duration gravity:(SIToastViewGravity)gravity;
+ (SIToastView *)showToastWithImage:(UIImage *)image message:(NSString *)message duration:(NSTimeInterval)duration gravity:(SIToastViewGravity)gravity offset:(CGFloat)offset;
+ (SIToastView *)showToastWithImage:(UIImage *)image message:(NSString *)message duration:(NSTimeInterval)duration gravity:(SIToastViewGravity)gravity style:(SIToastViewStyle)style offset:(CGFloat)offset;

+ (NSArray *)visibleToastViews;
+ (BOOL)isShowingToastView;

- (void)showMessage:(NSString *)message;
- (void)showMessage:(NSString *)message duration:(NSTimeInterval)duration;
- (void)showMessage:(NSString *)message duration:(NSTimeInterval)duration gravity:(SIToastViewGravity)gravity;
- (void)showMessage:(NSString *)message duration:(NSTimeInterval)duration gravity:(SIToastViewGravity)gravity offset:(CGFloat)offset;
- (void)showMessage:(NSString *)message duration:(NSTimeInterval)duration gravity:(SIToastViewGravity)gravity style:(SIToastViewStyle)style offset:(CGFloat)offset;

- (void)showActivityWithMessage:(NSString *)message;
- (void)showActivityWithMessage:(NSString *)message gravity:(SIToastViewGravity)gravity;
- (void)showActivityWithMessage:(NSString *)message gravity:(SIToastViewGravity)gravity offset:(CGFloat)offset;
- (void)showActivityWithMessage:(NSString *)message gravity:(SIToastViewGravity)gravity style:(SIToastViewStyle)style offset:(CGFloat)offset;

- (void)showImage:(UIImage *)image message:(NSString *)message;
- (void)showImage:(UIImage *)image message:(NSString *)message duration:(NSTimeInterval)duration;
- (void)showImage:(UIImage *)image message:(NSString *)message duration:(NSTimeInterval)duration gravity:(SIToastViewGravity)gravity;
- (void)showImage:(UIImage *)image message:(NSString *)message duration:(NSTimeInterval)duration gravity:(SIToastViewGravity)gravity offset:(CGFloat)offset;

- (void)show;
- (void)dismiss;

@end
