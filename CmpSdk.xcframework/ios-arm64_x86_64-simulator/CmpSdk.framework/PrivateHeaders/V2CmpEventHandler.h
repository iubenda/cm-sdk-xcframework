//
//  V2CmpEventHandler.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//
#ifndef V2CmpEventHandler_h
#define V2CmpEventHandler_h
#import <CmpSdk/CmpEventListenerTypes.h>
#import <CmpSdk/CmpCallbackTypes.h>
#import <CmpSdk/CmpButtonEvent.h>
#import <CmpSdk/CmpLog.h>
#import "CmpEventsProtocol.h"
static NSString * const kCmpEventHandler = @"EventHandler";

@interface V2CmpEventHandler : NSObject <CmpEventsProtocol>

// Event listeners
@property (nonatomic, copy) CmpOpenListener openListener;
@property (nonatomic, copy) CmpCloseListener closeListener;
@property (nonatomic, copy) CmpNotOpenedListener notOpenedListener;
@property (nonatomic, copy) CmpErrorListener errorListener;
@property (nonatomic, copy) CmpButtonClickedListener buttonClickedListener;
@property (nonatomic, copy) CmpViewControllerConfigurationBlock viewControllerConfigurationBlock;
@property (nonatomic, copy) CmpUIViewConfigurationBlock uiViewConfigurationBlock;
// Registration methods for listeners
- (void)registerOpenListener:(void (^)(void))listener;
- (void)registerCloseListener:(void (^)(void))listener;
- (void)registerNotOpenedListener:(void (^)(void))listener;
- (void)registerErrorListener:(void (^)(CmpErrorType errorType, NSString *message))listener;
- (void)registerButtonClickedListener:(void (^)(CmpButtonEvent event))listener;
- (void)registerViewControllerConfigurationBlock:(CmpViewControllerConfigurationBlock)configurationBlock;
- (void)registerUIViewConfigurationBlock:(CmpUIViewConfigurationBlock)configurationBlock;
// Trigger methods
- (void)triggerOpenListener;
- (void)triggerCloseListener;
- (void)triggerNotOpenedListener;
- (void)triggerErrorListenerWithType:(CmpErrorType)errorType message:(NSString *)message;
- (void)triggerButtonClickedListenerWithEvent:(CmpButtonEvent)event;
- (void)triggerConfigureViewControllerBlock:(UIViewController*)viewController;
- (void)triggerConfigureUIViewBlock:(UIView*)view;
@end

#endif /* V2CmpEventHandler_h */
