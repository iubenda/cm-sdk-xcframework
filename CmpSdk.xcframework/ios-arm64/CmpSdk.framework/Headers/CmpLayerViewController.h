//
//  CmpLayerViewController.h
//  GDPR
//

#import <UIKit/UIKit.h>
#import "CmpConsentService.h"


@class CmpLayerViewController;

@protocol WKScriptMessageHandler;
@class CmpConsentDto;
@protocol CmpLayerViewControllerDelegate<NSObject>
- (void)didReceivedConsentString:(CmpLayerViewController *)cmpLayerViewController consentString:(NSString *)consentString;
- (void)didReceivedConsentDto:(CmpLayerViewController *)cmpLayerViewController :(CmpConsentDto *)cmpUserConsentDto;
- (void)didFinishedLoading:(CmpLayerViewController *)cmpLayerViewController;
- (void)cancelConsentLayer:(CmpLayerViewController *)cmpLayerViewController;
@end

@interface CmpLayerViewController : UIViewController

@property(nonatomic, assign) BOOL isOpen;
@property(nonatomic, assign) BOOL isMessageSent;
@property(nonatomic, assign) BOOL justOpenView;
@property(nonatomic, assign) BOOL timedOut;
@property(nonatomic, assign) BOOL rejectAll;
/**
 Optional delegate to receive callbacks from the CMP web tool
 */
@property(nonatomic, weak) id<CmpLayerViewControllerDelegate> delegate;
/**
 This listener will be called, if an error occurs while calling the Server or showing the view.
 */
@property(nonatomic, copy) void (^errorListener)(NSString *error);

- (void)initWebView;
- (void)reset;
@end
