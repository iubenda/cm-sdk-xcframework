//
//  CmpConsentDescriptionRepository.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 17.12.23.
//

#ifndef CmpConsentDescriptionRepository_h
#define CmpConsentDescriptionRepository_h
#import "CmpConstants.h"
@interface CmpFrameworkDescriptionRepository : NSObject

+ (BOOL)saveCmpFrameworkMetaKeys:(NSArray *)descriptionFieldsArray;
+ (void)cleanDescriptionFields;

@end

#endif /* CmpConsentDescriptionRepository_h */
