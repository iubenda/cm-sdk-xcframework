//
//  CmpRepositoryProtocol.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//

#ifndef CmpRepositoryProtocol_h
#define CmpRepositoryProtocol_h
@protocol CmpRepositoryProtocol

+ (void)setConsentString:(NSString *)consentString;
+ (void)removeCmpConsent;
// Add other typical functions here...

@end
#endif /* CmpRepositoryProtocol_h */
