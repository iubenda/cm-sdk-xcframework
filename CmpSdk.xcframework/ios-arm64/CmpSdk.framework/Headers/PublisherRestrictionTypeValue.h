//
//  PublisherRestrictionTypeValue.h
//  GDPR
//

#import <Foundation/Foundation.h>

/**
 Object that provides the interface for storing and retrieving GDPR-related information
 */
@interface PublisherRestrictionTypeValue : NSObject

/**
 The restrictionType of the vendors;
 */
@property(nonatomic, assign) int restrictionType;

/**
 The Vendors which needs a consent for this restriction
 */
@property(nonatomic, copy) NSString *vendorIds;

- (id)init:(int)rType vendors:(NSString *)vIds;

- (NSString *)vendorIds;

- (int)restrictionType;

- (void)setVendorIds:(NSString *)vId;

- (void)setRestrictionType:(int)rType;

- (BOOL)hasVendorId:(int)vId;
- (NSString *)description;
@end
