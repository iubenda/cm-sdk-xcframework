//
//  CmpMigrationManager.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//

#ifndef CmpMigrationManager_h
#define CmpMigrationManager_h

@interface CmpMigrationManager : NSObject
extern NSString *const CURRENT_SDK_VERSION;
+ (void)performMigrationIfNeeded;
+ (NSString *)getOldConsentString;
@end

#endif /* CmpMigrationManager_h */
