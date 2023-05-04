//
// Created by Skander Ben Abdelmalak on 20.11.21.
//

#import <Foundation/Foundation.h>
#import "CmpRepository.h"

@class CmpConsentDto;

@interface CmpConsentService : NSObject

+ (bool)userAcceptedConsent:(CmpConsentDto *)consentDto;

+ (void)userOpenedConsentLayer;

+ (void)cmpManagerOpenedConsentLayer;

+ (void)updateUserConsent:(NSString*)consentString;
+ (void)userImportedConsent:(NSString *)data;

+ (NSString *)getCmpApiKey;

+ (void)resetConsent;

+ (void)consentLayerOpened;
+ (BOOL)validConsent;

+ (BOOL)hasConsent;
@end
