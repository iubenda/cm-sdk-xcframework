//
//  CMPConsentTool.h
//  GDPR
//

#import "CMPServerResponse.h"
#import "CMPSettings.h"
#import "CmpButtonEvents.h"
#import "CmpConfig.h"
#import "CmpConsentService.h"
#import "CmpErrorTypes.h"
#import "CmpPlaceholderParams.h"
#import "CmpPlaceholderView.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

#define UIKitLocalizedString(key) [[NSBundle bundleWithIdentifier:@"com.apple.UIKit"] localizedStringForKey:key value:@"" table:nil]

@class CmpLayerViewController;

/// CMPConsentTool instance to interact with the Consentmanager Platform. You can open the Consent layer and manage the user consent
@interface CMPConsentTool : NSObject

/// The singleton CMPConsentToolInstance
extern CMPConsentTool *consentTool;

/// The Config set to the CMPConsentTool while initialisation
@property(nonatomic, retain) CmpConfig *cmpConfig;

@property(nonatomic, weak) UIViewController *viewController;

@property(nonatomic, strong) CmpConsentService *consentServiceInstance;

/// This listener will be called, if the View of the consentTool will be closed
@property(nonatomic, copy) void (^closeListener)(void);

/// This listener will be called, if the View of the consentTool will be opened
@property(nonatomic, copy) void (^openListener)(void);

/// If this listener is set, this listener will be called, apart from openening an own View
@property(nonatomic, copy) void (^customOpenListener)(CMPSettings *settings) __attribute__((deprecated("Use -openListener, -closeListener instead. This method will be removed in future versions.")));;

/// Listener will be called, if an error occurs while calling the Server or showing the view.
@property(nonatomic, copy) void (^errorListener)(CmpErrorType errorType, NSString *errorMessage);

/// Listener for Event when CMP doesn't need to be opened
@property(nonatomic, copy) void (^onCMPNotOpenedListener)(void);

/// Listener for Event when Button is clicked and Consent layer is closing
@property(nonatomic, copy) void (^onCmpButtonClickedCallback)(CmpButtonEvent event);

#pragma mark - init < 1.6.0

/// Initializes a new instance of the class
///
/// - Parameter domain: String cmp domain
/// - Parameter cmpId: String cmp id
/// - Parameter appName: String App name
/// - Parameter language: String language
/// - Parameter idfa: String IDFA String String IDFA String
/// - Parameter viewController: `UViewController` instance
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)      init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController addOpenListener:(void (^)(
	void))openListener
addCloseListener:(void (^)(void))closeListener;

/// Initializes a new instance of the class
///
/// - Parameter config: ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addCloseListener:(void (^)(
	void))closeListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOnCMPNotOpenedListener:(void (^)(

	void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)      init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener
addCloseListener:(void (^)(void))closeListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addCloseListener:(void (^)(
	void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addOpenListener:(void (^)(void))openListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addCloseListener:(void (^)(void))closeListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addOpenListener:(void (^)(void))openListener addCloseListener:(void (^)(
	void))closeListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(CmpConfig *)config withViewController:(UIViewController *)viewController addOpenListener:(void (^)(
	void))openListener
		 addCloseListener:(void (^)(void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addOpenListener:(void (^)(void))openListener addOnCMPNotOpenedListener:(void (^)(

	void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener
		 addCloseListener:(void (^)(void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addCloseListener:(void (^)(void))closeListener addOnCMPNotOpenedListener:(void (^)(
	void))onCMPNotOpenedListener;

/// Initializes a new instance of the class/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Parameter backendVerification: If enabled the consentmanager server will be requested to check if the consent layer needs to be opened
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(CmpConfig *)config withViewController:(UIViewController *)viewController addOpenListener:(void (^)(
	void))openListener
		 addCloseListener:(void (^)(void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener
   addBackendVerification:(Boolean)backendVerification;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addOpenListener:(void (^)(
	void))openListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addCloseListener:(void (^)(
	void))closeListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)      init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addOpenListener:(void (^)(
	void))openListener
addCloseListener:(void (^)(void))closeListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addOnCMPNotOpenedListener:(void (^)(
	void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addOpenListener:(void (^)(
	void))openListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addOpenListener:(void (^)(
	void))openListener
		 addCloseListener:(void (^)(void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addCloseListener:(void (^)(
	void))closeListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)      init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener
addCloseListener:(void (^)(void))closeListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOnCMPNotOpenedListener:(void (^)(
	void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addCloseListener:(void (^)(
	void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener
		 addCloseListener:(void (^)(void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter idfa: IDFA `String`
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter idfa: IDFA `String`
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter idfa: IDFA `String`
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addCloseListener:(void (^)(
	void))closeListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter idfa: IDFA `String`
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOnCMPNotOpenedListener:(void (^)(
	void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter idfa: IDFA `String`
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addCloseListener:(void (^)(
	void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter idfa: IDFA `String`
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)      init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener
addCloseListener:(void (^)(void))closeListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter idfa: IDFA `String`
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener
		 addCloseListener:(void (^)(void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter idfa: IDFA `String`
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter idfa: IDFA `String`
/// - Parameter viewController: `UViewController` instance
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addIDFA:(NSString *)idfa addViewController:(UIViewController *)viewController addCloseListener:(void (^)(
	void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addCloseListener:(void (^)(
	void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter errorListener: Callback to add action if an error occurred. The block should have the following signature: `void (^)(CmpErrorType, NSString *)`
/// - Returns: ``CMPConsentTool`` instance
- (id)      init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener
addCloseListener:(void (^)(void))closeListener
addErrorListener:(void (^)(CmpErrorType, NSString *))errorListener;

/// Initializes a new instance of the class
///
/// - Parameter domain: `String` cmp domain
/// - Parameter cmpId: `String` cmp id
/// - Parameter appName: `String` App name
/// - Parameter language: `String` language for the consentlayer
/// - Parameter viewController: `UViewController` instance
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Parameter backendVerification: If enabled the consentmanager server will be requested to check if the consent layer needs to be opened
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(NSString *)domain addId:(NSString *)cmpId addAppName:(NSString *)appName addLanguage:(NSString *)language addViewController:(UIViewController *)viewController addCloseListener:(void (^)(
	void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener
  addBackendeVerification:(Boolean)backendVerification;

/// Initializes a new instance of the class
///
/// - Parameter config ``CmpConfig`` instance
/// - Parameter viewController: `UViewController` instance
/// - Parameter autoupdate: Performs an automatic check to determine if the user needs to provide consent.
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`: The block should have the following signature: `void (^)(void)`
/// - Parameter errorListener: Callback to add action if an error occurred. The block should have the following signature: `void (^)(CmpErrorType, NSString *)`
/// - Returns: ``CMPConsentTool`` instance
- (id)               init:(CmpConfig *)config withViewController:(UIViewController *)viewController autoupdate:(BOOL)autoupdate addOpenListener:(void (^)(
	void))openListener
		 addCloseListener:(void (^)(void))closeListener
addOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener
		 addErrorListener:(void (^)(CmpErrorType, NSString *))errorListener;

/// Initializes a new instance of the class
/// - Parameters:
///     - cmpConfig:  ``CmpConfig`` object.
///     - viewController: `UIViewController` instance
///     - errorListener: Callback to add action if an error occurred. The block should have the following signature: `void (^)(CmpErrorType, NSString *)`
/// - Returns: ``CMPConsentTool`` instance
- (id)init:(CmpConfig *)config withViewController:(UIViewController *)viewController addErrorListener:(void (^)(
	CmpErrorType,
	NSString *))errorListener;

#pragma mark - initialize 1.6.0

/// Initializes a new instance of the class with the specified CMP domain, code ID, app name, language, and view controller.
///
/// - Parameters:
///     - domain: Cmp server domain
///     - codeId: Cmp ID
///     - appName: name of the app
///     - language: language for the consentlayer
///     - viewController: `UIViewController` instance
/// - Returns: ``CMPConsentTool`` instance
- (instancetype)initWithDomain:(NSString *)domain
						codeId:(NSString *)codeId
					   appName:(NSString *)appName
					  language:(NSString *)language
				viewController:(UIViewController *)viewController;

///
/// Initializes a new instance of the class with the specified ``CmpConfig`` and view controller.
///
/// - Parameters:
///     - cmpConfig: The ``CmpConfig`` object.
///     - viewController: `UIViewController` instance
/// - Returns: ``CMPConsentTool`` instance
- (instancetype)initWithCmpConfig:(CmpConfig *)cmpConfig
				   viewController:(UIViewController *)viewController;

/// Adds a close listener to receive notifications when the consent layer is being closed.
///
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)`
- (instancetype)withCloseListener:(void (^)(void))closeListener;

/// Adds an open listener to receive notifications when the consent layer is being opened.
///
/// - Parameter openListener: Callback which will be called when the consent layer is opened: The block should have the following signature: `void (^)(void)`.
- (instancetype)withOpenListener:(void (^)(void))openListener;

/// Adds an error listener to receive notifications when an error occurred
///
/// - Parameters:
///     - errorListener: Callback to add action if an error occurred. The block should have the following signature: `void (^)(CmpErrorType, NSString *)`
- (instancetype)withErrorListener:(void (^)(CmpErrorType, NSString *))errorListener;

/// Adds an custom open callback
///
/// - Parameters:
///     - listener: listener callback
- (instancetype)withCustomOpenListener:(void (^)(CMPSettings *))listener __attribute__((deprecated("Use -openListener, -closeListener instead. This method will be removed in future versions.")));

/// Adds a Cmp not opened callback to get notification when consent layer is not opening
/// Most common reason is that the user already gave a consent
///
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`. The block should have the following signature: `void (^)(void)`
- (instancetype)withOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Sets a callback to receive notifications when the user clicks a button to close the consent layer.
///
/// - Parameter onCmpButtonClickedCallback: Callback that will be invoked with the ``CmpButtonEvent`` indicating which button was pressed. The block should have the following signature: `void (^)(CmpButtonEvent)`
- (instancetype)withOnCmpButtonClickedCallback:(void (^)(CmpButtonEvent))onCmpButtonClickedCallback;

/// Initialize function will initialize the consent layer and checks automatically if the user needs a consent or not. This function will eventually open the consent layer and
/// will interact wit the Apple Tracking Transparency API to ask the user for Consent
///
/// - Returns: ``CMPConsentTool`` instance
- (instancetype)initialize;

#pragma mark - Placeholder functions

/// Creates a placeholder Instance which can be used to block dynamically content if a user did not give a specific consent
///
/// - Parameter frame: `CGRect` object to define the UIView
/// - Parameter placeholderParams: specified parameters set by ``CmpPlaceholderParams``
/// - Returns: ``CmpPlaceholderView`` instance
- (CmpPlaceholderView *)createPlaceholder:(CGRect)frame :(CmpPlaceholderParams *)placeholderParams __attribute__((deprecated("Use -enableVendorList, -disableVendorList instead. This method will be removed in future versions.")));

#pragma mark - API functions

/// opens consent layer
- (void)openCmpConsentToolView;

/// Opens the CMP consent layer view
///
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)` close listener callback
- (void)openCmpConsentToolView:(void (^)(void))closeListener __attribute__((deprecated("Use `-openCmpConsentToolView` instead. This method will be removed in future versions.The closelistener should be already declared on instantiation")));

/// Get vendor ids comma separated
///
/// - Returns: The Vendors `String`, that was set by consentmanager
- (NSString *)getVendorsString;

/// Get purpose ids comma separated
///
/// - Returns: The Purposes `String`, that was set by consentmanager
- (NSString *)getPurposesString;

/// Get US Privacy String
///
/// - Returns: `String` The US Privacy String, that was set by consentmanager
- (NSString *)getUSPrivacyString;

/// Retrieves the Google Advertising ID (`addtlConsent`) string that was set by the consent manager.
/// -
/// - Returns: The Google Advertising ID (`addtlConsent`) string.
- (NSString *)getGoogleACString;

/// Checks if the vendor ID is enabled based on the user consent.
/// 
/// - Parameters:
///     - vendorId: vendor id
///     - isIABVendor: if vendor id is an IAB vendor. (deprecated: The flag is not needed anymore)
/// - Returns: TRUE if the user has given consent to the specified vendor, FALSE otherwise.
- (BOOL)hasVendorConsent:(NSString *)vendorId vendorIsV1orV2:(BOOL)isIABVendor __attribute__((deprecated("Use -hasVendorConsent instead. This method will be removed in future versions.")));

/// Checks if the vendor ID is enabled based on the user consent.
///
/// - Parameters:
///     - vendorId: vendor id
/// - Returns: TRUE if the user has given consent to the specified vendor, FALSE otherwise.
- (BOOL)hasVendorConsent:(NSString *)vendorId;

/// Checks if the purpose ID is enabled based on the user consent.
///
/// - Parameters:
///     - purposeId: purpose id
///     - isIABVendor: is an IAB vendor. (deprecated: The flag is not needed anymore)
/// - Returns: TRUE if the user has given consent to the specified vendor, FALSE otherwise.
- (BOOL)hasPurposeConsent:(NSString *)purposeId purposeIsV1orV2:(BOOL)isIABPurpose __attribute__((deprecated("Use -hasVendorConsent instead. This method will be removed in future versions.")));

/// Checks if the purpose ID is enabled based on the user consent.
///
/// - Parameters:
///     - purposeId: purpose id
/// - Returns: TRUE if the user has given consent to the specified vendor, FALSE otherwise.
- (BOOL)hasPurposeConsent:(NSString *)purposeId;

/// Checks if the user gave a consent. The consent layer can have the option to just close the layer by. In this case the user does not gave a consent.
/// The function does not determine if the consent layer was shown or not.
///
/// - Returns: TRUE if the user gave a consent.
- (BOOL)hasConsent;

/// Checks if the vendor ID is enabled based on the purpose
///
/// - Parameters:
///     - purposeId: purpose id
///     - vendorId: vendor id
/// - Returns: TRUE if the user has given consent to the specified vendor for the purpose, FALSE otherwise.
- (BOOL)hasPurposeConsent:(int)purposeId forVendor:(int)vendorId;

/// Checks with the Consentmanager Network if the consent layer needs to be open. On positive notification by the server the consent layer will show
- (void)checkAndOpenConsentLayer;

/// imports the CmpData String which is used by the Cmp SDK
///
/// - Parameters:
///     - cmpData: Cmp data String base64 encoded
/// - Use `exportCmpString`
/// - Returns: Imports the given Cmp String
- (BOOL)importCmpString:(NSString *)cmpData;

/// Exports the CmpData String which can be imported by ``importCmpString:cmpData``
///
///  - Use `importCmpString` to import the exported String
/// - Returns: The CmpData String base64 encoded
+ (NSString *)exportCmpString;

/// Checks if the consent layer was called today
///
/// - Returns: TRUE if the CMPConsent Manager Server was requested today, otherwise FALSE
- (BOOL)calledThisDay;

/// Checks if the user needs acceptance
///
/// - Returns:TRUE if the user needs to give a consent.
- (BOOL)needsAcceptance;

/// Resets all data set by the ``CMPConsentTool``
+ (void)reset;

/// Sets the errorlistener callback
///
/// - Parameter errorListener: Callback to add action if an error occurred. The block should have the following signature: `void (^)(CmpErrorType, NSString *)`
/// - Returns: ``CMPConsentTool`` instance
- (id)errorListener:(void (^)(CmpErrorType, NSString *))errorListener;

/// Rejects the consent layer and behaves the same when the user `did not accept` the consent
///
/// - Parameter onFinish: Callback for handling consent received event. it will be called when consent is received.
- (void)rejectAll:(void (^)(void))onFinish;

/// Checks with the Consentmanager server, if the user needs to give a consent and the consent layer has to be opened
///
/// - Parameter onCmpLayerOpen: callback when the consent layer needs to be open
- (void)check:(void (^)(void))onCmpLayerOpen;

/// Checks with the Consentmanager server, if the user needs to give a consent and the consent layer has to be opened
///
/// - Parameter onCmpLayerOpen: Callback when the consent layer needs to be open. The block should have the following signature: `void (^)(CmpErrorType, NSString *)`
/// - Parameter isCached: BOOL flag when TRUE, the request will be cached and the response will be saved
- (void)check:(void (^)(void))onCmpLayerOpen isCached:(BOOL)isCached;

/// Accepts the consent layer and behaves the same when the user `did accepts` the consent
///
/// - Parameter onFinish: Callback for handling consent received event. it will be called when consent is received and processed.
- (void)acceptAll:(void (^)(void))onFinish;

/// Enables a list of vendors and updates the given consent
///
/// - Parameter vendors: List of vendor ids to enable.
- (void)enableVendorList:(NSArray *)vendors;

/// Enables a list of vendors and updates the given consent
///
/// - Parameters:
///     - vendors: List of vendor ids to enable.
///     - onFinish: Callback for handling consent received event. it will be called when consent is received and processed.
- (void)enableVendorList:(NSArray *)vendors onFinish:(void (^)(void))onFinish;

/// Disables a list of vendors and updates the given consent
///
/// - Parameter vendors  List of vendor ids to disable.
- (void)disableVendorList:(NSArray *)vendors;

/// Disables a list of vendors and updates the given consent
///
/// - Parameters:
///     - vendors: List of vendor ids to disable.
///     - onFinish: Callback for handling consent received event. it will be called when consent is received and processed.
- (void)disableVendorList:(NSArray *)vendors onFinish:(void (^)(void))onFinish;

/// Enables a list of purposes and updates the given consent
///
/// - Parameter purposes: List of purpose ids to enable.
- (void)enablePurposeList:(NSArray *)purposes;

///  Enables a list of purposes and updates the given consent
///
/// - Parameter purposes: List of purpose ids to enable.
/// - Parameter onFinish: Callback for handling consent received event. it will be called when consent is received and processed.
- (void)enablePurposeList:(NSArray *)purposes onFinish:(void (^)(void))onFinish;

/// Disables a list of purposes and updates the given consent
///
/// - Parameter purposes: List of purpose ids to enable.
- (void)disablePurposeList:(NSArray *)purposes;

/// Disables a list of purposes and updates the given consent
///
/// - Parameter purposes: List of purpose ids to enable.
/// - Parameter onFinish: Callback for handling consent received event. it will be called when consent is received and processed.
- (void)disablePurposeList:(NSArray *)purposes onFinish:(void (^)(void))onFinish;

/// Gets a list of the enabled `purpose` IDs
///
/// - Returns: `List` of enabled `purpose` IDs
- (NSArray *)getEnabledPurposeList;

/// Gets a comma separated String of the enabled `purpose` IDs
///
/// - Returns: `String` of enabled `purpose` IDs
- (NSString *)getEnabledPurposes;

/// Gets a list of the enabled `vendor` IDs
///
/// - Returns: `List` of enabled `vendor` IDs
- (NSArray *)getEnabledVendorList;

/// Gets a comma separated String of the enabled `vendor` IDs
///
/// - Returns: `String` of enabled `vendor` IDs
- (NSString *)getEnabledVendors;

/// Gets a list of the disabled `vendor` IDs
///
/// - Returns: `List` of disabled `vendor` IDs
- (NSArray *)getDisabledVendorList;

/// Gets a comma separated String of the disabled `vendor` IDs
///
/// - Returns: `String` of disabled `vendor` IDs
- (NSString *)getDisabledVendors;

/// Gets a list of the disabled `purpose` IDs
///
/// - Returns: `List` of disabled `purpose` IDs
- (NSArray *)getDisabledPurposeList;

/// Gets a comma separated String of the disabled `purpose` IDs
///
/// - Returns: `String` of disabled `purpose` IDs
- (NSString *)getDisabledPurposes;

/// Retrieves a list of all `purpose` IDs for the given Cmp.
///
/// - Returns: A `List` containing all `purpose` IDs.
- (NSArray *)getAllPurposesList;

/// Retrieves a list of all `purpose` IDs for the given Cmp.
///
/// - Returns: A `List` containing all `purpose` IDs.
- (NSString *)getAllPurposes;

/// Retrieves a list of all `vendor` IDs for the given Cmp.
///
/// - Returns: A `List` containing all `purpose` IDs.
- (NSArray *)getAllVendorList;

/// Retrieves a list of all `vendor` IDs for the given Cmp.
///
/// - Returns: A `List` containing all `vendor` IDs.
- (NSString *)getAllVendors;

/// Get consent String
///
/// - Returns: consent String
- (NSString *)getConsentString;

@end
