# Changelog

All notable changes to this project will be documented in this file.
### Version 1.99.1 (Released on 2023-12-16)

### Added
- 

### Fixed

### Refactored 
- Preparation release 2.0.0

### Version 1.7.3 (Released on 2023-10-03)

### Added
- Feature & Stability Improvements: New enhancements added to the system.
- Retry Logic: New retry mechanism introduced for better reliability.
  
### Refactor
- Codebase: Significant refactoring done for improved code stability.
- ViewController: Operations focused on refactoring the ViewController and streamlining debug logs.
### Fixes
- Deprecated Class Removal: An outdated class that was no longer in use has been removed.
- Cleanup: General tidying up of the codebase.

### Version 1.7.2 (Released on 2023-08-09)

### Refactor

- CmpConfig optimized

### Version 1.7.1 (Released on 2023-07-04)

### Fixes

- Serialization fix for NSString 

### Version 1.7.0 (Released on 2023-06-28)

### Refactor

- Refactoring Cmp consent process

### Version 1.6.4 (Released on 2023-05-24)

### Added
- updateVendor Parameter to updateVendors in disable/enable PurposeList API

### Refactor
- Documentation updates

### Fixes
- disablePurposeList and enablePurposeList fix
- getDisableVendors and purpose fix
- close Listener now executed correctly

### Version 1.6.3 (Released on 2023-05-14)

### Added
- Check API to requests server if consent layer needs to be open.
- Adding enable and disable vendor and purpose with feedback callback
- Check API caching feature
- Adding design ID parameter to set consent design

### Refactor
- Remove Webview after disappear
- Adding V4 URL for old Cmp Repository

### Fixes
- disableVendorList fix

### Version 1.6.2 (Released on 2023-04-21)

### Added
- Check API to requests server if consent layer needs to be open.

### Fixes
- Bug regarding to fetch the Vendor and Purpose List

### Version 1.6.1 (Released on 2023-04-12)

### Refactor
- Added old constructor API to CMPConsentTool

#### Added
- Feature new codeIds.
- Cmp Error Types on error callback.
- Cmp Button Event callbacks. Callback gives information about the user clicked button
#### Refactor
- Changed constructor calls. Chainable callbacks and removed autoupdate
- Updated signature.
- Synchronized API function naming.
- Refactored signature of API functions, changed process of read write consent.
- Refactored service class to singleton instance with listener properties.
- Refactored internal naming and refactored backend consent process.
- Changed signature of API functions getAgreed becomes getEnabled.

### Version 1.6.0 (Released on 2023-03-17)

#### Added
- Feature new codeIds.
- Cmp Error Types on error callback.
- Cmp Button Event callbacks. Callback gives information about the user clicked button
#### Refactor
- Changed constructor calls. Chainable callbacks and removed autoupdate
- Updated signature.
- Synchronized API function naming.
- Refactored signature of API functions, changed process of read write consent.
- Refactored service class to singleton instance with listener properties.
- Refactored internal naming and refactored backend consent process.
- Changed signature of API functions getAgreed becomes getEnabled.

### Version 1.5.2 (Released on 2023-02-07)

#### Fixes
- Bug fixes

### Version 1.5.1 (Released on 2023-02-05)

#### Features
- Added get list of disabled purposes and vendors
- Disabled purposes and vendors
- Changed vendorstring
- Added enable/disable vendor and purposes

### Version 1.5.0 (Released on 2023-01-21)

#### Refactor
- Cleanup
- Removed logs
- Logs
- Refactored API and added interface. Cleaned endpoints and marked specific endpoints as deprecated

#### Features
- Changed att
- getAgreed and getAll api

### Version 1.3.93 (Released on 2023-01-05)

#### Features
- Vendor and purpose api
- hasConsent API

#### Refactor
- Timeout and error listener

### Version 1.3.92 (Released on 2023-01-04)

#### Refactor
- Language update

### Version 1.3.91 (Released on 2023-01-04)

#### Refactor
- Version
- Timeout and error listener

### Version 1.3.9 (Released on 2023-01-03)

#### Refactor
- Timeout and common error
- Synchronize error listener

### Version 1.3.8 (Released on 2022-12-21)

#### Refactor
- Removed indicator view

### Version 1.3.7 (Released on 2022-12-13)

#### Features
- Podspec
- hasConsent API

### Version 1.3.6 (Released on 2022-12-10)

#### Features
- ModalTransitionStyle, openListener Bug, rejectAll feature

### Version 1.3.5 (Released on 2022-11-23)

#### Features
- Customlayout and skiptocustomize page

### Version 1.3.4 (Released on 2022-10-26)

#### Features
- Custom UI color

### Version 1.3.3 (Released on 2022-10-24)

#### Fixes
- Needs acceptance fix

### Version 1.3.2 (Released on 2022-10-21)

#### Refactor
- Changed signature to CmpSdk
- Update close and not close listener

### Version 1.3.1 (Released on 2022-05-05)

#### Refactor
- Added constructor for backend verification option

### Version 1.2.9 (Released on 2022-03-22)
#### Fixed
- User default parsing for IABTCF key values

### Version 1.2.8 (Released on 2022-03-15)
#### Refactored
- Stability improvements for CMP Communication of ConsentLayer
- Reliability of network requests

### Version 1.2.7 (Released on 2022-02-07)
#### Fixed
- ATT Status for consentlayer settings fixed:

### Version 1.2.6 (Released on 2022-01-03)
#### Added
- log verbose level

#### Fixed
- Additional process flow control

### Version 1.2.3 (Released on 2021-12-09)
#### Refactored
- basic improvements and project cleanup

### Version 1.2.2 (Released on 2021-12-09)
#### Fixed
- decode String bug

#### Refactored
- Consentlayer Event callback

### Version 1.2.1 (Released on 2021-12-02)
#### Added
- Timeout for specific events

### Version 1.2.0 (Released on 2021-11-30)
#### Added
- Placeholder feature
- ATT Support

#### Changed
- Consentlayer event processing
- API queries

#### Refactored
- Restructure Project
- Improved performance of consentlayer
- Preparing for new Interface Structure

### Version 1.1.1 (Released on 2021-09-05)
#### Fixed
- bug fix for hasVendor method

### Version 1.1.0 (Released on 2021-08-17)
#### Added
- added callback event when cmp view will not be opened

#### Fixed
- deactivated dismissing the cmp modal
- handle consent logic with non-EU traffic

#### Refactored
- changed url gnerator logic

### Version 1.0.3 (Released on 2021-06-17)
#### Fixed
- fixed misbehahaviour of external link calls within the cmp view.

### Version 1.0.2 (Released on 2021-06-14)
#### Fixed
- minor problems with xcframework version

### Version 1.0.0 (Released on 2021-06-11)
#### Added
- added CHANGELOG to development lifecycle

#### Changed
- Changed internal class names regarding to naming conflicts

#### Fixed
- Fixed unused element Warning caused by Parser
- Fixed Delegates association warning of ConsentController

### Version 0.1.5 (Released on 2021-03-22)
#### Refactored
- refactored minor parts of the sdk for better maintenance

### Version 0.1.1 (Released on 2021-03-21)
#### Added
- additional optional parameter to CmpConsentTool to pass idfa String

### Version 0.1.0 (Released on 2021-03-21)
#### Added
- added xc framework integration

#### Fixed
- fixed error handling on invalid json data

### Version 0.0.1 (Released on 2021-02-28)
#### Added
- pod example project fo pod try command

### Version 0.0.1 (Released on 2021-02-27)
#### Added
- Providing integration through cocoapod


