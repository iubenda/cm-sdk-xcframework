//
//  CmpConfig.h
//  GDPR
//

#import "CMPServerResponse.h"
#import "CMPTypes.h"
#import <Foundation/Foundation.h>

/**
 Object that provides the interface for storing and retrieving GDPR-related information
 */
@interface CMPSettings : NSObject

/**
 * Setter for the consentString which was returned from the Server
 */
+ (void)setConsentString:(NSString *)consentString;

/**
 * Returns the consentString which was returned from the Server and saved in
 * this instance
 */
+ (NSString *)consentString;

/**
 * Setter for the setSubjectToGdpr which was returned from the Server
 */
+ (void)setSubjectToGdpr:(SubjectToGDPR)subjectToGdpr;

/**
 * Returns the subjectToGdpr which was returned from the Server and saved in
 * this instance
 */
+ (SubjectToGDPR)subjectToGdpr;

+ (void)setRegulationStatus:(NSNumber *)regulationStatus;

+ (void)setSubjectToGdprByRegulationStatus:(NSNumber *)regulationStatus;

+ (void)setConsentProcessData:(CMPServerResponse *)response;

@end
