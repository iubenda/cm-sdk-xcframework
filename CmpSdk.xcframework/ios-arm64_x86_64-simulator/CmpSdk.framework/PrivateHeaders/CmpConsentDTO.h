//
// Created by Skander Ben Abdelmalak on 30.11.21.
//

#import <CmpSdk/Metadata.h>
#import <Foundation/Foundation.h>
#import "CmpSdk/CmpUseCase.h"
@interface CmpConsentDTO : NSObject <NSSecureCoding>

@property(nonatomic, strong) NSString *cmpStringBase64Encoded;
@property(nonatomic, strong) NSString *consentString;
@property(nonatomic, strong) NSString *googleACString;
@property(nonatomic, strong) NSNumber *regulation;
@property(nonatomic, strong) NSNumber *lastButtonEvent;
@property(nonatomic, assign) BOOL gdprApplies;
@property(nonatomic, assign) BOOL tcfCompliant;
@property(nonatomic, strong) NSNumber *tcfVersion;
@property(nonatomic, strong) NSString *uspString;
@property(nonatomic, strong) NSString *regulationKey;
@property(nonatomic, strong) NSArray *googleVendorList;
@property(nonatomic, strong) NSArray *purposeConsentList;
@property(nonatomic, strong) NSArray *allPurposeList;
@property(nonatomic, strong) NSArray *allVendorList;
@property(nonatomic, strong) NSArray *enabledPurposes;
@property(nonatomic, strong) NSArray *enabledVendors;
@property(nonatomic, strong) NSArray<Metadata *> *metadata;
@property(nonatomic, assign) BOOL hasGlobalScope;
@property(nonatomic, assign) BOOL userChoiceExists;

@property (nonatomic, strong) NSDate *createdAt;
@property (nonatomic, strong) NSDate *updatedAt;
@property (nonatomic, strong) NSNumber *changedCount;
@property (nonatomic, strong) NSString *operationType;
@property(nonatomic, strong) NSDictionary<NSString *, NSString *> *consentMode;
#pragma mark Init

+ (CmpConsentDTO *)fromJSON:(NSDictionary *)jsonData :(CmpUseCase)useCase;
+ (CmpConsentDTO *)resetInstance;

#pragma mark API
- (BOOL)hasVendor:(NSString *)vendor;

- (BOOL)hasPurpose:(NSString *)purpose;

+ (bool)isValid:(CmpConsentDTO *)dto;

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
- (NSArray<Metadata *> *)getMetadata;
- (NSDictionary<NSString *, NSString *> *)getConsentModeStatus;

#pragma mark Core
- (NSString *)compareWithDTO:(CmpConsentDTO *)otherDTO;
- (NSString *)description;

@end
