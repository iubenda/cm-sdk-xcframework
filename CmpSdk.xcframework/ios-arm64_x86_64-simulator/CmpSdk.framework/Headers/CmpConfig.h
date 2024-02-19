//
//  CmpConfig.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 12.12.23.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CmpSdk/CmpLogLevel.h>
#import <CmpSdk/CmpLayout.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * `CmpConfig` is a class for managing the configuration settings of the CMP SDK.
 * It provides properties for setting up and customizing the behavior of the SDK.
 */
@interface CmpConfig : NSObject

/// Shared instance of `CmpConfig`.
@property (class, nonatomic, readonly) CmpConfig *sharedConfig;

/// Unique identifier for the CMP configuration.
@property (nonatomic, strong, readonly) NSString *id;

/// Domain associated with the CMP configuration.
@property (nonatomic, strong, readonly) NSString *domain;

/// Application name using the CMP SDK.
@property (nonatomic, strong, readonly) NSString *appName;

/// Language code for localization.
@property (nonatomic, strong, readonly) NSString *language;

/// Package name of the application.
@property (nonatomic, strong, readonly) NSString *packageName;

// General configurations

/// Identifier for Advertisers (IDFA).
@property (nonatomic, strong, nullable) NSString *idfa;

/// Flag indicating whether the SDK is in debug mode.
@property (nonatomic, assign) BOOL isDebugMode;

/// Log level for SDK logging.
@property (nonatomic, assign) CmpLogLevel logLevel;

/// domain Whitelist
@property (nonatomic, strong) NSSet<NSString *> *domainWhitelist;

/// Flag indicating whether App Tracking Transparency request is handled automatically during initialize function
@property (nonatomic, assign) BOOL isAutomaticATTRequest;

// Webview configurations

/// Timeout duration for webview operations.
@property (nonatomic, assign) NSInteger timeout;

/// Maximum number of retry attempts for webview loading.
@property (nonatomic, assign) NSInteger maxRetries;

/// Delay between retry attempts for webview loading.
@property (nonatomic, assign) NSInteger retryDelay;

/// Identifier for the CMP design.
@property (nonatomic, strong, nullable) NSString *designId;

/// Flag indicating whether to jump to settings page if necessary.
@property (nonatomic, assign) BOOL isJumpToSettingsPage;

// Layout configurations

/// Layout configuration for the CMP UI.
@property (nonatomic, strong) CmpLayout *cmpLayout;

@property (nonatomic, strong) UIViewController *viewController;
/**
 * Sets up the CMP configuration with the specified parameters.
 *
 * @param id The unique identifier for the CMP configuration.
 * @param domain The domain associated with the CMP configuration.
 * @param appName The name of the application using the CMP SDK.
 * @param language The language code for localization.
 * @return An instance of `CmpConfig`.
 */
- (CmpConfig *)setupWithId:(NSString *)id domain:(NSString *)domain appName:(NSString *)appName language:(NSString *)language;

// Methods for configuring various aspects of the CMP SDK.

- (CmpConfig *)withTimeout:(NSTimeInterval)timeout;
- (CmpConfig *)withJumpToSettingsPage:(BOOL)jumpToSettingsPage;
- (CmpConfig *)withDebugMode:(BOOL)debugMode;
- (CmpConfig *)withDesignId:(NSString *)designId;
- (CmpConfig *)withAutomaticATTRequest:(BOOL)isAutomaticATTRequest;
- (CmpConfig *)withRetryDelay:(NSInteger)retryDelay;
- (CmpConfig *)withMaxRetries:(NSInteger)maxRetries;
- (CmpConfig *)withViewController:(UIViewController *)viewController;

- (UIViewController *)currentViewController;
/// Retrieves the current `CmpLayout` configuration.
- (CmpLayout *)getCmpLayout;

/// Checks if the current configuration is valid.
- (BOOL)isValid;

/// Sets the flag to jump to the settings page.
- (void)setJumpToSettingsPage;

/// Enables debug mode for the SDK.
- (void)enableDebugMode;

/// Resets the configuration to its default state.
- (void)reset;

@end

NS_ASSUME_NONNULL_END
