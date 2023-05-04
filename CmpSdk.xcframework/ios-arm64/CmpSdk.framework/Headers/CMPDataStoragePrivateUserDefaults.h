//
//  CMPDataStoragePrivateUserDefaults.h
//  GDPR
//

#import <Foundation/Foundation.h>

@interface CMPDataStoragePrivateUserDefaults : NSObject
+ (NSString *)consentToolUrl;

+ (void)setConsentToolUrl:(NSString *)consentToolUrl;

+ (NSString *)lastRequested;

+ (void)setLastRequested:(NSString *)lastAccepted;

+ (BOOL)needsAcceptance;

+ (void)setNeedsAcceptance:(BOOL)needsAcceptance;

+ (void)clearContents;

+ (NSString *)description;
@end
