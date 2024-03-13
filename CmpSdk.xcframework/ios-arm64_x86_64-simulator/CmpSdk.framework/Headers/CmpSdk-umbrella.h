#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "CmpATTrackingManager.h"
#import "CmpButtonEvent.h"
#import "CmpCallbackTypes.h"
#import "CmpChangeItem.h"
#import "CmpConfig.h"
#import "CmpConsentChangeInfo.h"
#import "CMPConsentTool.h"
#import "CmpErrorTypes.h"
#import "CmpEventListenerTypes.h"
#import "CmpEventMetadata.h"
#import "CmpGoogleConsentMap.h"
#import "CmpLayout.h"
#import "CmpLog.h"
#import "CmpLogLevel.h"
#import "CmpNotificationConstants.h"
#import "CmpSdk.h"
#import "CmpUIConfig.h"

FOUNDATION_EXPORT double CmpSdkVersionNumber;
FOUNDATION_EXPORT const unsigned char CmpSdkVersionString[];

