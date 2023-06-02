Pod::Spec.new do |spec|

  spec.name         = "CmpSdk"
  spec.version      = "1.6.4"
  spec.summary      = "Provides functionality to inform the user about data protection and collect consent from the user."
  spec.description  = <<-DESC
          The ConsentManager SDK for iOS apps implements and provides functionality to inform the user about data protection and ask and collect consent from the user.
        It enables app-developers to easily integrate the ConsentManager service into their app.
                   DESC

  spec.homepage     = "https://github.com/iubenda/cm-sdk-xcframework"
  spec.license      = { :type => "MIT", :file => "LICENSE" }

  spec.author             = { "Skander Ben Abdelmalak" => "skander@consentmanager.net" }

  spec.platform     = :ios, "11.0"
  spec.source       = { :git => "https://github.com/iubenda/cm-sdk-xcframework.git", :tag => "#{spec.version}" }
  spec.vendored_frameworks = "CmpSdk.xcframework"
  spec.platform = :ios
  spec.swift_version = "4.2"
  spec.ios.deployment_target  = '11.0'

end
