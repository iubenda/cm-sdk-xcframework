//
// Created by Skander Ben Abdelmalak on 30.11.21.
//

#import <Foundation/Foundation.h>

@interface CmpConsentDto : NSObject<NSSecureCoding>

@property(nonatomic, strong) NSString *cmpApiKey;
@property(nonatomic, strong) NSString *consentString;
@property(nonatomic, assign) NSNumber *regulation;
@property(nonatomic, assign) BOOL gdprApplies;
@property(nonatomic, assign) NSString *regulationKey;
@property(nonatomic, assign) NSNumber *tcfVersion;
@property(nonatomic, assign) BOOL tcfCompliant;
@property(nonatomic, assign) NSString *uspString;
@property(nonatomic, strong) NSArray *googleVendorList;
@property(nonatomic, strong) NSArray *purposeConsentList;
@property(nonatomic, strong) NSArray *purposeList;
@property(nonatomic, strong) NSArray *vendorList;
@property(nonatomic, strong) NSArray *metadata;
@property(nonatomic, assign) BOOL hasGlobalScope;
@property(nonatomic,assign) BOOL userChoiceExists;

#pragma mark Init
+ (CmpConsentDto *)fromJSON:(NSDictionary *)jsonData;

#pragma mark API
- (BOOL)hasVendor:(NSString *)vendor;

- (BOOL)hasPurpose:(NSString *)purpose;

+ (bool)isValid:(CmpConsentDto *)dto;

#pragma mark Getter
- (NSArray *)getVendorList;
- (NSArray *)getPurposeList;
- (NSString *)getUsPrivacy;

#pragma mark Core
- (NSString *)description;
@end

@interface Metadata : NSObject
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *value;
@property (nonatomic, strong) NSNumber *type;
@end
