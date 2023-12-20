//
//  CmpEventRepository.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 17.12.23.
//

#ifndef CmpEventRepository_h
#define CmpEventRepository_h
#import <Foundation/Foundation.h>
#import "CmpConstants.h"
@class CmpConsentDTO;

@interface CmpEventRepository : NSObject

+ (BOOL)saveCmpEventMetadata:(CmpEventMetadata *)metadata;

+ (NSArray<CmpEventMetadata *> *)getAllCmpEventMetadata;

+ (CmpEventMetadata *)getCmpEventMetadataForKey:(NSUInteger)metadataID;

+ (CmpEventMetadata *)getLastCmpEventMetadata;

+ (void)clearAllMetadata;

@end

#endif /* CmpEventRepository_h */
