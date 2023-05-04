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

#import "CmpConfig.h"
#import "CMPConsentTool.h"
#import "ATTrackingHelper.h"
#import "Logger.h"
#import "CMPConsentV2Constant.h"
#import "CMPConsentV2Parser.h"
#import "PublisherRestriction.h"
#import "PublisherRestrictionTypeValue.h"
#import "CmpReachability.h"
#import "CMPServerResponse.h"
#import "CMPSettings.h"
#import "CMPTypes.h"
#import "CmpUtils.h"
#import "CmpConsentDto.h"
#import "CmpPlaceholderParams.h"
#import "CmpLayerViewController.h"
#import "CmpPlaceholderView.h"
#import "CmpRepository.h"
#import "CmpConsentService.h"
#import "CMPDataStorageConsentManagerUserDefaults.h"
#import "CMPDataStoragePrivateUserDefaults.h"
#import "CMPDataStorageV1Protocol.h"
#import "CMPDataStorageV1UserDefaults.h"
#import "CMPDataStorageV2UserDefaults.h"
#import "CmpSdk.h"

FOUNDATION_EXPORT double CmpSdkVersionNumber;
FOUNDATION_EXPORT const unsigned char CmpSdkVersionString[];

