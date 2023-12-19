//
//  CmpUrlParams.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 12.12.23.
//
#import <CmpSdk/CmpConfig.h>
#import "CmpUseCase.h"
@interface CmpUrlParams : NSObject

@property (nonatomic, assign) CmpUseCase useCase;
@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) NSString *domain;
@property (nonatomic, strong) NSString *idfa;
@property (nonatomic, assign) NSInteger attStatus;
@property (nonatomic, strong) NSString *language;
@property (nonatomic, strong) NSString *appName;
@property (nonatomic, strong) NSString *designId;
@property (nonatomic, assign) BOOL jumpToSettingsPage;
@property (nonatomic, assign) BOOL isDebugMode;
@property (nonatomic, strong) NSString *consent;
@property (nonatomic, strong) NSArray<NSString *> *addPurposes;
@property (nonatomic, strong) NSArray<NSString *> *addVendors;
@property (nonatomic, assign) BOOL updateVendors;
@property (nonatomic, assign) BOOL forceOpen;
@property (nonatomic, assign) BOOL rejectAll;
@property (nonatomic, assign) BOOL acceptAll;
@property (nonatomic, assign) BOOL skipCookies;
@property (nonatomic, strong) NSString *bundleID;
// Initializers
+ (instancetype)paramsWithUseCase:(CmpUseCase)useCase
                         consent:(NSString *)consent
                        purposes:(NSArray<NSString *> *)purposes
                         vendors:(NSArray<NSString *> *)vendors
                       forceOpen:(BOOL)forceOpen
                     skipCookies:(BOOL)skipCookies
                   updateVendors:(BOOL)updateVendors
                      rejectAll:(BOOL)rejectAll
acceptAll:(BOOL)acceptAll;
+ (instancetype)paramsWithUseCase:(CmpUseCase)useCase consent:(NSString *)consent;
+ (instancetype)paramsWithUseCase:(CmpUseCase)useCase consent:(NSString *)consent vendors:(NSArray<NSString *> *)vendors;
+ (instancetype)paramsWithUseCase:(CmpUseCase)useCase consent:(NSString *)consent purposes:(NSArray<NSString *> *)purposes updateVendors:(BOOL)updateVendors;
+ (instancetype)paramsWithUseCase:(CmpUseCase)useCase consent:(NSString *)consent rejectAll:(BOOL)rejectAll;
+ (instancetype)paramsWithUseCase:(CmpUseCase)useCase consent:(NSString *)consent acceptAll:(BOOL)acceptAll;
+ (instancetype)paramsWithUseCase:(CmpUseCase)useCase consent:(NSString *)consent forceOpen:(BOOL)forceOpen;

@end
