//
//  CmpUtils.h
//  GDPR
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <CmpSdk/CmpButtonEvent.h>
#import <CmpSdk/CmpConfig.h>
#import <CmpSdk/CmpErrorTypes.h>
#import "CmpSdk/CmpATTrackingStatus.h"
@interface CmpUtils : NSObject

+ (BOOL)isNetworkAvailable;

+ (BOOL)validateCmpLayerUrl:(NSURL *)url;

+ (UIViewController *)topViewController;

+ (void)dispatchToMainThread:(void (^)(void))block;

+ (CmpButtonEvent)buttonEventFromInt:(NSInteger)intValue;

+ (NSString *)jsonStringFromDictionary:(NSDictionary *)dictionary;

+ (BOOL)isDarkModeEnabled;
@end
