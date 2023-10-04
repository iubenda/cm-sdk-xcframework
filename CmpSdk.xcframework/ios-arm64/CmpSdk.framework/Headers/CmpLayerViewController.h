//
//  CmpLayerViewController.h
//  GDPR
//

#import "CmpConsentService.h"
#import "CmpErrorTypes.h"
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@class CmpLayerViewController;

@protocol WKScriptMessageHandler;
@class CmpConsentDto;
@protocol CmpLayerViewControllerDelegate <NSObject>
- (void)didReceivedConsentDto:(CmpLayerViewController *)cmpLayerViewController
            cmpUserConsentDto:(CmpConsentDto *)cmpUserConsentDto;
- (void)didFinishedLoading:(CmpLayerViewController *)cmpLayerViewController;
- (void)cancelConsentLayer:(CmpLayerViewController *)cmpLayerViewController;
@end

@interface CmpLayerViewController : UIViewController

@property (nonatomic, assign) BOOL isOpen;
@property (nonatomic, assign) BOOL isMessageSent;
@property (nonatomic, assign) BOOL isAPICall;
@property (nonatomic, assign, readwrite) BOOL timedOut;
@property (nonatomic, assign) BOOL error;

@property (nonatomic, strong) WKWebView *webView;

@property (nonatomic, strong) NSURL *consentURL;
@property (nonatomic, assign) NSTimeInterval delaySeconds;
@property (nonatomic, assign) NSInteger maxRetryCount;
@property (nonatomic, strong) NSTimer *retryTimer;
@property (nonatomic, assign) BOOL shouldProcessCallback;

@property (nonatomic, weak) id<CmpLayerViewControllerDelegate> delegate;


// Callbacks
@property (nonatomic, copy) void (^onFinish)(void);
@property (nonatomic, copy) void (^onCheckApiResponseOpen)(void);
@property (nonatomic, copy) void (^onCheckApiResponseNotOpen)(void);
@property (nonatomic, copy) void (^errorListener)(CmpErrorType, NSString *);

- (instancetype)initWithConsentURL:(NSURL *)consentURL
                          delegate:(id<CmpLayerViewControllerDelegate>)delegate
                     errorListener:(void (^)(CmpErrorType, NSString *))errorListener;

- (instancetype)initWithImport:(NSURL *)consentURL delegate:(id<CmpLayerViewControllerDelegate>)delegate errorListener:(void (^)(CmpErrorType, NSString *))errorListener onFinishListener:(void (^)(void))onFinishListener;

- (instancetype)initWithApiCall:(NSURL *)consentURL delegate:(id<CmpLayerViewControllerDelegate>)delegate errorListener:(void (^)(CmpErrorType, NSString *))errorListener onFinishListener:(void (^)(void))onFinishListener;
- (instancetype)initWithCheckApi:(NSURL *)consentURL delegate:(id<CmpLayerViewControllerDelegate>)delegate errorListener:(void (^)(CmpErrorType, NSString *))errorListener onCheckApiResponseOpen: (void (^)(void))onCheckApiResponseOpen onCheckApiResponseNotOpen: (void (^)(void))onCheckApiResponseNotOpen;
- (void)initWebView;
- (void)reset;
@end
