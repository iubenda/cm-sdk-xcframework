//
//  CMPDataStorageConsentManagerUserDefaults.h
//  GDPR
//

#import <Foundation/Foundation.h>

@interface CMPDataStorageConsentManagerUserDefaults : NSObject

+ (NSString *)usPrivacyString;

+ (void)setUsPrivacyString:(NSString *)usPrivacyString;

+ (NSString *)consentString;

+ (void)setConsentString:(NSString *)consentString;

+ (NSString *)parsedVendorConsents;

+ (void)setParsedVendorConsents:(NSString *)parsedVendorConsents;

+ (NSString *)parsedPurposeConsents;

+ (void)setParsedPurposeConsents:(NSString *)parsedPurposeConsents;

+ (NSString *)googleACString;

+ (void)setGoogleACString:(NSString *)googleACString;

+ (void)clearContents;

+ (NSString *)description;

@end
