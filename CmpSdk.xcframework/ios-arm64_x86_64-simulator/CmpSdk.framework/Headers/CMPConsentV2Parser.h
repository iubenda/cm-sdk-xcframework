//
//  CMPConsentV2Parser.h
//  GDPR
//

#import "PublisherRestriction.h"
#import <Foundation/Foundation.h>

@interface CMPConsentV2Parser : NSObject

/**
 Initilaises the Class and set all variables to its content by filling them with the cosentString parameters.
 */
- (id)init:(NSString *)consentString;
- (NSString *)description;

/**
 The SDK Id that is beeing used by the consentString
 */
@property(nonatomic, retain) NSNumber *cmpSdkId;

/**
 The Sdk Version that is used by the consentManager
 */
@property(nonatomic, retain) NSNumber *cmpSdkVersion;

/**
 If GDPR Applies to this ConsentString
 */
@property(nonatomic, retain) NSNumber *gdprApplies;
/**
 Gets the purpose onTreatment from the consentString
 */
@property(nonatomic, retain) NSNumber *purposeOneTreatment;
/**
 If the consentString allows non Standard Stacks
 */
@property(nonatomic, retain) NSNumber *useNoneStandardStacks;
/**
 The Publischer CC
 */
@property(nonatomic, retain) NSString *publisherCC;
/**
 The vendor Consents given in the ConsentString
 */
@property(nonatomic, retain) NSString *vendorConsents;
/**
 The Vendor Legitimation Interest given in the ConsentString
 */
@property(nonatomic, retain) NSString *vendorLegitimateInterests;
/**
 The Purpose consent given in the ConsentString
 */
@property(nonatomic, retain) NSString *purposeConsents;
/**
 The Purpose Legitimation Interest given in the ConsentString
 */
@property(nonatomic, retain) NSString *purposeLegitimateInterests;
/**
 The Special feature Opts given in the ConsentString
 */
@property(nonatomic, retain) NSString *specialFeaturesOptIns;
/**
 The Publisher Restrictions given in the ConsentString
 */
@property(nonatomic, retain) NSArray<PublisherRestriction *> *publisherRestrictions;
/**
 The Publisher Consnet given in the ConsentString
 */
@property(nonatomic, retain) NSString *publisherConsent;
/**
 The Publisher LegitimationInterest in the ConsentString
 */
@property(nonatomic, retain) NSString *publisherLegitimateInterests;
/**
 The Publisher Custom Purpose Consnet in the ConsentString
 */
@property(nonatomic, retain) NSString *publisherCustomPurposesConsent;
/**
 The Publisher Custom Purpose Legitmation Interest given in the ConsentString
 */
@property(nonatomic, retain) NSString *publisherCustomPurposesLegitimateInterests;

/**
 The Disclosed Vendors from DisclosedVendor String as binary String
 */
@property(nonatomic, retain) NSString *cmpDisclosedVendors;
/**
 The Allowed Vendors from AllowedVendor String as binary String
 */
@property(nonatomic, retain) NSString *cmpAllowedVendors;

/**
 The Allowed Vendors from AllowedVendor String as binary String
 */
@property(nonatomic, retain) NSNumber *version;

/**
 The Allowed Vendors from AllowedVendor String as binary String
 */
@property(nonatomic, retain) NSNumber *created;

/**
 The Allowed Vendors from AllowedVendor String as binary String
 */
@property(nonatomic, retain) NSNumber *lastUpdated;

/**
 The Allowed Vendors from AllowedVendor String as binary String
 */
@property(nonatomic, retain) NSNumber *consentScreen;

/**
 The Allowed Vendors from AllowedVendor String as binary String
 */
@property(nonatomic, retain) NSString *consentLanguage;

/**
 The Allowed Vendors from AllowedVendor String as binary String
 */
@property(nonatomic, retain) NSNumber *vendorListVersion;

/**
 The Allowed Vendors from AllowedVendor String as binary String
 */
@property(nonatomic, retain) NSNumber *isServiceSpecific;

/**
 The Policy Version of the ConsentString
 */
@property(nonatomic, retain) NSNumber *policyVersion;

+ (NSString *)extractRangeFieldSection:(const char *)buffer fromIndex:(int)startIndex offset:(NSInteger *)offset;

+ (NSString *)getBitExtension:(NSMutableString *)value toIndex:(int)toIndex;

+ (NSString *)getBitRangeExtension:(NSMutableString *)value fromIndex:(int)fromIndex toIndex:(int)toIndex;

@end
