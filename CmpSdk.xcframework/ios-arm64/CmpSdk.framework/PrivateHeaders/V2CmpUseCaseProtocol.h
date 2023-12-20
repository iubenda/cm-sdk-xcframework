//
//  V2CmpUseCaseProtocol.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//

#import <CmpSdk/CmpErrorTypes.h>
#import <Foundation/Foundation.h>
#import "CmpEventsProtocol.h"
#import "CmpUseCase.h"
#ifndef V2CmpUseCaseProtocol_h
#define V2CmpUseCaseProtocol_h

@class CmpLayerViewController;
@class CmpWebViewManager;
@protocol CmpEventsProtocol;

@protocol V2CmpUseCaseProtocol <NSObject>

- (instancetype)initWithUseCase:(CmpUseCase)useCase eventHandler:(id<CmpEventsProtocol>)eventHandler;

// WebView Callback registers
- (void)handleWebViewDidFinishLoad;
- (void)handleWebViewConsentReceived:(NSDictionary *)json;
- (void)handleWebViewError:(CmpErrorType)errorType message:(NSString *)message;
- (void)handleWebViewOpen;

@optional
- (void)setupWebViewManagerInView:(UIView *)view;
@optional
- (void)closeCmpViewController;

@end

#endif /* V2CmpUseCaseProtocol_h */
