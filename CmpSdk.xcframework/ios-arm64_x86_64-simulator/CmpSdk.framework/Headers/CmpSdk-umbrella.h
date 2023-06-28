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

#import "ATTrackingHelper.h"
#import "CMPConsentTool.h"
#import "CMPConsentV2Constant.h"
#import "CMPServerResponse.h"
#import "CMPTypes.h"
#import "CmpButtonEvents.h"
#import "CmpConfig.h"
#import "CmpConsentDto.h"
#import "CmpConsentService.h"
#import "CmpErrorTypes.h"
#import "CmpLayerViewController.h"
#import "CmpPlaceholderParams.h"
#import "CmpPlaceholderView.h"
#import "CmpReachability.h"
#import "CmpRepository.h"
#import "CmpSdk.h"
#import "CmpUtils.h"
#import "Logger.h"
#import "Metadata.h"

FOUNDATION_EXPORT double CmpSdkVersionNumber;
FOUNDATION_EXPORT const unsigned char CmpSdkVersionString[];
