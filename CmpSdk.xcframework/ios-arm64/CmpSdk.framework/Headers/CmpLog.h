//
//  CmpLog.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 31.10.23.
//
#import <CmpSdk/CmpLogLevel.h>
@interface CmpLog : NSObject

+ (void)errorWithTag:(NSString *)tag message:(NSString *)message;
+ (void)warningWithTag:(NSString *)tag message:(NSString *)message;
+ (void)infoWithTag:(NSString *)tag message:(NSString *)message;
+ (void)debugWithTag:(NSString *)tag message:(NSString *)message;
+ (void)verboseWithTag:(NSString *)tag message:(NSString *)message;

+ (void)logWithLevel:(CmpLogLevel)level tag:(NSString *)tag message:(NSString *)message file:(NSString *)file line:(NSNumber*)line;
@end
