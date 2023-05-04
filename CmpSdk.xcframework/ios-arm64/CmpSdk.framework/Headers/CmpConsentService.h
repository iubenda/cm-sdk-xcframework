//
// Created by Skander Ben Abdelmalak on 20.11.21.
//

#import <Foundation/Foundation.h>
#import "CmpRepository.h"
#import "CmpErrorTypes.h"
#import "CmpButtonEvents.h"

@class CmpConsentDto;

@interface CmpConsentService : NSObject

@property (nonatomic, copy) void(^onCloseListener)(void);
@property (nonatomic, copy) void(^onOpenListener)(void);
@property (nonatomic, copy) void(^onErrorListener)(CmpErrorType errorType, NSString *errorMessage);
@property (nonatomic, copy) void(^onCmpNotOpenedListener)(void);
@property (nonatomic, copy) void(^onButtonClickedCallback)(CmpButtonEvent event);

- (bool)saveConsentDto:(CmpConsentDto *)consentDto;

- (CmpConsentDto *)getConsentDto;

- (NSString *)getCmpStringBase64Encoded;

- (void)reset;

+ (instancetype)sharedInstance;

+ (void)userImportedConsent:(NSString *)data;

+ (void)consentLayerOpened;

+ (BOOL)validConsent;

+ (BOOL)hasConsent;
@end
