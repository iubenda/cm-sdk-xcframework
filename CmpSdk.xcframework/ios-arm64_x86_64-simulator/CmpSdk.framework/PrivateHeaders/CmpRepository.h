//
// Created by Skander Ben Abdelmalak on 22.11.21.
//

#import <Foundation/Foundation.h>
@class CmpConsentDTO;

@interface CmpRepository : NSObject

+ (CmpConsentDTO *)saveOrUpdateUserConsent:(CmpConsentDTO *)newConsentDto existingConsent:(CmpConsentDTO *)existingConsentDto;

+ (void)removeCmpConsent;

+ (void)reset;

+ (void)setConsentString:(NSString *)consentString;

+ (NSString *)getConsentString;

+ (void)debugUserDefaults;
@end
