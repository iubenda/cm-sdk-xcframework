//
//  CmpEventMetadataFactory.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 17.12.23.
//

#ifndef CmpEventMetadataFactory_h
#define CmpEventMetadataFactory_h
#import "CmpEventMetadata.h"
#import "CmpConsentDTO.h"
@interface CmpEventMetadataFactory : NSObject

+ (CmpEventMetadata *)createEventMetadataFromDictionary:(NSDictionary *)dict;
+ (CmpEventMetadata *)createEventMetadataForNewConsent:(CmpConsentDTO *)newConsentDto existingConsent:(CmpConsentDTO *)existingConsentDto;
+ (NSDictionary *)serializeEventMetadata:(CmpEventMetadata *)metadata;
@end


#endif /* CmpEventMetadataFactory_h */
