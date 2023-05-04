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
@property(class) NSString *consentToolDomain;

/**
 Language that is used to create and load the request into the WKWebView – it is the request for the consent webpage. This property is mandatory.
 */

@property(class) NSString *consentToolLanguage;

/**
 Color that is used for the background of the WKWebView
 */
@property(class) UIColor *backgroundColor;
/**
 AppName that is used to create and load the request into the WKWebView – it is the request for the consent webpage. This property is mandatory.
 */
@property(class) NSString *consentToolAppName;

/**
 User ID that is used to create and load the request into the WKWebView – it is the request for the consent webpage. This property is mandatory.
 */
@property(class) NSString *consentToolId;

+ (void)setConsentToolDomain:(NSString *)consentToolDomain;

+ (NSString *)consentToolDomain;

+ (void)setConsentToolId:(NSString *)consentToolId;

+ (NSString *)consentToolId;

+ (void)setConsentToolAppName:(NSString *)consentToolAppName;

+ (NSString *)consentToolAppName;

+ (void)setConsentToolLanguage:(NSString *)consentToolLanguage;

+ (UIColor *)backgroundColor;

+ (void)setBackgroundColor:(UIColor *)backgroundColor;

+ (NSString *)consentToolLanguage;

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

+ (void)setAppleTrackingStatus:(NSUInteger)status;

+ (void)setAutoAppleTracking:(BOOL)addAttActive;

+ (BOOL)getAutoAppleTracking;

+ (NSInteger)getVerboseLevel;

+ (long)getTimeout;
    
+ (void)setVerboseLevel:(NSInteger)level;
/**
 Creates a new singleton Instance from the config and returns this
 */
+ (void)setValues:(NSString *)domain addCmpId:(NSString *)appId addAppName:(NSString *)appName addLanguage:(NSString *)language;

/**
 Returns the ConsentManager url String which needs to be called, to get the url for the consentView
 */
+ (NSString *)getConsentToolURLString:(NSString *)consent;

+ (NSInteger)getAppleTrackingStatus;

+ (BOOL)getSkipToCustomizePage;

+(void)setModalTransitionStyle:(NSInteger)style;

+ (NSInteger)getModalTransitionStyle;

+ (NSString *)description;

@end
