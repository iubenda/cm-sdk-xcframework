//
//  CmpWebViewEventListenerTypes.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 14.12.23.
//

#ifndef CmpWebViewEventListenerTypes_h
#define CmpWebViewEventListenerTypes_h
typedef void (^CmpWebViewErrorHandler)(CmpErrorType errorType, NSString *message);
typedef void (^CmpWebViewCompletion)(void);
typedef void (^CmpWebViewOpenHandler)(void);
typedef void (^CmpWebViewConsentReceivedHandler)(NSDictionary* json);
typedef void (^CmpWebViewCloseHandler)(void);
#endif /* CmpWebViewEventListenerTypes_h */
