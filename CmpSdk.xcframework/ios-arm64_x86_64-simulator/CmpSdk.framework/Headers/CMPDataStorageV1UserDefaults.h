//
//  CMPDataStorageV1UserDefaults.h
//  GDPR
//

#import "CMPTypes.h"
#import <Foundation/Foundation.h>

@interface CMPDataStorageV1UserDefaults : NSObject
+ (NSString *)consentString;

+ (void)setConsentString:(NSString *)consentString;

+ (SubjectToGDPR)subjectToGDPR;

+ (void)setSubjectToGDPR:(SubjectToGDPR)subjectToGDPR;

+ (BOOL)cmpPresent;

+ (void)setCmpPresent:(BOOL)cmpPresent;

+ (NSString *)parsedVendorConsents;

+ (void)setParsedVendorConsents:(NSString *)parsedVendorConsents;

+ (NSString *)parsedPurposeConsents;

+ (void)setParsedPurposeConsents:(NSString *)parsedPurposeConsents;

+ (void)clearContents;

+ (NSString *)description;
@end
