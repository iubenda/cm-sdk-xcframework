//
//  CmpManager.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 24.06.24.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <CmpSdk/CmpButtonEvent.h>
#import <CmpSdk/CmpConfig.h>
#import <CmpSdk/CmpErrorTypes.h>
#import <CmpSdk/CmpCallbackTypes.h>
#import <CmpSdk/CmpEventListenerTypes.h>
#define UIKitLocalizedString(key) [[NSBundle bundleWithIdentifier:@"com.apple.UIKit"] localizedStringForKey:key value:@"" table:nil]

typedef void (^CmpViewControllerConfigurationBlock)(UIViewController *viewController);
typedef void (^CmpUIViewConfigurationBlock)(UIView *view);

@class CmpLayerViewController;

/// CmpManager instance to interact with the Consentmanager Platform. You can open the Consent layer and manage the user consent
@interface CmpManager : NSObject

/// The singleton CmpManagerInstance
extern CmpManager *cmpManager;

/// The Config set to the CmpManager while initialisation
@property(nonatomic, retain) CmpConfig *cmpConfig;

/// Initializes a new instance of the class with the specified CMP domain, code ID, app name, language, and view controller.
///
/// - Parameters:
///     - domain: Cmp server domain
///     - codeId: Cmp ID
///     - appName: name of the app
///     - language: language for the consentlayer
///     - viewController: `UIViewController` instance
/// - Returns: ``CmpManager`` instance
- (instancetype)initWithDomain:(NSString *)domain
                        codeId:(NSString *)codeId
                       appName:(NSString *)appName
                      language:(NSString *)language;

///
/// Initializes a new instance of the class with the specified ``CmpConfig`` and view controller.
///
/// - Parameters:
///     - cmpConfig: The ``CmpConfig`` object.
///     - viewController: `UIViewController` instance
/// - Returns: ``CmpManager`` instance
- (instancetype)initWithCmpConfig:(CmpConfig *)cmpConfig;

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

/// Adds a Cmp not opened callback to get notification when consent layer is not opening
/// Most common reason is that the user already gave a consent
///
/// - Parameter onCMPNotOpenedListener: Callback which will be called when the consent layer is `not opened`. The block should have the following signature: `void (^)(void)`
- (instancetype)withOnCMPNotOpenedListener:(void (^)(void))onCMPNotOpenedListener;

/// Sets a callback to receive notifications when the user clicks a button to close the consent layer.
///
/// - Parameter onCmpButtonClickedCallback: Callback that will be invoked with the ``CmpButtonEvent`` indicating which button was pressed. The block should have the following signature: `void (^)(CmpButtonEvent)`
- (instancetype)withOnCmpButtonClickedCallback:(void (^)(CmpButtonEvent))onCmpButtonClickedCallback;

/// Adds configuration to the CmpViewController
/// - Parameter controllerConfigurationBlock: Configuration for custom ViewController behaviour and styles
- (instancetype)withCmpViewControllerConfigurationBlock:(CmpViewControllerConfigurationBlock)controllerConfigurationBlock;

/// Adds configuration to the Cmp UIView
/// - Parameter viewConfigurationBlock: Configuration for custom UIView styles
- (instancetype)withCmpViewConfigurationBlock:(CmpUIViewConfigurationBlock)viewConfigurationBlock;

- (instancetype)withUpdateGoogleConsent:(CmpGoogleAnalyticsListener)googleAnalyticsListener;

- (instancetype)withOnCmpLinkClickListener:(CmpLinkClickListener)linkClickListener;
/// Initialize function will initialize the consent layer and checks automatically if the user needs a consent or not. This function will eventually open the consent layer and
/// will interact wit the Apple Tracking Transparency API to ask the user for Consent
///
/// - Returns: ``CmpManager`` instance
- (instancetype)initialize;

#pragma mark - API functions

/// opens consent layer
- (void)openCmpManagerView __attribute__((deprecated("Use `-openConsentLayer` instead. This method will be removed in future versions.")));

- (void)openConsentLayer;

/// Opens the CMP consent layer view
///
/// - Parameter closeListener: Callback which will be called when the consent layer is closed: The block should have the following signature: `void (^)(void)` close listener callback
- (void)openCmpManagerView:(void (^)(void))closeListener __attribute__((deprecated("Use `-openConsentLayer` instead. This method will be removed in future versions.The closelistener should be already declared on instantiation")));

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

/// Retrieves the Google Advertising ID (`addtlConsent`) string that was set bwy the consent manager.
/// -
/// - Returns: The Google Advertising ID (`addtlConsent`) string.
- (NSString *)getGoogleACString;

- (BOOL)hasVendor:(NSString *)vendorId defaultReturn:(BOOL)defaultReturn;

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
///     - isIABVendor: if vendor id is an IAB vendor. (deprecated: The flag is not needed anymore)
/// - Returns: TRUE if the user has given consent to the specified vendor, FALSE otherwise.
- (BOOL)hasVendorConsent:(NSString *)vendorId __attribute__((deprecated("Use -hasVendorConsent instead. This method will be removed in future versions.")));

/// Checks if the vendor ID is enabled based on the user consent.
///
/// - Parameters:
///     - vendorId: vendor id
/// - Returns: TRUE if the user has given consent to the specified vendor, FALSE otherwise.
- (BOOL)hasVendor:(NSString *)vendorId;


- (BOOL)hasPurpose:(NSString *)purposeId defaultReturn:(BOOL)defaultReturn;
/// Checks if the purpose ID is enabled based on the user consent.
///
/// - Parameters:
///     - purposeId: purpose id
///     - isIABVendor: is an IAB vendor. (deprecated: The flag is not needed anymore)
/// - Returns: TRUE if the user has given consent to the specified vendor, FALSE otherwise.
- (BOOL)hasPurposeConsent:(NSString *)purposeId purposeIsV1orV2:(BOOL)isIABPurpose __attribute__((deprecated("Use -hasPurpose instead. This method will be removed in future versions.")));

/// Checks if the vendor ID is enabled based on the user consent.
///
/// - Parameters:
///     - vendorId: vendor id
///     - isIABVendor: if vendor id is an IAB vendor. (deprecated: The flag is not needed anymore)
/// - Returns: TRUE if the user has given consent to the specified vendor, FALSE otherwise.
- (BOOL)hasPurposeConsent:(NSString *)purposeId __attribute__((deprecated("Use -hasPurpose instead. This method will be removed in future versions.")));

/// Checks if the purpose ID is enabled based on the user consent.
///
/// - Parameters:
///     - purposeId: purpose id
/// - Returns: TRUE if the user has given consent to the specified vendor, FALSE otherwise.
- (BOOL)hasPurpose:(NSString *)purposeId;

/// Checks if the user gave a consent. The consent layer can have the option to just close the layer by. In this case the user does not gave a consent.
/// The function does not determine if the consent layer was shown or not.
///
/// - Returns: TRUE if the user gave a consent.
- (BOOL)hasConsent;

/// Checks with the Consentmanager Network if the consent layer needs to be open. On positive notification by the server the consent layer will show
- (void)checkAndOpenConsentLayer __attribute__((deprecated("Use -openConsentLayerOnCheck instead. This method will be removed in future versions.")));

/// Checks with the Consentmanager Network if the consent layer needs to be open. On positive notification by the server the consent layer will show
- (void)openConsentLayerOnCheck;

/// imports the CmpData String which is used by the Cmp SDK
///
/// - Parameters:
///     - cmpData: Cmp data String base64 encoded
///     - onFinish: Callback for handling consent received event. it will be called when consent is received and processed.
/// - Use `exportCmpString`
/// - Returns: Imports the given Cmp String
- (void)importCmpString:(NSString *)cmpString completion:(CmpImportCompletionHandler)completionHandler;

/// Exports the CmpData String which can be imported by ``importCmpString:cmpData``
///
///  - Use `importCmpString` to import the exported String
/// - Returns: The CmpData String base64 encoded
+ (NSString *)exportCmpString;

/// Checks if the consent layer was called today
///
/// - Returns: TRUE if the CMPConsent Manager Server was requested today, otherwise FALSE
- (BOOL)consentRequestedToday;

/// Checks if the user needs acceptance
///
/// - Returns:TRUE if the user needs to give a consent.
- (BOOL)isConsentRequired;

/// Resets all data set by the ``CmpManager``
+ (void)reset;


/// Adds event listeners to the CmpManager.
/// - Parameters:
///     - openListener: Callback which will be called when the consent layer is opened.
///     - closeListener: Callback which will be called when the consent layer is closed.
///     - cmpNotOpenedCallback: Callback which will be called when the consent layer is not opened.
///     - onErrorCallback: Callback to add action if an error occurred.
///     - onButtonClickedCallback: Callback that will be invoked with the CmpButtonEvent indicating which button was pressed.
- (instancetype)addEventListenersWithOpenListener:(CmpOpenListener)openListener
                                    closeListener:(CmpCloseListener)closeListener
                              cmpNotOpenedCallback:(CmpNotOpenedListener)cmpNotOpenedCallback
                                    onErrorCallback:(CmpErrorListener)onErrorCallback
                            onButtonClickedCallback:(CmpButtonClickedListener)onButtonClickedCallback
                          googleConsentModeListener:(CmpGoogleAnalyticsListener)googleConsentModeListener;


/// Rejects the consent layer and behaves the same when the user `did not accept` the consent
///
/// - Parameter onFinish: Callback for handling consent received event. it will be called when consent is received.
- (void)rejectAll:(void (^)(void))onFinish;

/// Checks with the Consentmanager server, if the user needs to give a consent and the consent layer has to be opened
///
/// - Parameter onCmpLayerOpen: callback when the consent layer needs to be open
/// - Parameter onCmpLayerNotOpen:callback when the consent layer don't need to be open
- (void)check:(void (^)(void))onCmpLayerOpen onCmpLayerNotOpen:(void (^)(void))onCmpLayerNotOpen __attribute__((deprecated("Use `-checkConsentIsRequired` instead. This method will be removed in future versions.")));

/// Checks with the Consentmanager server, if the user needs to give a consent and the consent layer has to be opened
///
/// - Parameter onCmpLayerOpen: Callback when the consent layer needs to be open. The block should have the following signature: `void (^)(CmpErrorType, NSString *)`
/// - Parameter isCached: BOOL flag when TRUE, the request will be cached and the response will be saved
/// - Parameter onCmpLayerNotOpen: Callback when the consent layer does not need to be open. The block should have the following signature: `void (^)(CmpErrorType, NSString *)`
- (void)check:(void (^)(void))onCmpLayerOpen isCached:(BOOL)isCached onCmpLayerNotOpen:(void (^)(void))onCmpLayerNotOpen __attribute__((deprecated("Use `-checkConsentIsRequired` instead. This method will be removed in future versions.")));


- (void)checkConsentIsRequired:(BOOL)isCached onUpdate:(void (^)(BOOL needsToOpen))onUpdate;


- (void)checkConsentIsRequired:(void (^)(BOOL needsToOpen))onUpdate;

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

/// Enables a list of purposes and updates the given consent
/// - Parameters:
///   - purposes: List of purpose ids to enable.
///   - onFinish: Callback for handling consent received event. it will be called when consent is received and processed.
///   - updateVendor: flag if true also enable corresponding vendors
- (void)enablePurposeList:(NSArray *)purposes onFinish:(void (^)(void))onFinish updateVendor:(BOOL)updateVendor;

/// Disables a list of purposes and updates the given consent
///
/// - Parameter purposes: List of purpose ids to enable.
- (void)disablePurposeList:(NSArray *)purposes;

/// Disables a list of purposes and updates the given consent
///
/// - Parameter purposes: List of purpose ids to enable.
/// - Parameter onFinish: Callback for handling consent received event. it will be called when consent is received and processed.
- (void)disablePurposeList:(NSArray *)purposes onFinish:(void (^)(void))onFinish;

/// Disable a list of purposes and updates the given consent
/// - Parameters:
///   - purposes: List of purpose ids to enable.
///   - onFinish: Callback for handling consent received event. it will be called when consent is received and processed.
///   - updateVendor: flag if true also enable corresponding vendors
- (void)disablePurposeList:(NSArray *)purposes onFinish:(void (^)(void))onFinish updateVendor:(BOOL)updateVendor;

/// Gets the regulation key
///
/// - Returns: `String` of regulation key
+ (NSString *)getRegulationKey;

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

- (NSDictionary<NSString *, NSString *> *)getGoogleConsentModeStatus;


// ATT Feature:
#pragma mark ATTracking Feature

///  Request ATTracking permission
/// - Parameter completion: Completion handler for custom business logic
- (void)requestATTPermissionWithCompletion:(void (^)(ATTrackingManagerAuthorizationStatus status))completion API_AVAILABLE(ios(14));

- (void)requestATTPermission API_AVAILABLE(ios(14));

/// Gets the last ATTracking request Date
- (NSDate *)getLastATTRequestDate;

- (instancetype)withOnCmpATTrackingStatusChangedCallback:(CmpATTrackingStatusChangedListener)onATTrackingStatusChanged  API_AVAILABLE(ios(14));

@end
