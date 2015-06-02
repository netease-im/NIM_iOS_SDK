#
# Be sure to run `pod lib lint NIMSDK.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "NIMSDK"
  s.version          = "1.1.4"
  s.summary          = "Netease IM SDK"
  s.description      = <<-DESC
                       Netease IM iOS SDK
                       DESC
  s.homepage         = "http://netease.im"
  s.license          = { :"type" => "Copyright",
                         :"text" => " Copyright 2015 Netease \n"}
  s.authors           = "Netease IM Team"
  s.source           = { :git => "https://github.com/nimdevelopers/NIM_iOS_SDK.git",
                         :tag => "#{s.version}"}

  s.platform     = :ios, '6.0'

  s.source_files = "**/ExportHeaders/**/*.h"
  s.vendored_libraries = "**/lib#{s.name}.a"
  s.frameworks = 'SystemConfiguration', 'AVFoundation', 'CoreTelephony'
  s.libraries = 'sqlite3.0', 'z', 'stdc++.6.0.9'

end
