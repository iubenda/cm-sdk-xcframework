//
//  CmpStore.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 17.12.23.
//

#ifndef CmpStore_h
#define CmpStore_h
#import "CmpConstants.h"
#import "CmpConsentDTO.h"
@interface CmpStore : NSObject

+ (NSString *)fetchStringForKey:(NSString *)key;

+ (void)saveString:(NSString *)string forKey:(NSString *)key;

+ (void)removeUserDefaultsKey:(NSString *)key;

+ (void)removeMultipleUserDefaultsKeys:(NSArray<NSString *> *)keys;

+ (void)setBoolValue:(BOOL)value forKey:(NSString *)key;

+ (BOOL)boolValueForKey:(NSString *)key withDefaultValue:(BOOL)defaultValue;

+ (CmpConsentDTO *)fetchCmpUserConsent;

+ (BOOL)saveUserConsent:(CmpConsentDTO *)userConsent;

+ (NSDictionary *)debugUserDefaults;

@end

#endif /* CmpStore_h */
