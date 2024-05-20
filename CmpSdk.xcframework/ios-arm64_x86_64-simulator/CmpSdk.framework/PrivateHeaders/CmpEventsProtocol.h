//
//  CmpEventsProtocol.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//
#ifndef CmpEventsProtocol_h
#define CmpEventsProtocol_h
#import <CmpSdk/CmpButtonEvent.h>
#import "CmpErrorTypes.h"
#import <CmpSdk/CmpConsentTool.h>
@protocol CmpEventsProtocol <NSObject>

@optional
- (void)triggerOpenListener;
- (void)triggerCloseListener;
- (void)triggerNotOpenedListener;
- (void)triggerErrorListenerWithType:(CmpErrorType)errorType message:(NSString *)message;
- (void)triggerButtonClickedListenerWithEvent:(CmpButtonEvent)event;
- (BOOL)triggerLinkClickListenerWithURL:(NSString *)url navigationActionPolicy:(WKNavigationActionPolicy *)policy;
- (void)triggerConfigureViewControllerBlock:(UIViewController*)viewController;
- (void)triggerConfigureUIViewBlock:(UIView*)view;
- (void)triggerUpdateGoogleConsentListener:(NSDictionary<NSString *,NSString *>*)consentMap;
- (CmpLinkClickListener)getLinkClickListener;
@end

#endif /* CmpEventsProtocol_h */
