//
// Created by Skander Ben Abdelmalak on 03.01.22.
//

#import <Foundation/Foundation.h>

@interface Logger : NSObject
+ (void)debug:(NSString *)tag:(NSString *)message;
+ (void)info:(NSString *)tag:(NSString *)message;
+ (void)warning:(NSString *)tag:(NSString *)message;
+ (void)error:(NSString *)tag:(NSString *)message;
@end
