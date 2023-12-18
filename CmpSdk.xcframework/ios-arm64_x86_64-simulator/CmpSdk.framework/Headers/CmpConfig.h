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

@interface CmpConfig : NSObject

@property (class, nonatomic, readonly) CmpConfig *sharedConfig;

@property (nonatomic, strong, readonly) NSString *id;
@property (nonatomic, strong, readonly) NSString *domain;
@property (nonatomic, strong, readonly) NSString *appName;
@property (nonatomic, strong, readonly) NSString *language;
@property (nonatomic, strong, readonly) NSString *packageName;
// General configurations
@property (nonatomic, strong, nullable) NSString *idfa;
@property (nonatomic, assign) BOOL isDebugMode;
@property (nonatomic, assign) CmpLogLevel logLevel;
// ATT
@property (nonatomic, assign) BOOL isAutomaticATTRequest;
// Webview configurations
@property (nonatomic, assign) NSInteger timeout;
@property (nonatomic, assign) NSInteger maxRetries;
@property (nonatomic, assign) NSInteger retryDelay;
@property (nonatomic, strong, nullable) NSString *designId;
@property (nonatomic, assign) BOOL isJumpToSettingsPage;

// Layout configurations
@property (nonatomic, strong) CmpLayout *cmpLayout;

- (CmpConfig *)setupWithId:(NSString *)id domain:(NSString *)domain appName:(NSString *)appName language:(NSString *)language;

- (CmpConfig *)withTimeout:(NSTimeInterval)timeout;
- (CmpConfig *)withJumpToSettingsPage:(BOOL)jumpToSettingsPage;
- (CmpConfig *)withDebugMode:(BOOL)debugMode;
- (CmpConfig *)withDesignId:(NSString *)designId;
- (CmpConfig *)withAutomaticATTRequest:(BOOL)isAutomaticATTRequest;
- (CmpConfig *)withRetryDelay:(NSInteger)retryDelay;
- (CmpConfig *)withMaxRetries:(NSInteger)maxRetries;

- (CmpLayout *)getCmpLayout;
- (BOOL)isValid;
- (void)setJumpToSettingsPage;
- (void)enableDebugMode;
- (void)reset;

@end

NS_ASSUME_NONNULL_END
