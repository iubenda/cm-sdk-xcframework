//
//  CMPDataStorageV2UserDefaults.h
//  GDPR
//

#import "PublisherRestriction.h"
#import <Foundation/Foundation.h>

@interface CMPDataStorageV2UserDefaults : NSObject

+ (NSNumber *)cmpSdkId;

+ (void)setCmpSdkId:(NSNumber *)cmpSdkId;

+ (NSNumber *)cmpSdkVersion;

+ (void)setCmpSdkVersion:(NSNumber *)cmpSdkVersion;

+ (NSNumber *)policyVersion;

+ (void)setPolicyVersion:(NSNumber *)policyVersion;

+ (NSNumber *)gdprApplies;

+ (void)setGdprApplies:(NSNumber *)gdprApplies;

+ (NSString *)publisherCC;

+ (void)setPublisherCC:(NSString *)publisherCC;

+ (NSString *)tcString;

+ (void)setTcString:(NSString *)tcString;

+ (NSString *)vendorConsents;

+ (void)setVendorConsents:(NSString *)vendorConsents;

+ (NSString *)vendorLegitimateInterests;

+ (void)setVendorLegitimateInterests:(NSString *)vendorLegitimateInterests;

+ (NSString *)purposeConsents;

+ (void)setPurposeConsents:(NSString *)purposeConsents;

+ (NSString *)purposeLegitimateInterests;

+ (void)setPurposeLegitimateInterests:(NSString *)purposeLegitimateInterests;

+ (NSString *)specialFeaturesOptIns;

+ (void)setSpecialFeaturesOptIns:(NSString *)specialFeaturesOptIns;

+ (NSArray<PublisherRestriction *> *)publisherRestrictions;

+ (void)setPublisherRestrictions:(NSArray<PublisherRestriction *> *)publisherRestrictions;

+ (PublisherRestriction *)publisherRestriction:(NSNumber *)purposeId;

+ (void)setPublisherRestriction:(PublisherRestriction *)publisherRestriction;

+ (NSString *)publisherConsent;

+ (void)setPublisherConsent:(NSString *)publisherConsent;

+ (NSString *)publisherLegitimateInterests;

+ (void)setPublisherLegitimateInterests:(NSString *)publisherLegitimateInterests;

+ (NSString *)publisherCustomPurposesConsent;

+ (void)setPublisherCustomPurposesConsent:(NSString *)publisherCustomPurposesConsent;

+ (NSString *)publisherCustomPurposesLegitimateInterests;

+ (void)setPublisherCustomPurposesLegitimateInterests:(NSString *)publisherCustomPurposesLegitimateInterests;

+ (NSNumber *)purposeOneTreatment;

+ (void)setPurposeOneTreatment:(NSNumber *)purposeOneTreatment;

+ (NSNumber *)useNoneStandardStacks;

+ (void)setUseNoneStandardStacks:(NSNumber *)useNoneStandardStacks;

+ (NSNumber *)regulationStatus;

+ (void)setRegulationStatus:(NSNumber *)useNoneStandardStacks;

+ (void)clearContents;

+ (NSString *)description;
@end
