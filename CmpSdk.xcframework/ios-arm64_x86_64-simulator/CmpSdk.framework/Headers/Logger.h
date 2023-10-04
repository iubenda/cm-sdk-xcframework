//
// Created by Skander Ben Abdelmalak on 03.01.22.
//

#import <Foundation/Foundation.h>

@interface Logger : NSObject
+ (void)debugWithTag:(NSString *)tag message:(NSString *)message;
+ (void)infoWithTag:(NSString *)tag message:(NSString *)message;
+ (void)warningWithTag:(NSString *)tag message:(NSString *)message;
+ (void)errorWithTag:(NSString *)tag message:(NSString *)message;
@end

