//
//  CmpUseCase.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 15.12.23.
//
//
//  CmpUseCase.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 15.12.23.
//

#ifndef CmpUseCase_h
#define CmpUseCase_h
typedef NS_ENUM(NSUInteger, CmpUseCase) {
    VerifyConsentOnInitialize,
    CheckConsent,
    OpenConsent,
    PerformDryCheckConsent,
    PerformDryCheckWithCache,
    ImportConsent,
    EnableConsentPurposes,
    DisableConsentPurposes,
    EnableConsentVendors,
    DisableConsentVendors,
    AcceptAllConsent,
    RejectAllConsent,
    ResetConsentSettings
};
#endif /* CmpUseCase_h */
NSString *NSStringFromCmpUseCase(CmpUseCase useCase);

