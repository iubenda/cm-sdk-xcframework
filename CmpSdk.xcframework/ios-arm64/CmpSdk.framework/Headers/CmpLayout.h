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

/// The corner radius for UI elements.
@property (nonatomic, assign) CGFloat cornerRadius;

/// The background color for UI elements.
@property (nonatomic, strong) UIColor *backgroundColor;

/// The opacity for shadow effects on UI elements.
@property (nonatomic, assign) CGFloat shadowOpacity;

/// The offset size for shadow effects on UI elements.
@property (nonatomic, assign) CGSize shadowOffset;

/// The color of the shadow for UI elements.
@property (nonatomic, strong) UIColor *shadowColor;

/// Determines whether the presentation of UI elements should be animated.
@property (nonatomic, assign) BOOL shouldAnimatePresentation;

/// A custom layout frame for UI elements if a custom layout is required.
@property (nonatomic, assign) CGRect customLayout;

/// Indicates if a custom layout is being used.
@property (nonatomic, assign) BOOL hasCustomLayout;

/**
 * Sets the corner radius and returns the instance for chaining.
 * - Parameter cornerRadius: The corner radius for UI elements.
 */
- (instancetype)withCornerRadius:(CGFloat)cornerRadius;

/**
 * Sets the background color and returns the instance for chaining.
 * - Parameter backgroundColor: The background color for UI elements.
 */
- (instancetype)withBackgroundColor:(UIColor *)backgroundColor;

/**
 * Sets the shadow opacity and returns the instance for chaining.
 * - Parameter shadowOpacity: The opacity for shadow effects on UI elements.
 */
- (instancetype)withShadowOpacity:(CGFloat)shadowOpacity;

/**
 * Sets the shadow offset and returns the instance for chaining.
 * - Parameter shadowOffset: The offset size for shadow effects on UI elements.
 */
- (instancetype)withShadowOffset:(CGSize)shadowOffset;

/**
 * Sets the shadow color and returns the instance for chaining.
 * - Parameter shadowColor: The color of the shadow for UI elements.
 */
- (instancetype)withShadowColor:(UIColor *)shadowColor;

/**
 * Sets whether the presentation of UI elements should be animated and returns the instance for chaining.
 * - Parameter shouldAnimatePresentation: Determines if the presentation should be animated.
 */
- (instancetype)withShouldAnimatePresentation:(BOOL)shouldAnimatePresentation;

/**
 * Sets a custom layout frame and returns the instance for chaining.
 * - Parameter customLayout: A custom layout frame for UI elements if a custom layout is required.
 */
- (instancetype)withCustomLayout:(CGRect)customLayout;

// Additional methods

- (BOOL)hasCustomLayout;
- (void)removeCustomLayout;

/**
 * Applies the current layout properties to the specified view.
 * - Parameter view: The view to apply the layout properties to.
 */
- (void)applyToView:(UIView *)view;

/**
 * Returns the default layout configuration.
 */
+ (instancetype)defaultLayout;

@end

#endif /* CmpLayout_h */
