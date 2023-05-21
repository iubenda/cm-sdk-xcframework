# Consentmanager #

The ConsentManager Library for iOS apps implements and provides functionality to inform the user about data protection
and ask and collect consent from the user. It enables app developers to integrate the ConsentManager service into their
app without difficulty.

## Supported Standards ##

The ConsentManager GDPR/CCPA Library for iOS supports the following industry standards:

*IAB TCF v1
*IAB TCF v2
*IAB USPrivacy v1
*ConsentManager custom vendors/purposes
*Google Additional Consent Mode (Google AC String)

## Overview ##

* How it works
* Installation
    - Add Library with Cocoapod
    - Add Library as downloadable Framework
    - Initiate ConsentTool
* Using the Library

## How it works ##

First of all, the first step is to integrate the SDK into the app and configure the SDK settings. Once the SDK is
integrated into an app, the SDK will provide functions for the app developer to retrieve consent data. Then, as soon as
the app starts, the SDK will automatically retrieve information from the ConsentManager servers in order to prepare the
SDK for its usage.

It is recommended that the app creates a sample of a class CMPConsentTool when launched. After this is generated, the
SDK will automatically show the consent screen if necessary. When the app wants to process personal data, it should "
ask" the SDK whether consent is given for the specific purpose and vendor.

## Installation ##

### Add Library with Cocoapod ###

You can install the ConsentManager by adding `consentmanager` to your Podfile as explained in the example below:

```
target 'YourProject' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks!
  pod 'consentmanager'

  target 'YourProjectTests' do
    inherit! :search_paths
     # Pods for testing
  end
...
end
```

*Run `pod install` in your project directory to install the ConsentManager.
*Open the *.xcworkspace and build.

After you have followed all the steps, your dependency should be installed, and you can proceed and use it in your
project.

### Add Library as downloadable Framework (SDK) ###

If you do not use Cocoapod please use our SDK library as a downloadable package by clicking the following
link: https://help.consentmanager.net/books/cmp/page/consentmanager-gdprccpa-sdk-for-ios

Nevertheless, we strongly recommend installing and using the library with Cocoapod, because otherwise, it is harder to
maintain for the user as well as for the developer. This way, updates need to be integrated manually, and there are some
version control issues. Therefore, we are planning to stop the active service for this library.

### Initiate ConsentTool ###

With the app-start (usually your viewDidAppear function) you must create an instance of class CMPConsentTool. This will
automatically fetch the necessary data from our server and determine if the consent screen needs to be shown or not. If
so, the SDK will automatically show the consent screen at this point, collect the data and provide the data to the app.
The instance can then be used in order to get consent details from the SDK in order to use it in the app.

To initiate the ConsentTool, first import the library with ```import consentmanager```. Now you should be able to
instantiate the CMPConsentTool for example with the following init parameters:

```cmpConsentTool = CMPConsentTool.init("consentmanager.mgr.consensu.org", addId: "123456", addAppName: "my%20test%20app", addLanguage: "DE", add: self)```

## Using the Library ##

To check whether a vendor or purpose have consent, you can use these two methods:

```
if( cmpConsentTool!.hasPurposeConsent("52", purposeIsV1orV2: false)) {
   if((cmpConsentTool!.hasVendorConsent("52", vendorIsV1orV2: false))) {
      //do Something
   }
}
```

Both methods `hasPurposeConsent` and `hasVendorConsent` require two parameters:

* id - String of the vendor or purpose ID. Please note that vendor IDs can have different formats ("123", "s123" and "
  c123"), please double-check with Menu > Vendors and Menu > Purposes in your ConsentManager account.

* isIABVendor / isIABPurpose - If the vendor or purpose is a vendor/purpose that follows the IAB TCF standard, you will
  need to set a "correct", otherwise a "false".

--- 
**NOTE**

Remember: All vendors that do not belong to the IAB have ID's starting with "a" "s" or "c" (e.g. "s123"); vendors that belong to the IAB have ID's not starting with "a" "s" or "c".
---

### Re-opening the Consent Screen ###

In order to allow the user to change the choices, you can simply call openCmpConsentToolView():

```cmpConsentTool!.openView()```

### Passing Consent Information to other Sources ### 

In some cases, a native app might contain web views to display certain features like advertising or content. To transmit
the consent information from the SDK to the web view, please use the function:

```consentData = CMPStorageConsentManager.exportCMPData(this);```

```myWebView.loadURL("https://mywebsite.com/....#cmpimport=" + consentData);```