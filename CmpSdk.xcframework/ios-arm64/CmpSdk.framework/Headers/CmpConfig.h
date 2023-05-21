//
//  CmpConfig.h
//  GDPR
//

#import <Foundation/Foundation.h>

/**
 Object that provides the interface for storing and retrieving GDPR-related information
 */
@interface CmpConfig : NSObject

/**
 NSURL that is used to create and load the request into the WKWebView – it is the request for the consent webpage. This property is mandatory.
 */
@property(class) NSString *domain;

/**
 Language that is used to create and load the request into the WKWebView – it is the request for the consent webpage. This property is mandatory.
 */

@property(class) NSString *language;

/**
 Color that is used for the background of the WKWebView
 */
@property(class) UIColor *backgroundColor;
/**
 AppName that is used to create and load the request into the WKWebView – it is the request for the consent webpage. This property is mandatory.
 */
@property(class) NSString *appName;

/**
 User ID that is used to create and load the request into the WKWebView – it is the request for the consent webpage. This property is mandatory.
 */
@property(class) NSString *codeId;

+ (void)setDomain:(NSString *)consentToolDomain;

+ (NSString *)domain;

+ (void)setCodeId:(NSString *)consentToolId;

+ (NSString *)codeId;

+ (void)setAppName:(NSString *)consentToolAppName;

+ (NSString *)appName;

+ (void)setLanguage:(NSString *)consentToolLanguage;

+ (UIColor *)backgroundColor;

+ (void)setBackgroundColor:(UIColor *)backgroundColor;

+ (NSString *)language;

+ (long)timeout;

/**
 Returns if all Config parameter are set
 */
+ (BOOL)isValid;

+ (void)setSkipToCustomizePage;

+ (void)setCustomLayout:(CGRect)cl;

+ (CGRect)getCustomLayout;

+ (void)removeCustomLayout;

+ (BOOL)hasCustomLayout;
/**
 Returns the Advertising Device ID
 */
+ (void)setIDFA:(NSString *)setIDFA;

+ (NSString *)getIdfa;

- (CmpConfig *)setTimeout:(long)t;

+ (void)setDesignId:(NSString *)design;

+ (NSString *)getDesignId;

+ (void)setAppleTrackingStatus:(NSUInteger)status;

+ (void)setAutoAppleTracking:(BOOL)addAttActive;

+ (BOOL)getAutoAppleTracking;

+ (NSInteger)getVerboseLevel;

+ (long)getTimeout;

+ (void)setVerboseLevel:(NSInteger)level;
/**
 Creates a new singleton Instance from the config and returns this
 */
+ (void)setValues:(NSString *)domain addCodeId:(NSString *)appId addAppName:(NSString *)appName addLanguage:(NSString *)language;

/**
 Returns the ConsentManager url String which needs to be called, to get the url for the consentView
 */
+ (NSString *)getConsentToolURLString:(NSString *)consent;

+ (NSInteger)getAppleTrackingStatus;

+ (BOOL)getSkipToCustomizePage;

+ (void)setModalTransitionStyle:(NSInteger)style;

+ (NSInteger)getModalTransitionStyle;

+ (NSString *)description;

@end
