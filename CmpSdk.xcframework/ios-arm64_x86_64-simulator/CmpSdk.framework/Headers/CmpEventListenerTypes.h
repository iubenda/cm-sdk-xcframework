//
//  CmpEventListenerTypes.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 14.12.23.
//
#ifndef CmpEventListenerTypes_h
#define CmpEventListenerTypes_h
#import <CmpSdk/CmpButtonEvent.h>
#import <AppTrackingTransparency/ATTrackingManager.h>
#import <CmpSdk/CmpErrorTypes.h>
typedef void (^CmpOpenListener)(void);
typedef void (^CmpCloseListener)(void);
typedef void (^CmpNotOpenedListener)(void);
typedef void (^CmpErrorListener)(CmpErrorType errorType, NSString *message);
typedef void (^CmpButtonClickedListener)(CmpButtonEvent type);
API_AVAILABLE(ios(14))
typedef void (^CmpATTrackingStatusChangedListener)(ATTrackingManagerAuthorizationStatus oldStatus, ATTrackingManagerAuthorizationStatus newStatus, NSDate *lastUpdated);
#endif /* CmpEventListenerTypes_h */
