//
//  CMPConsentTool.h
//  GDPR
//

#import <Foundation/Foundation.h>
#import "CmpConfig.h"
#import "CMPServerResponse.h"
#import "CMPSettings.h"
#import "CmpPlaceholderView.h"
#import "CmpPlaceholderParams.h"
#import "CmpErrorTypes.h"
#import "CmpButtonEvents.h"
#import "CmpConsentService.h"
#import <WebKit/WebKit.h>
#import <UIKit/UIKit.h>

#define UIKitLocalizedString(key) [[NSBundle bundleWithIdentifier:@"com.apple.UIKit"] localizedStringForKey:key value:@"" table:nil]

@class CmpLayerViewController;
/**
 Object that needs to be initalised when starting the App
 */
@interface CMPConsentTool : NSObject

/**
 The singleton CMPConsentToolInstance
 */
extern CMPConsentTool *consentTool;

/**
 Returns the Config set to the CMPConsentTool while initialisation
 */
@property(nonatomic, retain) CmpConfig *cmpConfig;

/**
 The View Controller, the Web View should have shown onto.
 */
@property(nonatomic, weak) UIViewController *viewController;


@property (nonatomic, strong) CmpConsentService *consentServiceInstance;

/**
 This listener will be called, if the View of the consentTool will be closed
 */
@property(nonatomic, copy) void (^closeListener)(void);

/**
 This listener will be called, if the View of the consentTool will be opened
 */
@property(nonatomic, copy) void (^openListener)(void);

/**
 If this listener is set, this listener will be called, apart from openening an own View
 */
@property(nonatomic, copy) void (^customOpenListener)(CMPSettings *settings);

/**
 This listener will be called, if an error occurs while calling the Server or showing the view.
 */
@property(nonatomic, copy) void (^errorListener)(CmpErrorType errorType, NSString *errorMessage);

/**
 Listener for Event when CMP doesn't need to be opened
 */
@property(nonatomic, copy) void (^onCMPNotOpenedListener)(void);

@property(nonatomic, copy) void (^onCmpButtonClickedCallback)(CmpButtonEvent event);

#pragma mark - old API

/**
 Verify boolean
 */

/// <#Description#>
/// @param domain <#domain description#>
/// @param userId <#userId description#>
/// @param appName <#appName description#>
/// @param language <#language description#>
/// @param idfa <#idfa description#>
/// @param viewController <#viewController description#>
/// @param openListener <#openListener description#>
/// @param closeListener <#closeListener description#>
- (id)                             init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController addOpenListener:(void (^)(
    void))openListener addCloseListener:(void (^)(void))closeListener;

//----------------------- PART Initialize Config without autoupdate (8) -------------------------------------

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 */
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param openListener <#openListener description#>
 */
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
    void))openListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param closeListener <#closeListener description#>
 */
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addCloseListener:(void (^)(
    void))closeListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param onCMPNotOpenedListener onCMPOpenedListener  event
 */
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOnCMPNotOpenedListener:(void (^)(
    void))onCMPNotOpenedListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param openListener <#openListener description#>
 @param closeListener <#closeListener description#>
 */
- (id)                             init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
    void))openListener addCloseListener:(void (^)(void))closeListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param onCMPNotOpenedListener onCMPOpenedListener  event
 @param openListener <#openListener description#>
 */
- (id)                                      init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
    void))openListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param closeListener <#closeListener description#>
 @param onCMPNotOpenedListener <#onCMPOpenedListener description#>

 */
- (id)                                       init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addCloseListener:(void (^)(
    void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

//----------------------- PART Initialize Config without autoupdate (8) -------------------------------------

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 */
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param openListener <#openListener description#>
 */
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addOpenListener:(void (^)(void))openListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param closeListener <#closeListener description#>
 */
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addCloseListener:(void (^)(void))closeListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param openListener <#openListener description#>
 @param closeListener <#closeListener description#>
 */
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addOpenListener:(void (^)(void))openListener addCloseListener:(void (^)(
    void))closeListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param openListener <#openListener description#>
 @param closeListener <#closeListener description#>
 @param onCMPNotOpenedListener <#onCMPOpenedListener description#>
 */
- (id)                             init:(CmpConfig *)config withViewController:(UIViewController *)viewController addOpenListener:(void (^)(
    void))openListener addCloseListener:(void (^)(void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param openListener <#openListener description#>
 @param onCMPNotOpenedListener <#onCMPOpenedListener description#>
 */
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addOpenListener:(void (^)(void))openListener addOnCMPNotOpenedListener:(void (^)(
    void))onCMPNotOpenedListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param openListener <#openListener description#>
 @param closeListener <#closeListener description#>
 @param onCMPNotOpenedListener <#onCMPOpenedListener description#>
 */
- (id)                             init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
    void))openListener addCloseListener:(void (^)(void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param config <#config description#>
 @param viewController <#viewController description#>
 @param closeListener <#closeListener description#>
 @param onCMPNotOpenedListener <#onCMPOpenedListener description#>
 */
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addCloseListener:(void (^)(void))closeListener addOnCMPNotOpenedListener:(void (^)(
    void))onCMPNotOpenedListener;

- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addOpenListener:(void (^)(
                                                                                                               void))openListener addCloseListener:(void (^)(void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener addBackendVerification:(Boolean)backendVerification;
//----------------------- PART Initialize without autoupdate (8) -------------------------------------

/**
 Creates a new instance of this CMPConsentTool.
 @param domain <#domain description#>
 @param userId <#userId description#>
 @param appName <#appName description#>
 @param language <#language description#>
 @param viewController <#viewController description#>
 */
- (id)init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController;

/**
 Creates a new instance of this CMPConsentTool.
 @param domain <#domain description#>
 @param userId <#userId description#>
 @param appName <#appName description#>
 @param language <#language description#>
 @param viewController <#viewController description#>
 @param openListener <#openListener description#>
 */
- (id)init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addOpenListener:(void (^)(
    void))openListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param domain <#domain description#>
 @param userId <#userId description#>
 @param appName <#appName description#>
 @param language <#language description#>
 @param viewController <#viewController description#>
 @param closeListener <#closeListener description#>
 */
- (id)init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addCloseListener:(void (^)(
    void))closeListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param domain <#domain description#>
 @param userId <#userId description#>
 @param appName <#appName description#>
 @param language <#language description#>
 @param viewController <#viewController description#>
 @param openListener <#openListener description#>
 @param closeListener <#closeListener description#>
 */
- (id)                             init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addOpenListener:(void (^)(
    void))openListener addCloseListener:(void (^)(void))closeListener;

- (id)init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addOnCMPNotOpenedListener:(void (^)(
    void))onCMPNotOpenedListener;

- (id)                                      init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addOpenListener:(void (^)(
    void))openListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

- (id)                             init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addOpenListener:(void (^)(
    void))openListener addCloseListener:(void (^)(void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;


//----------------------- PART Initialize with autoupdate (8) -------------------------------------

/**
 Creates a new instance of this CMPConsentTool.
 @param domain <#domain description#>
 @param userId <#userId description#>
 @param appName <#appName description#>
 @param language <#language description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 */
- (id)init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate;

/**
 Creates a new instance of this CMPConsentTool.
 @param domain <#domain description#>
 @param userId <#userId description#>
 @param appName <#appName description#>
 @param language <#language description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param openListener <#openListener description#>
 */
- (id)init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
    void))openListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param domain <#domain description#>
 @param userId <#userId description#>
 @param appName <#appName description#>
 @param language <#language description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param closeListener <#closeListener description#>
 */
- (id)init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addCloseListener:(void (^)(
    void))closeListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param domain <#domain description#>
 @param userId <#userId description#>
 @param appName <#appName description#>
 @param language <#language description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param openListener <#openListener description#>
 @param closeListener <#closeListener description#>
 */
- (id)                             init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
    void))openListener addCloseListener:(void (^)(void))closeListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param domain <#domain description#>
 @param userId <#userId description#>
 @param appName <#appName description#>
 @param language <#language description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param onCMPNotOpenedListener <#onCMPNotOpenedListener description#>
 */
- (id)init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOnCMPNotOpenedListener:(void (^)(
    void))onCMPNotOpenedListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param domain <#domain description#>
 @param userId <#userId description#>
 @param appName <#appName description#>
 @param language <#language description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param onCMPNotOpenedListener <#onCMPNotOpenedListener description#>
 @param openListener <#openListener description#>
 */
- (id)                                      init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
    void))openListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param domain <#domain description#>
 @param userId <#userId description#>
 @param appName <#appName description#>
 @param language <#language description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param onCMPNotOpenedListener <#onCMPNotOpenedListener description#>
 @param closeListener <#closeListener description#>
 */
- (id)                                       init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addCloseListener:(void (^)(
    void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/**
 Creates a new instance of this CMPConsentTool.
 @param domain <#domain description#>
 @param userId <#userId description#>
 @param appName <#appName description#>
 @param language <#language description#>
 @param viewController <#viewController description#>
 @param autoupdate <#autoupdate description#>
 @param onCMPNotOpenedListener <#onCMPNotOpenedListener description#>
 @param closeListener <#closeListener description#>
 */
- (id)                             init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
    void))openListener addCloseListener:(void (^)(void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;


//----------------------- PART Initialize with IDFA and autoupdate (8) -------------------------------------

/// <#Description#>
/// @param domain <#domain description#>
/// @param userId <#userId description#>
/// @param appName <#appName description#>
/// @param language <#language description#>
/// @param idfa <#idfa description#>
/// @param viewController <#viewController description#>
/// @param autoupdate <#autoupdate description#>
- (id)init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate;

/// <#Description#>
/// @param domain <#domain description#>
/// @param userId <#userId description#>
/// @param appName <#appName description#>
/// @param language <#language description#>
/// @param idfa <#idfa description#>
/// @param viewController <#viewController description#>
/// @param autoupdate <#autoupdate description#>
/// @param openListener <#openListener description#>
- (id)init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
    void))openListener;

/// <#Description#>
/// @param domain <#domain description#>
/// @param userId <#userId description#>
/// @param appName <#appName description#>
/// @param language <#language description#>
/// @param idfa <#idfa description#>
/// @param viewController <#viewController description#>
/// @param autoupdate <#autoupdate description#>
/// @param closeListener <#closeListener description#>
- (id)init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addCloseListener:(void (^)(
    void))closeListener;

/// <#Description#>
/// @param domain <#domain description#>
/// @param userId <#userId description#>
/// @param appName <#appName description#>
/// @param language <#language description#>
/// @param idfa <#idfa description#>
/// @param viewController <#viewController description#>
/// @param autoupdate <#autoupdate description#>
/// @param onCMPNotOpenedListener onCMPOpenedListener description
- (id)init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOnCMPNotOpenedListener:(void (^)(
    void))onCMPNotOpenedListener;

/// <#Description#>
/// @param domain <#domain description#>
/// @param userId <#userId description#>
/// @param appName <#appName description#>
/// @param language <#language description#>
/// @param idfa <#idfa description#>
/// @param viewController <#viewController description#>
/// @param autoupdate <#autoupdate description#>
/// @param closeListener <#closeListener description#>
/// @param onCMPNotOpenedListener <#onCMPOpenedListener description#>
- (id)                                       init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addCloseListener:(void (^)(
    void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// <#Description#>
/// @param domain <#domain description#>
/// @param userId <#userId description#>
/// @param appName <#appName description#>
/// @param language <#language description#>
/// @param idfa <#idfa description#>
/// @param viewController <#viewController description#>
/// @param autoupdate <#autoupdate description#>
/// @param openListener <#openListener description#>
/// @param closeListener <#closeListener description#>
- (id)                             init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
    void))openListener addCloseListener:(void (^)(void))closeListener;

/// <#Description#>
/// @param domain <#domain description#>
/// @param userId <#userId description#>
/// @param appName <#appName description#>
/// @param language <#language description#>
/// @param idfa <#idfa description#>
/// @param viewController <#viewController description#>
/// @param autoupdate <#autoupdate description#>
/// @param openListener <#openListener description#>
/// @param closeListener <#closeListener description#>
/// @param onCMPNotOpenedListener <#onCMPOpenedListener description#>
- (id)                             init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
    void))openListener addCloseListener:(void (^)(void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// <#Description#>
/// @param domain <#domain description#>
/// @param userId <#userId description#>
/// @param appName <#appName description#>
/// @param language <#language description#>
/// @param idfa <#idfa description#>
/// @param viewController <#viewController description#>
/// @param autoupdate <#autoupdate description#>
/// @param openListener <#openListener description#>
/// @param onCMPNotOpenedListener <#onCMPOpenedListener description#>
- (id)                                      init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
    void))openListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

//----------------------- PART Initialize with IDFA and without autoupdate (8) -------------------------------------

/// <#Description#>
/// @param domain <#domain description#>
/// @param userId <#userId description#>
/// @param appName <#appName description#>
/// @param language <#language description#>
/// @param idfa <#idfa description#>
/// @param viewController <#viewController description#>
/// @param closeListener <#closeListener description#>
/// @param onCMPNotOpenedListener <#onCMPOpenedListener description#>
- (id)                                       init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController addCloseListener:(void (^)(
    void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// <#Description#>
/// @param domain <#domain description#>
/// @param userId <#userId description#>
/// @param appName <#appName description#>
/// @param language <#language description#>
/// @param viewController <#viewController description#>
/// @param closeListener <#closeListener description#>
/// @param onCMPNotOpenedListener <#onCMPOpenedListener description#>
- (id)                                       init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addCloseListener:(void (^)(
    void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

- (id)                             init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
                                                                                                                                                                        void))openListener addCloseListener:(void (^)(void))closeListener addErrorListener:(void (^)(CmpErrorType, NSString *))errorListener;

- (id)                                       init:(NSString *)domain addId:(NSString *)userId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addCloseListener:(void (^)(
    void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener addBackendeVerification:(Boolean)backendVerification;

- (id)                             init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
                                                                                                                                                                        void))openListener addCloseListener:(void (^)(void))closeListener addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener addErrorListener:(void (^)(CmpErrorType, NSString *))errorListener;

- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addErrorListener:(void (^)(CmpErrorType, NSString *))errorListener;



#pragma mark - init
- (instancetype)initWithDomain:(NSString *)domain
                        codeId:(NSString *)codeId
                       appName:(NSString *)appName
                      language:(NSString *)language
                viewController:(UIViewController *)viewController;

- (instancetype)initWithCmpConfig:(CmpConfig *)cmpConfig
                   viewController:(UIViewController *)viewController;

- (instancetype)withCloseListener:(void (^)(void))closeListener;

- (instancetype)withOpenListener:(void (^)(void))openListener;

- (instancetype)withErrorListener:(void (^)(CmpErrorType, NSString *))errorListener;

- (instancetype)withCustomOpenListener:(void (^)(CMPSettings *))listener;

- (instancetype)withOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

- (instancetype)withOnCmpButtonClickedCallback:(void (^)(CmpButtonEvent))onCmpButtonClickedCallback;

- (instancetype)initialize;


#pragma mark - Placeholder functions

- (CmpPlaceholderView *)createPlaceholder :(CGRect)frame :(CmpPlaceholderParams*) placeholderParams;

#pragma mark - API functions
/**
 Displays a modal view with the consent web view. If the Compliance is accepted or rejected,
 a close function will be called. You can overrride this close function with your own. Therefor
 implement the closeListener and add this as a parameter.
 */
- (void)openCmpConsentToolView;

/**
 *
 *  @brief Displays a modal view with the consent web view. If the Compliance is accepted or rejected,
 *  a close function will be called. You can override this close function with your own. Therefore
 *  implement the closeListener and give it to this function. This Method will not send a request
 *  to the ConsentTool Server again. It will use the last state. If you only want to open the consent
 *  Tool View again, if the server gives a response status ==1 use the checkAndProceedConsentUpdate
 *  method.
 * ! deprecated use open method without close Listener. The callback should already be passed by initialisation
 */
- (void)openCmpConsentToolView:(void (^)(void))closeListener;

- (void)didReceivedConsentString:(CmpLayerViewController *)CmpLayerViewController consentString:(NSString *)consentString;
/**
 * Returns the Vendors String, that was set by consentmanager
 */
- (NSString *)getVendorsString;

/**
 Returns the Purposes String, that was set by consentmanager
 */
- (NSString *)getPurposesString;

/**
 Returns the US Privacy String, that was set by consentmanager
 */
- (NSString *)getUSPrivacyString;

/**
 Returns if a given Vendor has the rights to set cookies
 */
- (BOOL)hasVendorConsent:(NSString *)vendorId vendorIsV1orV2:(BOOL)isIABVendor;

/**
 Returns if under a given Purpose the rights to set cookies are given
 */
- (BOOL)hasPurposeConsent:(NSString *)purposeId purposeIsV1orV2:(BOOL)isIABPurpose;


- (BOOL)hasConsent;
/**
 Returns, if the Consent for a purpose for a specific vendor was given. This Method will
 only give a valid answer, if the Consent was given in the version V2.
 */
- (BOOL)hasPurposeConsent:(int)purposeId forVendor:(int)vendorId;

- (void)registerUserDefaults;

/**
 * Verify Consent and gives a valid consent String
 */
- (void)checkAndOpenConsentLayer;

/**
 * Imports the given Cmp String in base64 encoded
 */
- (BOOL)importCmpString:(NSString *)cmpData;

/**
 Returns the stored ConsentManager CMP String in base64
 */
+ (NSString *)exportCmpString;

/**
 * returns, wether the CMPConsent Manager Server was requested today, or the consentmanager server was already
 * asked, wether the server shuld be requested again.
 */
- (BOOL)calledThisDay;

/**
 * returns, weather the user needs to give a consent, cause he didn't do so in the past,
 * or because the consent Server returned, that a new consent is required.
 */
- (BOOL)needsAcceptance;

/**
 * resets all data set by the consentCMPTool
 */
+ (void)reset;

- (id)errorListener:(void (^)(CmpErrorType, NSString *))errorListener;

- (void)rejectAll:(void (^)(void))onFinish;

- (void)check:(void (^)(void))onCmpLayerOpen;

- (void)acceptAll:(void (^)(void))onFinish;

- (void)enableVendorList:(NSArray *)vendors;

- (void)disableVendorList:(NSArray *)vendors;

- (void)enablePurposeList:(NSArray *)purposes;

- (void)disablePurposeList:(NSArray *)purposes;

- (NSArray *)getEnabledPurposeList;

- (NSString *)getEnabledPurposes;

- (NSArray *)getEnabledVendorList;

- (NSString *)getEnabledVendors;

- (NSArray *)getDisabledVendorList;
- (NSString *)getDisabledVendors;

- (NSArray *)getDisabledPurposeList;
- (NSString *)getDisabledPurposes;

- (NSArray *)getAllPurposesList;

- (NSString *)getAllPurposes;

- (NSArray *)getAllVendorList;

- (NSString *)getAllVendors;

- (NSString *)getGoogleACString;


@end
