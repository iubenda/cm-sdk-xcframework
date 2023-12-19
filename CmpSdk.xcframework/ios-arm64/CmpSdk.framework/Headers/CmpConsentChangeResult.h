//
//  CmpConsentChangeResult.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 17.12.23.
//
#import "CmpConsentDTO.h"
@interface CmpConsentChangeResult : NSObject

@property (nonatomic, strong) CmpConsentDTO *lastConsent;
@property (nonatomic, strong) CmpConsentDTO *currentConsent;

- (instancetype)initWithOldConsent:(CmpConsentDTO *)oldConsent newConsent:(CmpConsentDTO *)newConsent;

@end
