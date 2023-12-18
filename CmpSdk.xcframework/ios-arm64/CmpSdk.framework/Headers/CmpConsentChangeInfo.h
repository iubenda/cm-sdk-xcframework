//
//  CmpConsentChangeInfo.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//

#ifndef CmpConsentChangeInfo_h
#define CmpConsentChangeInfo_h
#import <CmpSdk/CmpChangeItem.h>
#import <CmpSdk/CmpEventMetadata.h>
@interface CmpConsentChangeInfo : NSObject <NSCoding>

@property (nonatomic, strong) CmpEventMetadata *eventMetadata;
@property (nonatomic, strong) NSArray *addedVendors;
@property (nonatomic, strong) NSArray *removedVendors;
@property (nonatomic, strong) NSArray *addedPurposes;
@property (nonatomic, strong) NSArray *removedPurposes;
@property (nonatomic, strong) CmpChangeItem *consentStringChange;
@property (nonatomic, strong) CmpChangeItem *iabUSPrivacyStringChange;
@property (nonatomic, strong) CmpChangeItem *googleAdditionalConsentModeChange;

@property (nonatomic, strong) CmpChangeItem *gdprAppliesChange;
@property (nonatomic, strong) CmpChangeItem *lastButtonEventChange;
@property (nonatomic, strong) CmpChangeItem *regulationChange;
@property (nonatomic, strong) CmpChangeItem *tcfVersionChange;
@property (nonatomic, strong) CmpChangeItem *tcfCompliantChange;
@property (nonatomic, strong) CmpChangeItem *userChoiceExistsChange;
@property (nonatomic, strong) CmpChangeItem *googleVendorConsentsChange;

- (BOOL)userAcceptedVendors;
- (BOOL)userDeclinedVendors;
- (BOOL)userAcceptedPurposes;
- (BOOL)userDeclinedPurposes;

- (NSTimeInterval)ageOfDataInSeconds;
- (BOOL)hasAnyChanges;
- (NSDictionary *)changedItemsMapRepresentation;
- (NSArray *)listChangedItems;
- (NSDictionary *)dictionaryRepresentation;
@end

#endif /* CmpConsentChangeInfo_h */
