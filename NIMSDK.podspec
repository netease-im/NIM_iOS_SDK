Pod::Spec.new do |s|
 s.name = "NIMSDK"
 s.version = "3.2.0.1"
 s.summary = "Netease IM SDK"
 s.homepage = "http://netease.im"
 s.license = { :"type" => "Copyright", :"text" => " Copyright 2016 Netease "}
 s.authors = "Netease IM Team"
 s.source = { :git => "https://github.com/netease-im/NIM_iOS_SDK.git", :tag => "#{s.version}"}
 s.platform = :ios, '7.0'
 s.source_files = "**/ExportHeaders/**/*.h"
 s.frameworks = 'SystemConfiguration', 'AVFoundation', 'CoreTelephony', 'AudioToolbox', 'CoreMedia' , 'VideoToolbox'
 s.libraries = 'sqlite3.0', 'z', 'c++'

 s.subspec 'WithSSL' do |sp|
   sp.vendored_libraries = 'NIMSDK/libNIMSDK.a',
                           'NIMAVChat/libNIMAVChat.a',
                           'NIMAVChat/Libs/*.a',
                           'NIMSDK/Libs/libaacplus.a',
                           'NIMSDK/Libs/libcrypto.a',
                           'NIMSDK/Libs/libevent.a',
                           'NIMSDK/Libs/libssl.a'
 end

 s.subspec 'WithoutSSL' do |sp|
   sp.vendored_libraries = 'NIMSDK/libNIMSDK.a',
                           'NIMAVChat/libNIMAVChat.a',
                           'NIMAVChat/Libs/*.a',
                           'NIMSDK/Libs/libaacplus.a',
                         # 'NIMSDK/Libs/libcrypto.a',
                           'NIMSDK/Libs/libevent.a'
                         # 'NIMSDK/Libs/libssl.a'
 end

 # 默认不引入 libcrypto.a libssl.a，若有需要 pod 'NIMSDK/WithoutSSL'
 s.default_subspec = 'WithSSL'

end
