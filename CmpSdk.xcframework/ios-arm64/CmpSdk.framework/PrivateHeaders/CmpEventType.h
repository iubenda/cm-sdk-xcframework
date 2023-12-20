//
//  CmpEventType.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//

#ifndef CmpEventType_h
#define CmpEventType_h

typedef NS_ENUM(NSUInteger, CmpEventType) {
    // Lifetime
    CmpEventTypeManagerInitialized = 1000,
    // WebView
    CmpEventTypeCheckConsentInvoked = 1001,
    // CmpSubsctiptionEvents
    CmpEventTypeConsentScreenOpened = 102,
    CmpEventTypeConsentScreenNotOpened = 129,
    
    // API Calls
    CmpEventTypeApiRequestInvoked = 1031,
    CmpEventTypeDryCheckInvoked = 1003,
    CmpEventTypeDryCheckWithCachingInvoked = 1004,
    CmpEventTypeImportedConsentInvoked = 1005,
    CmpEventTypeConsentImportCompleted = 1006,
    CmpEventTypeConsentEnabledPurposesInvoked = 1007,
    CmpEventTypeConsentDisabledPurposesInvoked = 1008,
    CmpEventTypeConsentEnableVendorsInvoked = 1009,
    CmpEventTypeConsentDisabledVendorsInvoked = 1010,
    CmpEventTypeAcceptAllInvoked = 1011,
    CmpEventTypeRejectAllInvoked = 1012,
    // WebView
    CmpEventTypeWebViewInitialized = 113,
    CmpEventTypeWebViewErrorOccurred = 114,
    CmpEventTypeWebViewOpenRequested = 115,
    CmpEventTypeWebViewConsentReceived = 116,
    CmpEventTypeWebViewTimedOut = 117,
    CmpEventTypeWebViewRequestRetried = 118,
    CmpEventTypeWebViewLoadCompleted = 119,

    // UI
    CmpEventTypeConsentLayerDisplayed = 12,
    CmpEventTypeConsentLayerDismissed = 13,

    // Interface Functionalities
    CmpEventTypeConsentCleared = 1022,
    CmpEventTypeVendorCheckInvoked = 1023,
    CmpEventTypePurposeCheckInvoked = 1024,

    // iOS Specific
    CmpEventTypeATTTrackingStatusRequested = 1025,

    // Other
    CmpEventTypeConsentCreated = 1026,
    CmpEventTypeConsentUpdated = 1027,
    CmpEventTypeConsentUpdateOrCreateFailed = 1028,
    CmpEventTypeAPIRequestCompleted = 130,
    CmpEventConsentReadFailed = 31,
    CmpEventTypeWriteFailed = 32,
    CmpEventTypeDescriptionFieldsUpdated =33,
    CmpEventTypeDescriptionFieldsCleaned = 34,
    CmpEventTypeReadData = 35,
    CmpEventTypeWriteData = 36,
    CmpEventTypeDeleteKey = 37,
};
NSString *StringFromEventType(CmpEventType eventType);
#endif /* CmpEventType_h */
