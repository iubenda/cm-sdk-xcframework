//
//  CMPDataStorageV1Protocol.h
//  GDPR
//

#import "CMPTypes.h"
#import <Foundation/Foundation.h>

@protocol CMPDataStorageV1Protocol
@required

/**
 The consent string passed as a websafe base64-encoded string.
 */
@property(nonatomic, retain) NSString *consentString;

/**
 Enum that indicates    'SubjectToGDPR_Unknown'- value -1, unset.
                        'SubjectToGDPR_No' – value 0, not subject to GDPR
                        'SubjectToGDPR_Yes' – value 1, subject to GDPR,
 */
@property(nonatomic, assign) SubjectToGDPR subjectToGDPR;

/**
 String that contains the consent information for all vendors
 */
@property(nonatomic, retain) NSString *parsedVendorConsents;

/**
 String that contains the consent information for all purposes
 */
@property(nonatomic, retain) NSString *parsedPurposeConsents;

/**
 Boolean that indicates if a CMP implementing the iAB specification is present in the application
 */
@property(nonatomic, assign) BOOL cmpPresent;

/**
 Removes all properties form the Storage
 */
- (void)clearContents;

@end
