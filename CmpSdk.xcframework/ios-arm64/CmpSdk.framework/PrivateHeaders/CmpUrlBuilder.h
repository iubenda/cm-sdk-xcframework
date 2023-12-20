//
//  CmpUrlBuilder.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 12.12.23.
//
#import <CmpSdk/CmpConfig.h>
#import "CmpSdk/CmpUrlParams.h"
@interface CmpUrlBuilder : NSObject

@property(nonatomic, strong) CmpUrlParams *params;

@property (nonatomic, strong) NSMutableDictionary *useCaseParameters;

- (instancetype) initWithCmpURLParams:(CmpUrlParams*)params;
//- (instancetype) setConsent:(NSString *)consent;
- (NSString *) getConsent;

- (NSURL *)build;

@end
