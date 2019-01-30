
Pod::Spec.new do |s|

  s.authors      = "Turkcell",
  s.name         = "PaycellSDK"
  s.summary      = "Paycell payment SDK"
  s.version      = "0.9.8"
  s.homepage     = "http://www.paycell.com.tr"
  s.license      = { :type => 'Apache 2.0', :file => 'LICENSE' }

  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/Turkcell/PaycellSDK-iOS", :tag => "release/v#{s.version}"}

  # ――― Source Code ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #

  s.source_files        = "Frameworks/PaycellSDK.framework/Headers/*.h"
  s.public_header_files = "Frameworks/PaycellSDK.framework/Headers/*.h"
  s.vendored_frameworks = "Frameworks/PaycellSDK.framework"
  s.frameworks          = "UIKit"


end
