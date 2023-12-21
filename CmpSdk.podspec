#
#  Be sure to run `pod spec lint cm-sdk-xcframework.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  spec.name         = "CmpSdk"
  spec.version      = "1.99.2"
  spec.summary      = "Provides functionality to inform the user about data protection and collect consent from the user."
  spec.description  = <<-DESC
          The ConsentManager SDK for iOS apps implements and provides functionality to inform the user about data protection and ask and collect consent from the user.
        It enables app-developers to easily integrate the ConsentManager service into their app.
                   DESC

  spec.homepage     = "https://github.com/iubenda/cm-sdk-xcframework"
  spec.license      = { :type => "MIT", :file => "LICENSE" }

  spec.author             = { "Skander Ben Abdelmalak" => "skander@consentmanager.net" }

  spec.platform     = :ios, "12.0"
  spec.source       = { :git => "https://github.com/iubenda/cm-sdk-xcframework.git", :tag => "#{spec.version}" }
  spec.vendored_frameworks = "CmpSdk.xcframework"
  spec.platform = :ios
  spec.ios.deployment_target  = '12.0'

end
