//
//  CmpLayout.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 15.12.23.
//

#ifndef CmpLayout_h
#define CmpLayout_h
#import <UIKit/UIKit.h>

@interface CmpLayout : NSObject

@property (nonatomic, assign) CGFloat cornerRadius;
@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, assign) CGFloat shadowOpacity;
@property (nonatomic, assign) CGSize shadowOffset;
@property (nonatomic, strong) UIColor *shadowColor;
@property (nonatomic, assign) BOOL shouldAnimatePresentation;
@property (nonatomic, assign) CGRect customLayout;
@property (nonatomic, assign) BOOL hasCustomLayout;

// Chainable setters
- (instancetype)withCornerRadius:(CGFloat)cornerRadius;
- (instancetype)withBackgroundColor:(UIColor *)backgroundColor;
- (instancetype)withShadowOpacity:(CGFloat)shadowOpacity;
- (instancetype)withShadowOffset:(CGSize)shadowOffset;
- (instancetype)withShadowColor:(UIColor *)shadowColor;
- (instancetype)withShouldAnimatePresentation:(BOOL)shouldAnimatePresentation;
- (instancetype)withCustomLayout:(CGRect)customLayout;

// Add any other style-related properties you need
- (BOOL)hasCustomLayout;
- (void)removeCustomLayout;
- (void)applyToView:(UIView *)view;

+ (instancetype)defaultLayout;

@end

#endif /* CmpLayout_h */
