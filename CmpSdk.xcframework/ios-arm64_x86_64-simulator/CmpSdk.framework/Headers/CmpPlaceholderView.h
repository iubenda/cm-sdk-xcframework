//
//  CmpPlaceholderView.h
//  consentmanager
//
//  Created by Skander Ben Abdelmalak on 17.11.21.
//
#import "CmpPlaceholderParams.h"
#import <WebKit/WebKit.h>
@class CmpPlaceholderView;

#ifndef CmpPlaceholderView_h
#define CmpPlaceholderView_h

@protocol CmpPlaceholderDelegate <NSObject>
- (void)receivedConsentString:(CmpPlaceholderView *)placeholderView:(NSString *)consentString;
@end

@protocol CmpPlaceholderAcceptedDelegate <NSObject>
- (void)vendorAccepted:(CmpPlaceholderView *)placeholderView;
@end

@interface CmpPlaceholderView : UIView <WKNavigationDelegate>

@property(strong, nonatomic) WKWebView *webView;

@property(nonatomic, assign) CmpPlaceholderParams *placeholderParams;

/**
 delegate to receive callbacks from the CMP web tool
 */
@property(nonatomic, weak) id<CmpPlaceholderDelegate> delegate;

@property(nonatomic, weak) id<CmpPlaceholderAcceptedDelegate> vendorDelegate;

- (instancetype)initWithPlaceholderParams:(CmpPlaceholderParams *)placeholderParams;

+ (instancetype)viewWithPlaceholderParams:(CmpPlaceholderParams *)placeholderParams;

- (CmpPlaceholderView *)createPreview:(CGRect)frame;
@end

#endif /* CmpPlaceholderView_h */
