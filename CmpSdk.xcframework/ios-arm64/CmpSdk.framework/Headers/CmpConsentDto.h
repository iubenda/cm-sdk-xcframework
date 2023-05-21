//
// Created by Skander Ben Abdelmalak on 30.11.21.
//

#import "Metadata.h"
#import <Foundation/Foundation.h>

@interface CmpConsentDto : NSObject <NSSecureCoding>

@property(nonatomic, strong) NSString *cmpStringBase64Encoded;
@property(nonatomic, strong) NSString *consentString;
@property(nonatomic, strong) NSString *googleACString;
@property(nonatomic, assign) NSNumber *regulation;
@property(nonatomic, assign) NSNumber *lastButtonEvent;
@property(nonatomic, assign) BOOL gdprApplies;
@property(nonatomic, assign) NSString *regulationKey;
@property(nonatomic, assign) NSNumber *tcfVersion;
@property(nonatomic, assign) BOOL tcfCompliant;
@property(nonatomic, assign) NSString *uspString;
@property(nonatomic, strong) NSArray *googleVendorList;
@property(nonatomic, strong) NSArray *purposeConsentList;
@property(nonatomic, strong) NSArray *allPurposeList;
@property(nonatomic, strong) NSArray *allVendorList;
@property(nonatomic, strong) NSArray *enabledPurposes;
@property(nonatomic, strong) NSArray *enabledVendors;
@property(nonatomic, strong) NSArray<Metadata *> *metadata;
@property(nonatomic, assign) BOOL hasGlobalScope;
@property(nonatomic, assign) BOOL userChoiceExists;

#pragma mark Init

+ (CmpConsentDto *)fromJSON:(NSDictionary *)jsonData;
+ (CmpConsentDto *)createEmpty;

#pragma mark API
- (BOOL)hasVendor:(NSString *)vendor;

- (BOOL)hasPurpose:(NSString *)purpose;

+ (bool)isValid:(CmpConsentDto *)dto;

#pragma mark Getter
- (NSArray *)getEnabledVendorList;
- (NSArray *)getEnabledPurposeList;
- (NSArray *)getDisabledVendorList;
- (NSArray *)getDisabledPurposeList;
- (NSString *)getCmpStringBase64Encoded;
- (NSString *)getUsPrivacy;

- (NSArray *)getAllVendorList;
- (NSString *)getAllVendors;
- (NSArray *)getAllPurposeList;
- (NSString *)getAllPurposes;

#pragma mark Core
- (NSString *)description;
@end
