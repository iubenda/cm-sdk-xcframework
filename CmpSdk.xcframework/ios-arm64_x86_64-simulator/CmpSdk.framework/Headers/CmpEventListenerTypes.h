//
//  CmpEventListenerTypes.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 14.12.23.
//
#ifndef CmpEventListenerTypes_h
#define CmpEventListenerTypes_h
#import <CmpSdk/CmpButtonEvent.h>
#import <AppTrackingTransparency/ATTrackingManager.h>
#import <CmpSdk/CmpErrorTypes.h>
#import <WebKit/WebKit.h>

typedef NSDictionary<NSString *, NSString *> CMPConsentMap;
typedef BOOL (^CmpLinkClickListener)(NSString *url, WKNavigationActionPolicy *policy);
typedef void (^CmpOpenListener)(void);
typedef void (^CmpCloseListener)(void);
typedef void (^CmpNotOpenedListener)(void);
typedef void (^CmpErrorListener)(CmpErrorType errorType, NSString *message);
typedef void (^CmpButtonClickedListener)(CmpButtonEvent type);
typedef void (^CmpGoogleAnalyticsListener)(CMPConsentMap *consentMap);

API_AVAILABLE(ios(14))
typedef void (^CmpATTrackingStatusChangedListener)(ATTrackingManagerAuthorizationStatus oldStatus, ATTrackingManagerAuthorizationStatus newStatus, NSDate *lastUpdated);

typedef NS_ENUM(NSUInteger, CMPConsentType) {
    CMPConsentTypeAnalyticsStorage,
    CMPConsentTypeAdStorage,
    CMPConsentTypeAdUserData,
    CMPConsentTypeAdPersonalization
};

typedef NS_ENUM(NSUInteger, CMPConsentStatus) {
    CMPConsentStatusGranted,
    CMPConsentStatusDenied
};
#endif /* CmpEventListenerTypes_h */
