//
//  CmpLayerViewController.h
//  GDPR
//

#import "CmpConsentService.h"
#import "CmpErrorTypes.h"
#import <UIKit/UIKit.h>

@class CmpLayerViewController;

@protocol WKScriptMessageHandler;
@class CmpConsentDto;
@protocol CmpLayerViewControllerDelegate <NSObject>
- (void)didReceivedConsentString:(CmpLayerViewController *)cmpLayerViewController consentString:(NSString *)consentString;
- (void)didReceivedConsentDto:(CmpLayerViewController *)cmpLayerViewController:(CmpConsentDto *)cmpUserConsentDto;
- (void)didFinishedLoading:(CmpLayerViewController *)cmpLayerViewController;
- (void)cancelConsentLayer:(CmpLayerViewController *)cmpLayerViewController;
@end

@interface CmpLayerViewController : UIViewController

@property(nonatomic, assign) BOOL isOpen;
@property(nonatomic, assign) BOOL isMessageSent;
@property(nonatomic, assign) BOOL justOpenView;
@property(nonatomic, assign) BOOL timedOut;
@property(nonatomic, assign) BOOL rejectAll;
@property(nonatomic, assign) BOOL acceptAll;
@property(nonatomic, assign) NSString *additionalUrlParameters;

/**
 Optional delegate to receive callbacks from the CMP web tool
 */
@property(nonatomic, weak) id<CmpLayerViewControllerDelegate> delegate;
/**
 This listener will be called, if an error occurs while calling the Server or showing the view.
 */
@property(nonatomic, copy) void (^errorListener)(CmpErrorType errorType, NSString *errorMessage);

@property(nonatomic, copy) void (^onFinish)(void);

@property(nonatomic, copy) void (^onCmpLayerOpen)(void);

@property(nonatomic, copy) void (^onCheckApiResponse)(void);

- (void)initWebView;
- (void)reset;
@end
