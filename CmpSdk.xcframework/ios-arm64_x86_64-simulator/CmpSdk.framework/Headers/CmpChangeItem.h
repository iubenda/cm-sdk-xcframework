//
//  CmpConsentChange.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 17.12.23.
//
#ifndef CmpConsentChange_h
#define CmpConsentChange_h
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CmpChangeItem : NSObject <NSCoding>

@property (nonatomic, strong) id fromOldValue;
@property (nonatomic, strong) id toNewValue;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
+ (instancetype)changeFromOldValue:(nullable id)oldValue toNewValue:(nullable id)newValue;
- (NSDictionary *)dictionaryRepresentation;
- (BOOL)hasChanged;

@end

NS_ASSUME_NONNULL_END
#endif /* CmpConsentChange_h */
