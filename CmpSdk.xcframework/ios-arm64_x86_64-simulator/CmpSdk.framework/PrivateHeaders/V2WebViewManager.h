//
//  V2WebViewManager.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//

#ifndef V2WebViewManager_h
#define V2WebViewManager_h
#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import <CmpSdk/CmpEventListenerTypes.h>
#import <CmpSdk/CmpErrorTypes.h>
#import <CmpSdk/CmpConfig.h>
#import "CmpSdk/CmpWebViewEventListenerTypes.h"

@interface V2WebViewManager : NSObject <WKNavigationDelegate, WKScriptMessageHandler, WKUIDelegate>

@property (nonatomic, strong) WKWebView *webView;
@property (nonatomic, copy) CmpWebViewOpenHandler openHandler;
@property (nonatomic, copy) CmpWebViewCloseHandler closeHandler;
@property (nonatomic, copy) CmpWebViewErrorHandler errorHandler;
@property (nonatomic, copy) CmpWebViewConsentReceivedHandler consentReceivedhandler;
@property (nonatomic, copy) CmpLinkClickListener linkClickHandler;
@property (nonatomic, copy) CmpWebViewCompletion completion;
@property (nonatomic, assign, getter=isInRetryState) BOOL retryState;

- (instancetype)initWithConsentURL:(NSURL *)consentURL;
- (void)loadWebView;
- (void)removeWebView;

@end

#endif /* V2WebViewManager_h */
