//
//  CmpUtils.h
//  GDPR
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import "CMPServerResponse.h"
#import "CmpConfig.h"
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

+ (CMPServerResponse *)     getAndSaveServerResponse:(void (^)(NSString *error))networkErrorListener serverErrorListener:(void (^)(
    NSString *error))serverErrorListener withConsent:(NSString *)consent;

+ (CMPServerResponse *) getServerResponse:(void (^)(NSString *error))errorListener  withConsent:(NSString *) consent;

+ (const char *)binaryConsentFrom:(NSString *)consentString;

+ (NSString *)binaryStringConsentFrom:(NSString *)consentString;

+ (NSURL *)getCmpLayerUrl:(NSString *)consent_string :(BOOL)force_open :(BOOL)rejectAll;

+ (NSURL *)generateResponseUrlWithStamp:(NSInteger)stamp consentString:(NSString *)consent_string :(BOOL)force_open :(BOOL)rejectAll;

+ (BOOL)validateCmpLayerUrl:(NSURL *)url;
@end
