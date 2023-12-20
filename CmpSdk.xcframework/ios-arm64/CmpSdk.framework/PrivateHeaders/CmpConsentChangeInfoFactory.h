//
//  CmpConsentChangeInfoFactory.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 17.12.23.
//

#ifndef CmpConsentChangeInfoFactory_h
#define CmpConsentChangeInfoFactory_h
#import "CmpConsentChangeInfo.h"
#import "CmpConsentDTO.h"

@interface CmpConsentChangeInfoFactory : NSObject

+ (CmpConsentChangeInfo *)consentChangeInfoFromDictionary:(NSDictionary *)dictionary;
+ (CmpConsentChangeInfo *)createConsentChangeInfoWithOldConsent:(CmpConsentDTO *)oldConsent newConsent:(CmpConsentDTO *)newConsent;
@end

#endif /* CmpConsentChangeInfoFactory_h */
