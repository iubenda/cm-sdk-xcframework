//
//  CmpBaseStrategy.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 14.12.23.
//

#ifndef CmpBaseStrategy_h
#define CmpBaseStrategy_h

#import "CmpSdk/V2CmpUseCaseProtocol.h"
#import "CmpSdk/V2WebViewManager.h"
#import "CmpSdk/V2CmpViewController.h"
#import "CmpUtils.h"
#import "CmpSdk/CmpEventsProtocol.h"
#import "CmpUseCase.h"
#import "Cmpsdk/CmpURLBuilder.h"
#import "CmpSdk/CmpConsentChangeResult.h"

@interface CmpBaseStrategy : NSObject <V2CmpUseCaseProtocol>
@property (nonatomic, strong) id<CmpEventsProtocol> eventHandler;
@property (nonatomic, assign) CmpUseCase useCase;
@property (nonatomic, strong) CmpUrlBuilder *consentURLBuilder;
@property (nonatomic, strong) V2WebViewManager *webViewManager;
@property (nonatomic, strong) V2CmpViewController *cmpViewController;

- (instancetype)initWithUseCase:(CmpUseCase)useCase eventHandler:(id<CmpEventsProtocol>)eventHandler;
- (void)presentCmpViewController;
- (void)closeCmpViewController;
- (void)loadWebView;
- (void)publishConsentChange:(CmpConsentChangeResult *)changeResult;

@end
#endif /* CmpBaseStrategy_h */
