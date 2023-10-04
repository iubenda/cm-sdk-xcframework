//
//  CmpUtils.h
//  GDPR
//

#import "CmpConfig.h"
#import "CmpErrorTypes.h"
#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
@interface CmpUtils : NSObject

+ (NSString *)addPaddingIfNeeded:(NSString *)base64String;

+ (const char *)NSDataToBinary:(NSData *)decodedData;

+ (NSString *)replaceSafeCharacters:(NSString *)consentString;

+ (NSString *)safeBase64ConsentString:(NSString *)consentString;

+ (NSInteger)BinaryToDecimal:(const char *)buffer fromIndex:(int)startIndex toIndex:(int)endIndex;

+ (NSInteger)BinaryToDecimal:(const char *)buffer fromIndex:(int)startIndex length:(int)totalOffset;

+ (NSString *)BinaryToString:(const char *)buffer fromIndex:(int)startIndex length:(int)totalOffset;

+ (NSString *)BinaryToLanguage:(const char *)buffer fromIndex:(int)startIndex length:(int)totalOffset;

+ (NSNumber *)BinaryToNumber:(const char *)buffer fromIndex:(int)startIndex length:(int)totalOffset;

+ (BOOL)isNetworkAvailable;

+ (const char *)binaryConsentFrom:(NSString *)consentString;

+ (NSString *)binaryStringConsentFrom:(NSString *)consentString;

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
