//
// Created by Skander Ben Abdelmalak on 18.11.21.
//

#import <Foundation/Foundation.h>

@interface CmpPlaceholderParams : NSObject

@property(nonatomic, assign) NSString *vendorId;
@property(nonatomic, assign) NSString *text;
@property(nonatomic, assign) NSString *headline;
@property(nonatomic, assign) NSString *buttonText;
@property(nonatomic, assign) NSString *checkboxText;
@property(nonatomic, assign) NSURL *imageUrl;

- (instancetype)initWithVendorId:(NSString *)vendorId;

+ (instancetype)paramsWithVendorId:(NSString *)vendorId;

- (NSURL *)getRequestURL:(NSString *)consent;

- (void)setCustomPlaceholderText:(NSString *)headline:(NSString *)text
                                :(NSString *)buttonText
                                :(NSString *)checkboxText;
//(NSString *)addText (NSString)addHeadline;
//(NSString *) (NSString *)headline (NSString *)text;
@end
