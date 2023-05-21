//
//  PublisherRestriction.h
//  GDPR
//

#import "PublisherRestrictionTypeValue.h"
#import <Foundation/Foundation.h>

/**
 Object that provides the interface for storing and retrieving GDPR-related information
 */
@interface PublisherRestriction : NSObject

/**
 The purposeID of the restriction
 */
@property(nonatomic, assign) int purposeId;

/**
 The restrictionType set to this restriction
 */
@property(nonatomic, copy) NSMutableArray<PublisherRestrictionTypeValue *> *restrictionTypes;

- (id)init:(int)pId type:(PublisherRestrictionTypeValue *)rtype;

- (id)init:(int)pId restrictionTypesString:(NSString *)rtypes;

- (int)purposeId;

- (NSArray<PublisherRestrictionTypeValue *> *)restrictionTypes;

- (void)setPurposeId:(int)pId;

- (void)addRestrictionType:(PublisherRestrictionTypeValue *)rType;

- (NSString *)getVendorsAsNSUSerDefaultsString;

- (BOOL)hasVendor:(int)vendorId;

- (NSString *)description;
@end
