//
//  CmpUIConfig.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 06.03.24.
//

#ifndef CmpUIConfig_h
#define CmpUIConfig_h

#import <UIKit/UIKit.h>

@interface CmpUIConfig : NSObject

+ (void)configureHalfScreenBottomForView:(UIView *)view;
+ (void)configureHalfScreenTopForView:(UIView *)view;
+ (void)configureCenterScreenForView:(UIView *)view withWidthRatio:(CGFloat)widthRatio heightRatio:(CGFloat)heightRatio;
+ (void)configureSmallCenterScreenForView:(UIView *)view;
+ (void)configureLargeTopScreenForView:(UIView *)view;
+ (void)configureLargeBottomScreenForView:(UIView *)view;

@end

#endif /* CmpUIConfig_h */
