//
//  CmpUtils.h
//  GDPR
//

#import "CmpConfig.h"
#import "CmpErrorTypes.h"
#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
@interface CmpUtils : NSObject


+ (BOOL)isNetworkAvailable;

+ (NSString *)getCmpLayerUrlWithConsentString:(NSString *)consentString
                                  forceOpen:(BOOL)forceOpen
                                  rejectAll:(BOOL)rejectAll
                                  acceptAll:(BOOL)acceptAll;

+ (NSString *)generateResponseUrlWithStamp:(NSInteger)stamp consentString:(NSString *)consent_string
                                          :(BOOL)force_open
                                          :(BOOL)rejectAll
                                          :(BOOL)acceptAll;

+ (BOOL)validateCmpLayerUrl:(NSURL *)url;
@end
