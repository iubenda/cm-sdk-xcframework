//
// Created by Skander Ben Abdelmalak on 20.11.21.
//
#import <CmpSdk/CmpButtonEvent.h>
#import <CmpSdk/CmpErrorTypes.h>
#import <CmpSdk/CmpRepository.h>
#import <CmpSdk/CmpLog.h>
#import <CmpSdk/CmpATTrackingManager.h>
#import <Foundation/Foundation.h>
#import "CmpSdk/CmpUseCase.h"
#import "CmpSdk/CmpConsentChangeResult.h"
@class CmpConsentDTO;

@interface CmpService : NSObject

+ (CmpConsentChangeResult*)saveConsentDTO:(CmpConsentDTO *)newConsentDto;

+ (CmpConsentChangeResult *)saveConsentFromJSON:(NSDictionary *)json useCase:(CmpUseCase)useCase;
+ (CmpConsentDTO *)getConsentDTO;

+ (NSString *)getCmpStringBase64Encoded;

+ (void)reset;

+ (BOOL)validConsent;

+ (bool)isConsentRequired;

+ (BOOL)hasConsent;

+ (NSDate*)getLastConsentRequest;
// caching logic:

+ (NSNumber *)getCachedConsent;

+ (BOOL)consentRequestedToday;

+ (void)cacheNeedsConsentResult:(NSNumber *)result;

@end
