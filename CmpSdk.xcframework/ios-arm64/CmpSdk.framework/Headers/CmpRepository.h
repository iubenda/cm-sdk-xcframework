//
// Created by Skander Ben Abdelmalak on 22.11.21.
//

#import <Foundation/Foundation.h>
@class CmpConsentDto;

static NSString *const CMP_SDK_ID = @"IABTCF_CmpSdkID";
static NSString *const CMP_SDK_VERSION = @"IABTCF_CmpSdkVersion";
static NSString *const POLICY_VERSION = @"IABTCF_PolicyVersion";
static NSString *const GDPR_APPLIES = @"IABTCF_gdprApplies";
static NSString *const PUBLISHER_CC = @"IABTCF_PublisherCC";
static NSString *const TC_STRING = @"IABTCF_TCString";
static NSString *const VENDOR_CONSENTS = @"IABTCF_VendorConsents";
static NSString *const VENDOR_LEGITIMATE_INTERESTS = @"IABTCF_VendorLegitimateInterests";
static NSString *const PURPOSE_CONSENTS = @"IABTCF_PurposeConsents";
static NSString *const PURPOSE_LEGITIMATE_INTERESTS = @"IABTCF_PurposeLegitimateInterests";
static NSString *const SPECIAL_FEATURES_OPT_INS = @"IABTCF_SpecialFeaturesOptIns";
static NSString *const PUBLISHER_RESTRICTIONS = @"IABTCF_PublisherRestrictions%d"; // %d = Purpose ID
static NSString *const PUBLISHER_CONSENT = @"IABTCF_PublisherConsent";
static NSString *const PUBLISHER_LEGITIMATE_INTERESTS = @"IABTCF_PublisherLegitimateInterests";
static NSString *const PUBLISHER_CUSTOM_PURPOSES_CONSENTS = @"IABTCF_PublisherCustomPurposesConsents";
static NSString *const PUBLISHER_CUSTOM_PURPOSES_LEGITIMATE_INTERESTS = @"IABTCF_PublisherCustomPurposesLegitimateInterests";
static NSString *const PURPOSE_ONE_TREATMENT = @"IABTCF_PurposeOneTreatment";
static NSString *const USE_NONE_STANDARD_STACKS = @"IABTCF_UseNoneStandardStacks";
static NSString *const CMP_REGULATION_STATUS = @"IABTCF_RegulationStatus";

@interface CmpRepository : NSObject
+ (void)saveCmpUserConsent:(CmpConsentDto *)userConsent;
+ (CmpConsentDto *)fetchCmpUserConsent;
+ (NSString *)getCmpStringBase64Encoded;
+ (void)removeCmpConsent;
+ (BOOL)hasConsent;
@end
