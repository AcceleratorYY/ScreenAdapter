//
//  ScreenAdapter.h
//  iOSScreenAdapter
//
//  Created by coder_zyy on 2020/12/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**常用宏**/
/// 状态栏高度
#define  StatusBarHeight [[UIApplication sharedApplication] statusBarFrame].size.height
// Navigation bar height.
#define  NavigationBarHeight  44.f
// Tabbar height.
#define  TabbarHeight         (isFullScreen() ? (49.f+34.f) : 49.f)
// Tabbar safe bottom margin.
#define  TabbarSafeBottomMargin         (isFullScreen() ? 34.f : 0.f)
// Status bar & navigation bar height.
#define  StatusBarAndNavigationBarHeight  (StatusBarHeight + NavigationBarHeight)

/** 适配手机类型 */
typedef NS_ENUM(NSInteger,AdapterPhoneType) {
    /** iPhone3GS_4_4S */
    AdapterPhoneType_iPhone3GS_4_4S    = 0,
    /** iPhone5_5C_5S_5SE */
    AdapterPhoneType_iPhone5_5C_5S_5SE = 1,
    /** iPhone6_6S_7_8 */
    AdapterPhoneType_iPhone6_6S_7_8_SE = 2,
    /** iPhone6Plus_6SPlus_7Plus_8Plus */
    AdapterPhoneType_iPhone6Plus_6SPlus_7Plus_8Plus = 3,
    /** iPhoneX_XS_11Pro_12mini */
    AdapterPhoneType_iPhoneX_XS_11Pro_12mini        = 4,
    /** iPhoneXSMax_XR_11_11ProMax */
    AdapterPhoneType_iPhoneXSMax_XR_11_11ProMax     = 5,
    /** iPhone12_12Pro */
    AdapterPhoneType_iPhone12_12Pro                 = 6,
    /** iPhone12ProMax */
    AdapterPhoneType_iPhone12ProMax                 = 7,
    /** 其他 */
    AdapterPhoneTypeOther                           = 8,
};

/** 所需适配机型-屏幕宽 */
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhone3GS_4_4S;
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhone5_5C_5S_5SE;
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhone6_6S_7_8_SE;
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhone6Plus_6SPlus_7Plus_8Plus;
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhoneX_XS_11Pro_12mini;
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhoneXSMax_XR_11_11ProMax;
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhone12_12Pro;
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhone12ProMax;

/** 所需适配机型-屏幕高 */
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhone3GS_4_4S;
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhone5_5C_5S_5SE;
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhone6_6S_7_8_SE;
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhone6Plus_6SPlus_7Plus_8Plus;
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhoneX_XS_11Pro_12mini;
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhoneXSMax_XR_11_11ProMax;
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhone12_12Pro;
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhone12ProMax;

/** 屏幕宽度 */
static inline CGFloat tScreenWidth() {
    return [UIScreen mainScreen].bounds.size.width;
}

/** 幕高度 */
static inline CGFloat tScreenHeight() {
    return [UIScreen mainScreen].bounds.size.height;
}

/** 是否是全面屏 */
static inline BOOL isFullScreen() {
    if (@available(iOS 11.0, *)) {
        UIWindow *keyWindow = [[[UIApplication sharedApplication] delegate] window];
        // 获取底部安全区域高度，iPhone X 竖屏下为 34.0，横屏下为 21.0，其他类型设备都为 0
        CGFloat bottomSafeInset = keyWindow.safeAreaInsets.bottom;
        if (bottomSafeInset == 34.0f || bottomSafeInset == 21.0f) {
            return YES;
        }
    }
    return NO;
}

/** 当前屏幕类型 */
static inline AdapterPhoneType tCurrentType() {
    if (tScreenHeight() == SCREEN_HEIGHT_iPhone3GS_4_4S) return AdapterPhoneType_iPhone3GS_4_4S;
    if (tScreenHeight() == SCREEN_HEIGHT_iPhone5_5C_5S_5SE) return AdapterPhoneType_iPhone5_5C_5S_5SE;
    if (tScreenHeight() == SCREEN_HEIGHT_iPhone6_6S_7_8_SE) return AdapterPhoneType_iPhone6_6S_7_8_SE;
    if (tScreenHeight() == SCREEN_HEIGHT_iPhone6Plus_6SPlus_7Plus_8Plus) return AdapterPhoneType_iPhone6Plus_6SPlus_7Plus_8Plus;
    if (tScreenHeight() == SCREEN_HEIGHT_iPhoneX_XS_11Pro_12mini) return AdapterPhoneType_iPhoneX_XS_11Pro_12mini;
    if (tScreenHeight() == SCREEN_HEIGHT_iPhoneXSMax_XR_11_11ProMax) return AdapterPhoneType_iPhoneXSMax_XR_11_11ProMax;
    if (tScreenHeight() == SCREEN_HEIGHT_iPhone12_12Pro) return AdapterPhoneType_iPhone12_12Pro;
    if (tScreenHeight() == SCREEN_HEIGHT_iPhone12ProMax) return AdapterPhoneType_iPhone12ProMax;
    return AdapterPhoneTypeOther;
}

/** 屏幕适配 */
@interface Adapter : NSObject

/** 屏幕默认类型 默认为AdapterPhoneType_iPhone6_6S_7_8 */
@property(nonatomic)AdapterPhoneType defaultType;

/** 屏幕宽度 */
@property(nonatomic,readonly)CGFloat defaultScreenWidth;

/** 屏幕高度 */
@property(nonatomic,readonly)CGFloat defaultScreenHeight;

/** 共享适配器 */
+ (instancetype)shareAdapter;

@end

/**
 注：屏幕及字体是以屏幕宽度来适配的
 */

/** 真实字体大小 */
static inline CGFloat tRealFontSize(CGFloat defaultSize) {
    if ([Adapter shareAdapter].defaultType == tCurrentType())
        return defaultSize;
    return tScreenWidth() / [Adapter shareAdapter].defaultScreenWidth * defaultSize;
}

/** 真实长度 */
static inline CGFloat tRealLength(CGFloat defaultLength) {
    if ([Adapter shareAdapter].defaultType == tCurrentType())
        return defaultLength;
    return tScreenWidth()/[Adapter shareAdapter].defaultScreenWidth * defaultLength;
}


NS_ASSUME_NONNULL_END
