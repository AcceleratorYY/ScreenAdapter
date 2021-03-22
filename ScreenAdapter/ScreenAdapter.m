//
//  ScreenAdapter.m
//  iOSScreenAdapter
//
//  Created by coder_zyy on 2020/12/16.
//

#import "ScreenAdapter.h"

/** 所需适配机型-屏幕宽 */
CGFloat const SCREEN_WIDTH_iPhone3GS_4_4S       = 320.0f;
CGFloat const SCREEN_WIDTH_iPhone5_5C_5S_5SE    = 320.0f;
CGFloat const SCREEN_WIDTH_iPhone6_6S_7_8_SE    = 375.0f;
CGFloat const SCREEN_WIDTH_iPhone6Plus_6SPlus_7Plus_8Plus  = 414.0f;
CGFloat const SCREEN_WIDTH_iPhoneX_XS_11Pro_12mini         = 375.0f;
CGFloat const SCREEN_WIDTH_iPhoneXSMax_XR_11_11ProMax      = 414.0f;
CGFloat const SCREEN_WIDTH_iPhone12_12Pro                  = 390.0f;
CGFloat const SCREEN_WIDTH_iPhone12ProMax                  = 428.0f;

/** 所需适配机型-屏幕高 */
CGFloat const SCREEN_HEIGHT_iPhone3GS_4_4S      = 480.0f;
CGFloat const SCREEN_HEIGHT_iPhone5_5C_5S_5SE   = 568.0f;
CGFloat const SCREEN_HEIGHT_iPhone6_6S_7_8_SE   = 667.0f;
CGFloat const SCREEN_HEIGHT_iPhone6Plus_6SPlus_7Plus_8Plus = 736.0f;
CGFloat const SCREEN_HEIGHT_iPhoneX_XS_11Pro_12mini        = 812.0f;
CGFloat const SCREEN_HEIGHT_iPhoneXSMax_XR_11_11ProMax     = 896.0f;
CGFloat const SCREEN_HEIGHT_iPhone12_12Pro                 = 844.0f;
CGFloat const SCREEN_HEIGHT_iPhone12ProMax                 = 926.0f;

@implementation Adapter

/** 共享适配器 */
+ (instancetype)shareAdapter{
    static dispatch_once_t onceToken;
    static Adapter * _instance = nil;
    dispatch_once(&onceToken, ^{
        _instance = [[self alloc] init];
    });
    return _instance;
}

/** 重载方法 */
- (instancetype)init{
    if (self = [super init]) {
        self.defaultType = AdapterPhoneType_iPhone6_6S_7_8_SE;
    }
    return self;
}

/** 设置默认类型 */
- (void)setDefaultType:(AdapterPhoneType)defaultType {
    _defaultType = defaultType;
    switch (_defaultType) {
        case AdapterPhoneType_iPhone3GS_4_4S:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhone3GS_4_4S;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhone3GS_4_4S;
            break;
        case AdapterPhoneType_iPhone5_5C_5S_5SE:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhone5_5C_5S_5SE;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhone5_5C_5S_5SE;
            break;
        case AdapterPhoneType_iPhone6_6S_7_8_SE:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhone6_6S_7_8_SE;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhone6_6S_7_8_SE;
            break;
        case AdapterPhoneType_iPhone6Plus_6SPlus_7Plus_8Plus:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhone6Plus_6SPlus_7Plus_8Plus;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhone6Plus_6SPlus_7Plus_8Plus;
            break;
        case AdapterPhoneType_iPhoneX_XS_11Pro_12mini:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhoneX_XS_11Pro_12mini;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhoneX_XS_11Pro_12mini;
            break;
        case AdapterPhoneType_iPhoneXSMax_XR_11_11ProMax:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhoneXSMax_XR_11_11ProMax;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhoneXSMax_XR_11_11ProMax;
            break;
        case AdapterPhoneType_iPhone12_12Pro:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhone12_12Pro;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhone12_12Pro;
            break;
        case AdapterPhoneType_iPhone12ProMax:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhone12ProMax;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhone12ProMax;
            break;
        case AdapterPhoneTypeOther:
            break;
        default:
            break;
    }
}

- (BOOL)isFullScreen {
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
@end

